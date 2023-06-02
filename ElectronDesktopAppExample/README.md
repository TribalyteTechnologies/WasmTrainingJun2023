# Electron App example

The current directory contains a simple example of how to create a desktop application based on the use of WebAssembly, starting from a C++ application. This will show how a web application that use WebAssembly can be transformed into a desktop application.

To carry out this example it will be necessary to use Electron.js that will allow us to pass the web application that uses WebAssembly to a desktop application.

Before starting, it should be noted that we are going to use three tools. These tools are Node.js, npm and rpm. In case we do not have any of them we can install them through the following commands:

```shell
sudo apt-get install nodejs
sudo apt-get install npm
sudo apt-get install rpm
```

This project has been executed under the following software versions:
- Node.js 16.19.1
- npm 8.19.13
- rpm 4.17.0

If we observe the structure of the project we can see the existence of a main directory and a directory called "web". The main directory contains the files "main.js", "package.json" and "package-lock.json", files necessary for the execution of Electron.js. On the other hand, the "web" directory contains the file "electornAppExample.html" associated to the web, as well as the file "electronAppExample.cpp" from which the WebAssembly file necessary for the web will be obtained.

To start, we will have to compile the file "electronExample.cpp" to obtain the associated .wasm and .js files. To generate these files we can run make in our machine if we have Emscripten or by a docker image if we do not have Emscripten installed or we do not want to install it. Note that the test have been done with Emscripten version 3.1.36, both for the docker image, and for having it installed in the machine that we work.

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

Note that there is also the option to clean, to delete the compiled files we can execute:

```shell
make cleanExample
```

Once we have the .js and .wasm files associated to WebAssembly the next step is to generate the application using Electron.js. To generate the application we can execute:

```shell
make exportApp
```

The above command will generate a directory named "out" with the binary application and the Linux installable of the application. However there is the possibility of doing the above step by step for this we can follow the following:

First step is to have the file "main.js" that will be the input file and the one that will define the application indicating that it has to load the web that contains the WebAssembly, besides other characteristics like the size of the window of the application, etc... This file comes already in the defined project and it is a file that we have to create us indicating each data.

In addition to this file we will need to have a package.json. This file also comes by default in the directory.

Having the last files, next we have to install the electron package in the devDependencies of our application. For this execute

```shell
npm i
```

Next we have to import our project with a handy conversion script.

```shell
npx electron-forge import
```

Finally, to create the distributable of the project that will contain the binary and the executable of the application among others, you will have to execute the electorn-forge make command:

```shell
npm run electronForgeMake
```

With the last command a directory named "out" will be created containing the application binary and its installable. If you access "out/electronappexample-linux-x64" you will see a binary named like the name defined in the package.json. If you open it, the application will open. 

On the other hand, the installable is also generated, in the case tested for Linux. If you access the directory "out/make/deb/x64" you can see a ".deb" file associated with the application, application that can be installed for example from the following command:

```shell
sudo dpkg -i electron_1.0.0_amd64.deb 
```