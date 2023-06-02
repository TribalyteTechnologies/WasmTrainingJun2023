const fs = require('fs');
let math;
const env = {
    memoryBase: 0,
    tableBase: 0,
    memory: new WebAssembly.Memory({
      initial: 256
    }),
    table: new WebAssembly.Table({
      initial: 0,
      element: 'anyfunc'
    })
  }

beforeAll(async () => {
    const mathWasm = fs.readFileSync('./build/unitTest.wasm');
    math = await WebAssembly.instantiate(new Uint8Array(mathWasm),{env: env})
                    .then(result => result.instance.exports);
})

test('Add operation 6 + 30 = 36', () => expect(math.addInt(6,30)).toBe(36) );
test('Add operation 2 + 2  =  4', () => expect(math.addInt(2,2)).toBe(4) ); 
test('Mult operation  9 * 2 = 18', () => expect(math.multInt(9,2)).toBe(18) ); 
test('Square operation 5 = 25', () => expect(math.square(5)).toBe(25) ); 