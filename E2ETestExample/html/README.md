# E2E example

### This is a simple example of how to use WebAssembly to integrate a C++ program in an HTML web page.

The following example presents some of the functionality that embind provides to use with WebAssembly certain C++ features, which will be called from the HTML via Javascript.

This example presents a simple form for send messages to Tribalyte. In it the person will enter their personal data, the message and the department they are going to. These data are sent through a function to the C++ program where it will be printed on the console. In addition, from C++ the Javascript "alert" function is called to generate an alert if the message has been sent correctly or if there has been an error.

In this program the associated properties are used to use through WebAssembly classes, structures, enumerations and exceptions that have been created in C++.

To generate these files we can run make in our machine if we have Emscripten or by a Docker image if we do not have Emscripten installed or we do not want to install it. Note that the test have been done with Emscripten version 3.1.36, both for the docker image, and for having it installed in the machine that we work.

To compile excecute:

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

Note that there is also the option to clean, to delete the compiled files:

```shell
make cleanExample
```

To end, execute the web through LiveServer extension in VSCode for example, which will create a local mini server from Visual Studio to check the web application.

Once the Web is launched, open the browser console, enter the data and exceute to see the messages generate.