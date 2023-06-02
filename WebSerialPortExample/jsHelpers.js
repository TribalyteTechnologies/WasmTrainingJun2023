
var port;
let fileHandle;
var getread=1;
comTest.addEventListener('click', async () => {
const requestOptions = {
     // filters: [{ vendorId: 0x0403 }],
    };

port = await navigator.serial.requestPort(requestOptions);
const encoder = new TextEncoder();
await port.open({ baudRate: 9600 });
console.log("COM Open");
const reader=port.readable.getReader();
const writer=port.writable.getWriter();
await writer.write(encoder.encode(document.querySelector("#tx").value));
getread=1;
while (getread==1) {
  const { value, done } = await reader.read();
  if (done) {
    // Allow the serial port to be closed later.
    reader.releaseLock();
    break;
  }
  var string=new TextDecoder().decode(value);
  console.log("received by serial port: " +string);
  document.getElementById("rx").value=string;
  getread=0;
}
reader.cancel();
await writer.releaseLock();
await reader.releaseLock();
port.close();
console.log("COM closed");
});

