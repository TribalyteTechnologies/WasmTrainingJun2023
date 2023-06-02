# Runtime Example

This is a simple example based on a helloWorld in C++ to test the functionality of Wasmedge runtime.

To run this example, first of all we have to generate the file associated to WebAssembly, the .wasm. To generate this file we can run the Makefile through:

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

Note that there is also the option to clean, to delete the compiled files:

```shell
make cleanExample
```

To run the .wasm with Wasmedge it will do through a Docker image, in particular the wasmedge/slim version 0.12.0: https://hub.docker.com/layers/wasmedge/slim/0.12.0/images/sha256-ac1bd5342500b0e5c978ce248388013044003e55a03efb4b39bfffb959108f33?context=explore

To execute this example with Wasmedge we can execute the next:

```shell
make run
```