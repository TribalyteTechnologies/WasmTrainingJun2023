# Boost websocket example

The main purpose of using WebAssembly is to take advantage of C++ or C programs that we already have. For example we might have a C++ application based on socket or websocket that uses the Boost library. It would be great to be able to use this application that uses sockets or websockets with WebAssembly, so that it can later be integrated for its use in a web browser.

However, the reality is that this utility does not seem to be possible, at least at this time. If we start from a program that uses for example websockets with the Boost library, and we build our program with Emscripten to get the Webassembly file we will find a first possible problem which are problems at the time of building the application.

This depends on the version of Emscritpen that we have installed or that we are using through a docker image. For example in previous cases we have used version 3.1.36, however when we compile for example our C++ program that contains the Boost library, specifically Asio, we will get conversion errors among others. These errors are produced in the new versions of the Emscripten compiler. If we change to an older version such as 3.1.28, our program will compile with success. From the tests that we have done, it has been verified that the last version of Emscripten that does not produce compilation errors with programs that use the Boost Asio library is 3.1.28.

With the compilation finished, we can proceed to test the compiled application in WebAssembly. However, when testing it for example in a browser, we will see that it stays blocked and there are no error traces. What is happening is that it has tried to connect, but the connection is closed in such a way that when we try to write something an error occurs that leaves everything blocked.

The fact that the connection is closed seems to be the cause of the code that has been generated with Emscripten, specifically the javascript file. Emscripten provides some solutions when we work with sockets, however, when we have a case like an application that uses websockets from the Boost library, Emscripten documentation commented that the use of TCP networking code written in C/C++ that use the Posix Sockets API is not very complete at the moment and it is probable that it has factory problems and there are limitations on this emulation.

To see more information access the following page: https://emscripten.org/docs/porting/networking.html

Therefore, it can be summarized that, at least at the moment in which the commented case has been written and tested, it is not recommended to use Boost sockets or websockets with WebAssembly.

An example of using websockets in C++ using Boost is presented in the current directory. This example can be used to see what we was just commented.

To run this example, first of all, we have to generate the files associated to WebAssembly, the .wasm and the .js. To generate these files we can run make in our machine if we have Emscripten or by a Docker image if we do not have Emscripten installed or we do not want to install it. Note that the test have been done with Emscripten version 3.1.28, both for the docker image, and for having it installed in the machine that we work, and on the other hand we tested with Boost library version 1.81.0.

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

Once the example has been compiled before opening the corresponding .html, note that for the tests it is necessary to open a websocket emulating the server. For this, in the case presented, a Websocat docker image has been used, serving localhost on port 3333. To do it, in other terminal we can execute:

```shell
make runWebsocat
```

We can change host or port serve changing "WEBSOCKET_HOST" and "WEBSOCKET_PORT" variables in the Makefile.

Once the previous steps have been taken, the next step is to serve the web. For this, as another examples, we could do a make run. However, for this case of the websockets it gives several errors when using the Apache image, errors that can be seen on the web, so another solution could be to use the LiveServer extension of VSCode with which it has also been tested.

If Apache image is used, open the web with the next link:
http://localhost:2345/boostWebsocketExample.html

In both cases we will be able to see the behavior that is that the web browser where it is executed is blocked. Going into more detail, this block occurs when writing in the example. We can try commenting the code in the example from the connection to see the error produced. In this case if we compile and serve the web with the generated WebAssembly we will see an error that tell us that the connection has been closed, action that seems to be done from the Javascript generated by Emscripten and that makes it impossible the connection.

This example although is not well through WebAssembly, it can be tested directly compiled in C++. To do this we would follow the previous steps with the difference that the compilation will be done through g++. To do this we can run:

```shell
make compileCppBoostExample
```

With the Websocat up, if we run the executable generated in the "build" directory, we can see that we receive a "Hello World!", testing the correct operation of the Websocket in C++.