# Access to the local Serial Port

The following example presents some of the functionality that Serial api provides , which 
allows us to access the serial port of the local machine.

## Secure context: This feature is available only in secure contexts (HTTPS), in some or all supporting browsers.  https://developer.mozilla.org/en-US/docs/Web/Security/Secure_Contexts




Currently it is not possible to access the serial port using WebAssembly, see discussion https://github.com/WebAssembly/WASI/issues/350
This example makes use of the Serial api from Chrome for handling COM Ports,
the "Serial Port Test" button opens a COM in the local machine, and sends the text "ABCDE" through the serial port, and shows what it receives in the the browser console. 


In the development a device that returns the echo was used. 


To end, execute the web through LiveServer extension in VSCode for example, which will create a local mini server from Visual Studio to check the web application.

Once the Web is launched, open the browser console, enter the data and execute to see the messages generate.