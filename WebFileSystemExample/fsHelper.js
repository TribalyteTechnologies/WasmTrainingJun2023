        let fileHandle;
        let contents;
        openw.addEventListener('click', async () => {
          [fileHandle] = await window.showOpenFilePicker();
          const file = await fileHandle.getFile();
          contents = await file.text();
          contents = contents + "Text to be added to the end of the file\n";
          const writable = await fileHandle.createWritable();
          await writable.write(contents);
          await writable.close();
        });


        sas.addEventListener('click', async () => {
          const options = {
            types: [
                   {
                    description: 'Text Files',
                    accept: {
                    'text/plain': ['.txt'],
                  },
                },
              ],
            };
          fileHandle = await window.showSaveFilePicker(options);
          var contents = "Text to be added to the end of the file\n";
          const writable = await fileHandle.createWritable();
          await writable.write(contents);
          await writable.close();
        });
     






