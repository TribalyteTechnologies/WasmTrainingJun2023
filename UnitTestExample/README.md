# Unit tests in Webassembly

In this simple example we are going to show how to make unit test to our WASM file, we will use the Jest framework working on node js

more information in https://jestjs.io/



We must install Jest in the directory to test.  

```shell
npm install --save-dev jest
```

run
```shell
jest --init
```
Based on your project, Jest will ask you a few questions and create a basic configuration file with a short description for each option:

The file that will contain the test must be called "yourtest.test.js" and we must place it in a directory called __test__

Add the following section to your package.json:
```shell
{
  "scripts": {
    "test": "jest"
  }
}
```
Before running the tests, you must make sure that you have compiled and generated at least the file, .wasm

For that, make use of the Makefile found in the example directory.

Finally, run  or "npm test" and Jest will print this message to the screen:

```shell
> test
> jest

 PASS  __test__/index.test.js
  ✓ Add operation 6 + 30 = 36 (2 ms)
  ✓ Add operation 2 + 2  =  4 (1 ms)
  ✓ Mult operation  9 * 2 = 4 (1 ms)
  ✓ Square operation 5 = 25 (1 ms)

Test Suites: 1 passed, 1 total
Tests:       4 passed, 4 total
Snapshots:   0 total
Time:        0.26 s, estimated 1 s
Ran all test suites.
```