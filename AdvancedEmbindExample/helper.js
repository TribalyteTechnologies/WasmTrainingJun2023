function sendMessage(){
  const nameIn = document.getElementById("name").value;
  const lastNameIn = document.getElementById("lastname").value;
  let departamentIdVar = document.getElementById("departament");
  const departmentId = (departamentIdVar.selectedIndex)?("Tribalyte.Ideas"):("Tribalyte.Tech");
  let ageIn = parseInt(document.getElementById("age").value);

  const myStruct = { name: nameIn, lastName: lastNameIn , age: ageIn };
  const MyMap = new Module.MyMap();
  MyMap.set(departmentId,nameIn, myStruct);
  console.log(MyMap.get(departmentId,nameIn));
}
