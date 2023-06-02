# Qt/Qml and WebAssembly example

The following example presents an application developed in QML and C++, using Qt. This application is a replica of the Tribalye web page (https://www.tribalyte.com/) that has functionalities such as redirecting to the Tribalye web page of Technologies or Ideas, or changing the background color of each logo.

The purpose of this example is that starting from the developed application this can be seen through a web thanks to the integration of Qt with WebAssembly.

The first thing to keep in mind is that we must have Qt Creator. For this example we have used version 7.0.2. In addition to other projects with WebAssembly, it is necessary a compiler to transform our C++ code to WebAssembly. In the case presented we have used Emscripten which is integrable with Qt.

When we work with Qt and Emscripten, the version used for each of them must be taken into account. In the following page we can see the dependencies between versions of these two tools, taking into account that we work with Qt 5: https://doc.qt.io/qt-5/wasm.html

In this example we have used Qt version 5.15, and Emscripten version 1.39.8.

To ensure that Emscripten is using the correct version, we can install it and then activate it. For example in the present case:

```shell
./emsdk install 1.39.8
```

```shell
./emsdk activate 1.39.8
```

With Emscripten ready, the next step is to check if we have the WebAssembly plugin associated in Qt Creator. This can be checked in the option "Tools->Options->Kits" in the Qt Creator. There we can see if the kit associated with WebAssembly is present or not.

If we do not see the WebAssembly plugin, we will have to install it. To do it, we have to access to the Qt installation directory. In this directory we will find an executable named "MaintenanceTool". This executable will open the Qt maintenance tool. After logging in, choose the option to add or remove components.

Then open the Qt option and from the chosen Qt version look for and check the "WebAssembly" component. Also if the compiler is not selected, choose this one too, for example if we are working on Linux choose the gcc option.

Once selected, click next and install.

When Qt Creator is open after the last steps, we will see a message in the bottom of Qt Creator associated with the WebAssembly plugin that we have just installed, telling us to add it the build path. We click to add and we assign the associated path where we have installed Emscripten, that is the directory "emsdk".

After this, if a project is opened, we can configure the kit to be used. For the case presented that we want to work with WebAssembly, we choose "Qt 5.15.2 WebAssembly".

With the previous steps done we could compile and build our project. Normally the compilation of WebAssembly is usually done by command window, however in Qt Creator with the associated plugin and the kit added, which is that we have done in the previous steps, we can compile and build the project for WebAssembly. Note that in Qt Creator we must assign the directory in which the project is built because if it is not indicated by default Qt Creator will create a new directory. To assign the directory where the project will be built we can access it through the "Project" option and modify the "Build directory".

When we build the project we can see that several files are created in the build folder. However when we work with Qt and WebAssembly to view the Qt/Qml project from a web site we can count with four main files that will be the necessary for the implementation:

- app.html
- app.wasm
- app.js
- qtloader.js

In addition to the basic files, app.wasm and app.js, there will be the qtloader.js which provides a JavaScript API to load and manage Qt/Qml applications.

Another file that stands out is the app.html. This file will contain the content of the basic web page that load the WebAssembly compile application. Normally we usually start with our own .html and then we add the .js associated with WebAssembly. However for Qt this is not enough. It is necessary to configure certain aspects to finally make reference to the app.js and qtloader.js, with the purpose of displaying correctly the application to display in the web browser.

To use in our web for easy to use we can copy the code associated to the generated app.html removing the following sentence that loads the Qt logo when loading the page, something that we probably will not want in our web:

```html
<figure style="overflow:visible;" id="qtspinner">
    <center style="margin-top:1.5em; line-height:150%">
    <img src="qtlogo.svg" width="320" height="200" style="display:block"></img>
    <strong>Qt for WebAssembly: exampleQtQml</strong>
    <div id="qtstatus"></div>
    <noscript>JavaScript is disabled. Please enable JavaScript to use this application.</noscript>
    </center>
</figure>
```

To run this application in the web server with WebAssembly, it is enough to have the following files generated after the construction:

- exampleQtQml.html (or out .html with the part of load the qt/qml application)
- exampleQtQml.wasm
- exampleQtQml.js
- qtloader.js

To launch the application it can be done for example with the vsCode Live Server extension or with Apache.

Note that to visualize the web using WebAssembly we can use QtCreator. Having selected the WebAssembly kit, if the application is run, a server will be launched with the associated web in such a way that a browser will open with our web.
