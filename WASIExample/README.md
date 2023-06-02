# WASI example

This repository shows a simple example of using WASI with the Wasmtime runtime.

WebAssembly is normally intended to run in a web browser, however there is the possibility of being able to run an application without a web browser which can be useful for certain uses. When working outside the browser with WebAssembly, for example if we run the WebAssembly code with a runtime there is the possibility of establishing an interface to access certain APIs of the system on which the application is running. This gives for example the possibility to work with files, use sockets, etc...

In this repository we will have a WebAssembly application that will be able to access the file we have defined in the project from its execution in a runtime thanks to the use of WASI.

The first step to run this example is to generate the WebAssembly file from the C++ file we have. In previous examples we have used the Emscripten compiler to generate the WebAssembly code. However, when working with WASI, this solution will not work and we will have to choose another compiler.

WASI defines a sandbox with the advantage that we can decide which resources to share with the host where we run it, something that with Emscripten we can't do because it uses the sandbox provided by the host, for example if we run on the web it would be the one associated with the web browser where we run it.

An alternative to Emscripten could be to use Clang integrated with wasi-SDK.

To use wasi-SDK, the first step is to make sure that the following applications are installed:

- cmake
- clang
- ninja

To install each of the previous tools we can execute:

For cmake:

```shell
sudo apt-get install cmake
```

For clang:

```shell
sudo apt-get install clang
```

For ninja:

```shell
sudo apt-get install ninja-build
```

The following versions of the above applications have been used in the example presented:

- cmake -> version 3.22.1
- clang -> verison 14.0.0
- ninja -> version 1.10.1

Once we have the above applications, the next step is to clone the wasi-sdk repository.

```shell
git clone --recursive https://github.com/WebAssembly/wasi-sdk.git
```

Next step is to build the package:

```shell
cd wasi-sdk
NINJA_FLAGS=-v make package
```

Then we have to define the necessary variables with the downloaded version of wasi-sdk. For example, we have used version 14.

```shell
export WASI_VERSION=14
export WASI_VERSION_FULL=${WASI_VERSION}.0
```

Then define a wasi-sdk path variable:

```shell
export WASI_SDK_PATH=`pwd`/wasi-sdk-${WASI_VERSION_FULL}
```

And define a variable associated with the Clang++ compiler to be used:

```shell
CCPP="${WASI_SDK_PATH}/bin/clang++ --sysroot=${WASI_SDK_PATH}/share/wasi-sysroot"
```

With all the above steps done, the C++ file can be compiled to obtain the WebAssembly. To do so, run:

```shell
$CCPP wasiExample.cpp -o wasiExample.wasm
```

Once we have the .wasm file, we can run it with a runtime. 

We can run the example using a docker image of Wasmtime. To do it just run:

```shell
make run
```

or 

```shell
make
```

The last sentence execute an image of Wasmtime based of 0.36.0 version.

There is also the chance to execute Wasmtime in our machine. To do it we have to install it:

```shell
curl https://wasmtime.dev/install.sh -sSf | bash
```

In the test we are use Wasmtime 8.0.1 version.
To finish with Wasmtime installed, we can run the .wasm program with the following statement:

```shell
wasmtime --dir=. wasiExample.wasm
```

Wasmer uses WASI so directories can be shared. This action is performed on the line above by specifying "--dir=.", where the current execution directory is specified to be shared. In this way it will be possible to see that from the runtime there is access since in the execution it prints the message that is located in the "test.txt" file.