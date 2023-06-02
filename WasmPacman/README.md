# PACMAN

This is a starting project to experiment with WebAssembly. To see how difficult it is to port programs designed entirely in C++ to WebAssembly.

The source code can be found at: https://github.com/uplinkx/pacman

Clone the remote repository to this directory
```shell
git clone https://github.com/uplinkx/pacman.git
```


## Build

To compile this example with the Makefile from our repository

With Emscripten installed: (NOTE:You need Emscripten version maximun 2.0.0)

```shell
make compilePacmanExample
```

With Docker image:

```shell
make dockerCompilePacmanExample
```

The last step is to exceute the html to throught the web. For this we can do it with an image of Apache to server the web.

To do it we can execute the next command:

```shell
make run
```

The last command, run the docker image and serve the web in localhost, so we can see the web by open the browser and access to:
http://localhost:2345/pacman/


When we end to work with the web we must stop the Apache image, so it can be used in the future. We can do it by:

```shell
make stop
```