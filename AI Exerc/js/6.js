const brain = require('brain.js');
const net = new brain.NeuralNetwork();

const data = [
  { input: { entrada1: 0, entrada2: 0 }, output: { saida: 0 } },
  { input: { entrada1: 0, entrada2: 1 }, output: { saida: 1 } },
  { input: { entrada1: 1, entrada2: 0 }, output: { saida: 1 } },
  { input: { entrada1: 1, entrada2: 1 }, output: { saida: 0 } }
];

net.train(data);

const output00 = Math.round(net.run({ entrada1: 0, entrada2: 0 }).saida);
const output01 = Math.round(net.run({ entrada1: 0, entrada2: 1 }).saida);
const output10 = Math.round(net.run({ entrada1: 1, entrada2: 0 }).saida);
const output11 = Math.round(net.run({ entrada1: 1, entrada2: 1 }).saida);

console.log(`0 xor 0:`, output00);
console.log(`0 xor 1:`, output01);
console.log(`1 xor 0:`, output10);
console.log(`1 xor 1:`, output11);