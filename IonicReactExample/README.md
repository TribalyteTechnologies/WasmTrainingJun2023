# Ionic React Example

This is a simple example where we are going to use WebAssembly in a Ionic React application.

In this example we will see how starting from an Ionic React application, we will be able to call a C++ function, thanks to the use of WebAssembly and Embind. The presented example presents two contact forms, where a person will enter their data and click a button to send it. Internally what will be done is that a C++ function will be called and the wrote data will be passed to it. The C++ function will generate a message from the received data, so that later from the web application the message generated in the C++ function will be shown.

We have the possibility to compile, build the application and run it with a single command. To do this we can run:

```shell
make runAll
```

However, we may want to execute each action individually. To run this example step by step, first of all, we have to generate the files associated to WebAssembly, the .wasm and the .js. To generate these files we can run make in our machine if we have Emscripten or by a docker image if we do not have Emscripten installed or we do not want to install it. Note that the test have been done with Emscripten version 3.1.36, both for the docker image, and for having it installed in the machine that we work.

To compile and obtain the WebAssembly files we can run:

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

Note that there is also the option to clean, to delete the compiled files execute:

```shell
make cleanExample
```

The last step is to execute the Ionic React application. To do it we can execute the next command:

```shell
make runIonicApp
```

We can also build the application. For this we can run:

```shell
make buildIonicApp
```