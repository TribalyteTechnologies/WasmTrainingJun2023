# Boost Example

This is a simple example that shows the use of Boost with WebAssembly. This example use the boost library Algorithm to separate a declared string.

To run this example, first of all, we have to generate the files associated to WebAssembly, the .wasm and the .js. To generate these files we can run make in our machine if we have Emscripten or by a Docker image if we do not have Emscripten installed or we do not want to install it. Note that the test have been done with Emscripten version 3.1.36, both for the docker image, and for having it installed in the machine that we work and on the other hand we tested with Boost library version 1.81.0.

To compile execute:

With Emscripten installed:

```shell
make compileBoostExample
```

With Docker image:

```shell
make dockerCompileBoostExample
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
http://localhost:2345/boostAlgorithmExample.html

When we end to work with the web we must stop the Apache image, so it can be used in the future. We can do it by:

```shell
make stop
```