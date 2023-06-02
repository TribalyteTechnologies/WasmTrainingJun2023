# Threads example

This repository shows a simple example of using threads in WebAssembly applications.

In this example we will have a small C++ program where threads are used. It should be noted that in our C++ program we will not have to add anything related to WebAssembly, that is, we can work as if we were using only C++.

To run this example, first of all we have to generate the files associated to WebAssembly, the .wasm and the .js, and for this case the .worker.js also. To generate these files we can run make in our machine if we have Emscripten or by a docker image if we do not have Emscripten installed or we do not want to install it. Note that the test have been done with Emscripten version 3.1.36, both for the docker image, and for having it installed in the machine that we work.

To compile execute:

With Emscripten installed:

```shell
make compileExample
```

With Docker image:

```shell
make dockerCompileExample
```

or

With Emscripten installed:

```shell
make allExample
```

With Docker image:

```shell
make dockerAllExample
```

After this we will have the WebAssembly files to use in HTML.

Note that there is also the option to clean, to delete the compiled files, execute:

```shell
make cleanExample
```

When compiling, in addition to the known .js and .wasm, a .worker.js is generated. This file associated to the Javascript workers will also be necessary to deploy the web.

If the web associated to the .html is launched we will see an error associated to the "SharedArrayBuffer". This is one of the features that are disabled by default in browsers. That is why it is necessary to enable cross-origin isolation. We must also work with a website with SSL certificate, otherwise, even if we enable cross-origin isolation, we will not be able to work with threads.

In the presented example of threads, for the web part, Apache has been used. The steps to be followed to reproduce the example are set out below. Note that the following actions must be performed as superuser.

Install Apache if it is not already installed on your computer.

```shell
apt install apache2
```

Once we have Apache installed, copy the content related to the web page in the root folder associated with the Apache web server:

```shell
/var/www/html 
```

Note that we do not have to use the default root folder, we can asociate with the directory that we are working with. To do this we would have to edit the apache.conf file (usually located in /etc/apache2/conf) and modify the DocumentRoot attribute.

The next step is to activate the cross-origin isolation. To do this, two headers must be inserted in the server side. But before that, we must enable Apache modules "rewrite" and "headers":

```shell
a2enmod rewrite
a2enmod headers
```

The next step is to edit the server configuration file:
```shell
vi /etc/apache2/sites-enabled/000-default.conf
```

In it the following headers must be added:

```shell
Cross-Origin-Embedder-Policy: require-corp
Cross-Origin-Opener-Policy: same-origin
```

The configuration file could look like this:
```shell
<VirtualHost *:443>
        ServerAdmin webmaster@localhost
        DocumentRoot /var/www/html
        ErrorLog ${APACHE_LOG_DIR}/error.log
        CustomLog ${APACHE_LOG_DIR}/access.log combined
        Header set Cross-Origin-Embedder-Policy: require-corp
        Header set Cross-Origin-Opener-Policy: same-origin
</VirtualHost>

```

Next, restart the Apache server:
```shell
service apache2 restart
```

As mentioned above, in addition to enabling cross-origin isolation for the SharedArrayBuffer, to run the threads the web must run in a secure environment, that is our page must be HTTPS.

To enable HTTPS in Apache and run the presented example the following steps can be followed:

Enable the Apache SSL module:

```shell
a2enmod ssl
```

Edit the Apache configuration file.

```shell
vi /etc/apache2/apache2.conf
```

Add the following lines to the end of the file:

```shell
<Directory /var/www/html>
AllowOverride All
</Directory>
```

Create a private key and website certificate using OpenSSL:

```shell
mkdir /etc/apache2/certificate
cd /etc/apache2/certificate
openssl req -new -newkey rsa:4096 -x509 -sha256 -days 365 -nodes -out apache-certificate.crt -keyout apache.key
```

In the "Common Name" option we must enter the ip or url associated to the web to be deployed with Apache (the ip can be known with ifconfig).

```shell
Generating a RSA private key
............++++
.......................................................++++
writing new private key to 'apache.key'
-----
You are about to be asked to enter information that will be incorporated
into your certificate request.
What you are about to enter is what is called a Distinguished Name or a DN.
There are quite a few fields but you can leave some blank
For some fields there will be a default value,
If you enter '.', the field will be left blank.
-----
Country Name (2 letter code) [AU]:SP
State or Province Name (full name) [Some-State]:Madrid
Locality Name (eg, city) []:
Organization Name (eg, company) [Internet Widgits Pty Ltd]:WebAssembly
Organizational Unit Name (eg, section) []:
Common Name (e.g. server FQDN or YOUR name) []:192.168.1.78
Email Address []:

```

Then edit the Apache configuration file for the web site:

```shell
vi /etc/apache2/sites-enabled/000-default.conf
```

Add the following lines:

```shell
SSLEngine on
SSLCertificateFile /etc/apache2/certificate/apache-certificate.crt
SSLCertificateKeyFile /etc/apache2/certificate/apache.key
```

In addition we can redirect HTTP users to the HTTPS version. To do this add:

```shell
<VirtualHost *:80>
    RewriteEngine On
    RewriteCond %{HTTPS} !=on
    RewriteRule ^/?(.*) https://%{SERVER_NAME}/$1 [R=301,L]
</virtualhost>
```

Finally the configuration file would have a view like the following:

```shell
<VirtualHost *:80>
        RewriteEngine On
        RewriteCond %{HTTPS} !=on
        RewriteRule ^/?(.*) https://%{SERVER_NAME}/$1 [R=301,L]
</virtualhost>
<VirtualHost *:443>
        ServerAdmin webmaster@localhost
        DocumentRoot /var/www/html
        ErrorLog ${APACHE_LOG_DIR}/error.log
        CustomLog ${APACHE_LOG_DIR}/access.log combined
        Header set Cross-Origin-Embedder-Policy: require-corp
        Header set Cross-Origin-Opener-Policy: same-origin
        SSLEngine on
        SSLCertificateFile /etc/apache2/certificate/apache-certificate.crt
        SSLCertificateKeyFile /etc/apache2/certificate/apache.key
</VirtualHost>
```

Lastly, the Apache service must be restarted:

```shell
service apache2 restart
```

With all this done, we could go to the browser (in the tested case Google Chrome has been used) and see that in the browser console the traces associated to each thread are shown, verifying the operation and implementation of threads in WebAssembly.  
