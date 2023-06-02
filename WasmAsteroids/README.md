# Asteroids 

This is a WebAssembly port of an Asteroids game written in C

[The source code can be found here: ](https://github.com/robertaboukhalil/wasm-asteroids.git):

Clone the remote repository to this directory
```shell
git clone https://github.com/robertaboukhalil/wasm-asteroids.git
```


## Build

if you want to compile this example with the Makefile from our repository

With Emscripten installed:

```shell
make compileExample
```

With Docker image:

```shell
make dockerCompileExample
```

Note that there is also the option to clean, to delete the compiled files:

```shell
make cleanExample
```

The last step is to exceute the html to throught the web. For this we can do it with an image of Apache to server the web.

To do it we can execute the next command:

```shell
make run
```

The last command, run the docker image and serve the web in localhost, so we can see the web by open the browser and access to:
http://localhost:2345/

When we end to work with the web we must stop the Apache image, so it can be used in the future. We can do it by:

```shell
make stop
```