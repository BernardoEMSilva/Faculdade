const brain = require('brain.js');
const net =new brain.NeuralNetwork();
net.train([
{input:[0,0], output:[0]},
{input:[0,1], output:[1]},
{input:[1,0], output:[1]},
{input:[1,1], output:[0]}
],{
Iterations:10000,
errorThresh: 0.004,
Log: true,
logPeriod:1000,
learningRate:0.3,
momentum:0.1,
callback: function(){
console.log (`função de callback chamada!!!?`);
},
callbackPeriod:1000,
timeout:Infinity
});
const output = net.run([0,1]);
console.log(output);