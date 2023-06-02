
  function saveFile()
  {
    let nameVar = String(document.getElementById("name").value);
    let departamentIdVar = document.getElementById("departament");
    const departmentId = (departamentIdVar.selectedIndex)?("Tribalyte.Ideas"):("Tribalyte.Tech");
    const stringVector = new Module.StringVector();
    stringVector.push_back(nameVar);
    stringVector.push_back(departmentId);
    Module.processStringVector(stringVector);
    let contents = Module.readFromFile('/data/file.txt');
    console.log("file.txt  Content \n");
    console.log(contents);
  }


