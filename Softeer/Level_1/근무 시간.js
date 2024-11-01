const readline = require("readline");
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

var lines = [];

rl.on("line", (line) => {
    var [a, b] = line.split(" ");
    lines.push([a, b]);
}).on("close", () => {
    var answer = 0;

    for (var i = 0; i < lines.length; i++) {
        var [start_hour, start_minute] = lines[i][0].split(":");
        var [end_hour, end_minute] = lines[i][1].split(":");

        var total_start = Number(start_hour) * 60 + Number(start_minute);
        var total_end = Number(end_hour) * 60 + Number(end_minute);

        answer += total_end - total_start;
    }
    console.log(answer);
});
