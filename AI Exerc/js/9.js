const brain = require('brain.js');
var config = {
binaryThresh: 1,
hiddenLayers: [3],
activation: 'sigmoid',
leakyReluAlpha: 0.01,
inputSize: 2,
inputRange: 2,
outputSize: 1,
learningRate: 0.01,
decayRate:0.999
};
var net = new brain.NeuralNetwork(config);
net.train([
{input:[0,0], output:[0]},
{input:[0,1], output:[1]},
{input:[1,0], output:[1]},
{input:[1,1], output:[0]}
]);
var output = net.run([0,1]);
console.log(output)

// Guardem executem a rede e verifiquem os valores

// alterando configurações da rede num ficheiro nomedoficheiro9.js


config = {
binaryThresh: 1,
hiddenLayers: [1],
activation: 'sigmoid',
leakyReluAlpha: 0.01,
inputSize: 2,
inputRange: 2,
outputSize: 1,
learningRate: 0.01,
decayRate:0.999
};
net = new brain.NeuralNetwork(config);
net.train([
{input:[0,0], output:[0]},

{input:[0,1], output:[1]},
{input:[1,0], output:[1]},
{input:[1,1], output:[0]}
]);
output = net.run([0,1]);
console.log(output)

// Guardem executem a rede e verifiquem os valores
// verifiquem que houve perda de precisão dos resultados esperados...