function sendMessage(){
let numvar = parseInt(document.getElementById("number").value); 
const idl = new Module.Idlclass();
idl.setVal(numvar);
document.getElementById("number").value=idl.getVal();
console.log("idl value:", idl.getVal());
}