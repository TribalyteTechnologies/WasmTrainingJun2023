# Hello World! Example WebAssembly and C++

This is a simple example of how to use WebAssembly to integrate a C++ program in an HTML web page.

To run this example, first of all, we have to generate the files associated to WebAssembly, the .wasm and the .js. To generate these files we can run make in our machine if we have Emscripten or by a docker image if we do not have Emscripten installed or we do not want to install it. Note that the test have been done with Emscripten version 3.1.36, both for the docker image, and for having it installed in the machine that we work.

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

Note that there is also the option to clean, to delete the compiled files execute:

```shell
make cleanExample
```

The last step is to exceute the html to throught the web. For this we can do it with an image of Apache to server the web.

To do it we can execute the next command:

```shell
make run
```

The last command, run the docker image and serve the web in localhost, so we can see the web by open the browser and access to:
http://localhost:2345/helloWorldWebassembly.html

When we end to work with the web we must stop the Apache image, so it can be used in the future. We can do it by:

```shell
make stop
```