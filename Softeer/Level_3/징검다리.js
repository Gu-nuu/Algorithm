const readline = require("readline");
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

var lines = [];

rl.on("line", (line) => {
    lines.push(line.split(" "));
}).on("close", () => {
    var N = Number(lines[0][0]);
    var height = lines[1].map(Number);

    var dp = new Array(N).fill(1);

    for (var i = 0; i < N; i++) {
        for (var j = i + 1; j < N; j++) {
            if (height[i] < height[j]) {
                dp[j] = Math.max(dp[i] + 1, dp[j]);
            }
        }
    }

    console.log(Math.max(...dp));

    process.exit(0);
});
