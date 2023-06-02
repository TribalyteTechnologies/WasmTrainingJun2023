# E2E test thread example

This following example shows how to do and run, an E2E test with cypress tool when we using an application that use WebAssembly with threads. 

The presented example is a simple exercise that starts with a simple C++ program that will print a trace for each thread executed, having a "Main thread" and two more threads, recognized as "1" and "2". The C++ code will be passed to WebAssembly thanks to the Emscripten compiler and will later be integrated into an .html. After this, and end to end test can be launched using the Cypress tool to see that the threads has been run, verifying the traces that they generate.

First we will have to compile the file "e2eTestThreadExample.cpp" to obtain the associated .wasm, .js and .wrker.js files. To generate these files we can run make in our machine if we have Emscripten or by a docker image if we do not have Emscripten installed or we do not want to install it. Note that the test have been done with Emscripten version 3.1.36, both for the docker image, and for having it installed in the machine that we work.

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

Note that there is also the option to clean, to delete the compiled files we can execute:

```shell
make cleanExample
```

Once we have this, we can move on to the end to end tests. For this, Cypress has been used, specifically its version 12.11.0.

There are two files to take into account when we do the tests. On the one hand, the "spec.cy.js" that will contain the tests to be carried out, where it will be verified that the traces associated with the execution of each thread are shown, verifying their execution. On the other hand the configuration file of the test "cypress.config.js". In this file we must highlight the enable of SharedArrayBuffer for Google Chrome, which is the browser used for the tests. This enable is done because it is a feature that is disabled for security in the latest versions of Chrome, but when using threads with WebAssembly it is necessary to activate it.

Taking the above into account, the next step would be to execute the tests. For this, we can use the docker-compose located in this directory that will use Docker images from Apache (version 2.4) to launch the web and Cypress (version 12.11.0) for run the tests. To use the docker-compose we can execute:

```shell
make run
```

or

```shell
docker-compose -f docker-compose.yml up --abort-on-container-exit
```

If the test passes correctly, it check that the traces have been printed by each thread, and that therefore the example of threads with WebAssembly works correctly.