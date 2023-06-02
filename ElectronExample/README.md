# Electron example

The current directory contains a simple example of how to use WebAssembly with Electron.js, in such a way that if we have a web site that contain WebAssembly we can build it and obtain a desktop application from this.

For this example we will need to have for the Electron.js part Node.js and npm installed in our machine. These can be installed as follows:

```shell
sudo apt-get install nodejs
sudo apt-get install npm
```

This project has been executed under the following software versions:
- Node.js 16.19.1
- npm 8.19.13

As we can see, the project structure consists of the main directory and the "web" directory. On the one hand "web", contains the file "electronExample.html" associated to the web, as well as the "electronExample.cpp" file from which the WebAssembly will be obtained. On the other hand, the main directory contains the "main.js", "package.json" and "package-lock.json" file that executes the main process that controls the app and runs in a Node.js environment.

To start, we will have to compile the file "electronExample.cpp" to obtain the associated .wasm and .js files. To generate these files we can run make in our machine if we have Emscripten or by a docker image if we do not have Emscripten installed or we do not want to install it. Note that the test have been done with Emscripten version 3.1.36, both for the docker image, and for having it installed in the machine that we work.

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

Note that there is also the option to clean, to delete the compiled files we can execute:

```shell
make cleanExample
```

Once we have the part of the web, that is the .html, the .wasm and the associated .js, we can go to the "electron" directory to obtain the application associated to our web through Electron.js.

The first step is to start the npm package:

```shell
npm init
```

After executing the last sentence we will have to configure some parameters such as the entry point that will have to be the "main.js" file and also add other values such as the author and the description necessary to package the applications.

The next step is to install the electron package in the devDependencies of our application. To do it, execute

```shell
npm install --save-dev electron
```

Before executing the application, to run it we have to add the "start" command to run Electron in the "package.json". That is the next line inside "scripts":

```shell
"start": "electron ."
```

The "package.json" file would look something like:

```json
{
  "name": "electron",
  "version": "1.0.0",
  "description": "electron example with WebAssembly",
  "main": "main.js",
  "scripts": {
    "start": "electron .",
    "test": "echo \"Error: no test specified\" && exit 1"
  },
  "author": "amelian",
  "license": "UNLICENSED",
  "devDependencies": {
    "electron": "^24.1.2"
  }
}
```

Finally, the application can be launched by:

```shell
npm start
```