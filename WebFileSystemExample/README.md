# Access to the local file system
### This is a simple example of how to use File System Access api in an HTML web page.
## Secure context: This feature is available only in secure contexts (HTTPS), in some or all supporting browsers.  https://developer.mozilla.org/en-US/docs/Web/Security/Secure_Contexts


WebAssembly does not have access to the local file system, for this reason it uses the File System Access API 
the "Open and Save" button opens a local file explorer, the file selected by the user is read, a string is added to the end, and finally saved again with the same name.
the button "SaveAs", allows us to save the data entered in the form, in a file from which we can choose the name


To end, execute the web through LiveServer extension in VSCode for example, which will create a local mini server from Visual Studio to check the web application.

Once the Web is launched, open the browser console, enter the data and execute to see the messages generate.