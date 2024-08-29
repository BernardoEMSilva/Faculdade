const brain = require('brain.js');
const cv = require('ml-cross-validation');
const arrayData = [
    [1269, 25198],
      [144, 2745],
      [1163, 18837],
      [52, 803],
      [41, 242],
      [3, 65],
      [3059, 72575],
      [711, 26665],
      [167, 9311],
      [713, 18246],
      [423, 23242],
      [11, 91],
      [141, 36110],
      [2965, 125683],
      [7, 94],
      [538, 60492],
      [9822, 17452],
      [2, 26],
      [35, 1036],
      [0, 86],
      [2647, 21478],
      [294, 4930],
      [2, 63],
      [87618, 1846641],
      [3, 138],
      [347, 5585],
      [53, 926],
      [6, 292],
      [1, 301],
      [22, 1550],
      [0, 147],
      [391, 14539],
      [8944, 0],
      [59, 1546],
      [75, 810],
      [9187, 319954],
      [4656, 78869],
      [8777, 131161],
      [7, 328],
      [54, 829],
      [208, 5700],
      [115, 3824],
      [96, 10361],
      [139, 3936],
      [87, 2351],
      [19, 852],
      [373, 11428],
      [613, 12605],
      [58, 4977],
      [0, 18],
      [1083, 30204],
      [5532, 34896],
      [4652, 34838],
      [408, 7778],
      [51, 842],
      [0, 191],
      [69, 1923],
      [34, 1025],
      [228, 6386],
      [0, 18],
      [329, 6920],
      [30212, 81212],
      [49, 4682],
      [8, 66],
      [16, 922],
      [9125, 190314],
      [168, 29801],
      [202, 1374],
      [0, 13],
      [0, 23],
      [1761, 32455],
      [45, 6257],
      [26, 803],
      [20, 181],
      [158, 4365],
      [0, 12],
      [1166, 5039],
      [596, 3329],
      [10, 1823],
      [33408, 951166],
      [4838, 58173],
      [15912, 255144],
      [4458, 77144],
      [1764, 23364],
      [474, 27133],
      [35112, 198593],
      [10, 714],
      [998, 21970]
    
    ];
    

    const data = arrayData.map(([deaths, recovered]) => ({
        input: { recovered },
        output: { deaths: recovered !== 0 ? Math.floor(Math.round(deaths / recovered)) : 0 }
      }));
      
      const networkOptions = { hiddenLayers: [3], learningRate: 0.01 };
      const trainingOptions = { iterations: 20000, errorThresh: 0.004 };
      
      const net = new brain.NeuralNetwork(networkOptions);
      const stats = net.train(data, trainingOptions);
      

      const output = net.run({ recovered: 10000 });
      console.log(`De acordo com o nosso modelo, a cada 10000 pessoas a taxa de morte é de ${output.deaths}%.`);
      console.log(`\t->Número de iterações: ${stats.iterations}`);
      console.log(`\t->Erro final: ${stats.error}`);