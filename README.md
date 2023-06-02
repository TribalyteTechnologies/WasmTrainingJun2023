# WebAssembly
This repository presents examples of the use of C++ and C applications in web pages, using WebAssembly for its integration.

To generate the WebAssembly files, that is .wasm and .js, we are going to use the compiler Emscripten. We can see information about this compiler in the next page: https://emscripten.org/

Highlight that the version of Emscipten used is the examples has been the 3.1.36. Also, we should highlight that this has been tested on a Linux operating system, specifically in Ubuntu 22.04.

Each of this examples have a README.md in their directories that explain the way to run each example. 

On the other hand as a general point we can compile through the Makefile that almost all directories have. Before doing the make in each directory, emphasize that there are two ways to do the make. The first one is executing make. This way will require that we have Emscripten installed in the machine. To install it, we can follow the steps described in the official documentation: https://emscripten.org/docs/getting_started/downloads.html. Once installed in each directory, simply run make or make all. The second way to do the make is by the Emscripten Docker image. For this way it will not be necessary to have Emscripten installed on our machine, because the compilation will be done through the Docker image. 

Note that there are some examples that have different compilation and do not have Makefiles. These examples are the next, referring to their directories:

- QtQmlExample
- WASIExample
- WebFileSystemExample
- WebSerialPortExample

In addition to the compilation in each of the directories through make, we can clean the compiled files through "make clean".

Lastly, we can see two makefiles in the root directory. The first one, Variable.mk include the variables used for each Makefile located in the different directories. On the other hand there is a Makefile. The purpose of this Makefile is call and execute the other Makefile that are located in the directories, in such a way that we can compile or clean all examples that have a Makefile with a single command. 

As in the case of each directory, there will be two ways to compile. One with Emscripten installed in our machine, and the other via a Docker image of Emscripten.

To compile in our machine if we have Emscripten, we can execute:

```shell
make emscriptenCompile
```

The above command will compile all the examples except the "Boost" examples. To run these examples with Emscripten installed we can follow the instructions for each example in each associated directory.

If we want to do through the Docker image and so that we are not dependent on having Emscripten installed. We can do:

```shell
make
```

or 

```shell
make all
```

or

```shell
make compile
```

The last three comands will build all example with a makefile, include the "Boost" examples.

In this point highlight that almost all example build with Emscripten version 3.1.36, but there are two example that need a lower version, specifically the version 3.1.28. These two examples are the next: 

- BoostSocketExample
- BoostWebsocketExample

Finally, if we want to delete all the files in all the directories that have been created with the compilation, we can execute:

```shell
make clean
```

There are some examples that can be run thanks to a Docker Apache image. To do it execute:

```shell
make run
```

in some of the next example available:

- BoostAlgorithExample
- BoostSocketExample
- BoostWebsocketExample
- DebuggingExample
- E2ETestExample
- EmbindExample
- HelloWorldWebAssembly
- HelloWorldWebAssemblyC
- WebAssemblyVirtualFS

Once run the image, the last step is open the browser and access to localhost.

Note that the above command can be executed from the current directory. In this case it should be noted that the URLs indicated in the READMEs of each example will change. Even so, if we execute the above command and access "localhost" or "127.0.0.1", and port 2345, we will be able to navigate through the different examples by opening each of them.

When we end to test with the web is important to stop the image for a future use. To do it run:

```shell
make stop
```