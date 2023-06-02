# Virtual File System example

This is a simple example of how to use the Virtual File System provided by WebAssembly

The following example presents some of the functionality of the WebAssembly virtual file system API. this Api It is documented at the following URL https://emscripten.org/docs/api_reference/Filesystem-API.html#filesystem-api

This example presents a simple form for collecting user data. In it the person will enter their personal data, the message and the department to which they are going. This data is stored in a file "/data/file.txt". the C++ code Write and Read the file, checks if the name is repeated, in which case, this new data entry is not written to the file, the content of the file is displayed on the console.



In this program the associated properties are used to use through WebAssembly classes, structures, enumerations and exceptions that have been created in C++.

To run this example, first of all we have to generate the files associated to WebAssembly, the .wasm and the .js. To generate these files we can run make in our machine if we have Emscripten or by a Docker image if we do not have Emscripten installed or we do not want to install it. Note that the test have been done with Emscripten version 3.1.36, both for the docker image, and for having it installed in the machine that we work.

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
http://localhost:2345/virtualFS.html

When we end to work with the web we must stop the Apache image, so it can be used in the future. We can do it by:

```shell
make stop
```