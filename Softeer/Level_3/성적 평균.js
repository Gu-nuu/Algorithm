const readline = require("readline");
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

var lines = [];

rl.on("line", (line) => {
    lines.push(line);
}).on("close", () => {
    var [N, K] = lines[0].split(" ").map(Number);
    var score = lines[1].split(" ").map(Number);
    var range = [];
    for (var i = 2; i < K + 2; i++) {
        var [a, b] = lines[i].split(" ").map(Number);
        range.push([a, b]);
    }
    for (var i = 0; i < range.length; i++) {
        var sum = 0;
        var size = range[i][1] - range[i][0] + 1;
        for (var j = range[i][0] - 1; j <= range[i][1] - 1; j++) {
            sum += score[j];
        }
        console.log((sum / size).toFixed(2));
    }
    process.exit(0);
});
