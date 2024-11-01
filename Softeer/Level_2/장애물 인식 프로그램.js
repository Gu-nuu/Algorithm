const readline = require("readline");
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

var lines = [];

rl.on("line", (line) => {
    lines.push(line);
}).on("close", () => {
    var answer = [];
    var N = Number(lines[0]);
    var board = Array.from(Array(N), () => new Array(N).fill(0));
    var isVisited = Array.from(Array(N), () => new Array(N).fill(0));
    var dir = [
        [-1, 0],
        [0, 1],
        [1, 0],
        [0, -1],
    ];

    for (var i = 1; i < lines.length; i++) {
        for (var j = 0; j < lines[i].length; j++) {
            board[i - 1][j] = Number(lines[i][j]);
        }
    }

    const BFS = (start_r, start_c) => {
        var queue = [];
        var area = 1;
        isVisited[start_r][start_c] = 1;
        queue.push([start_r, start_c]);

        while (queue.length > 0) {
            var [r, c] = queue.shift();

            for (var d = 0; d < 4; d++) {
                var dr = r + dir[d][0];
                var dc = c + dir[d][1];

                if (dr >= 0 && dr < N && dc >= 0 && dc <= N && isVisited[dr][dc] === 0 && board[dr][dc] === 1) {
                    area++;
                    isVisited[dr][dc] = 1;
                    queue.push([dr, dc]);
                }
            }
        }
        answer.push(area);
    };

    for (var i = 0; i < board.length; i++) {
        for (var j = 0; j < board[i].length; j++) {
            if (board[i][j] === 1 && isVisited[i][j] === 0) {
                BFS(i, j);
            }
        }
    }

    console.log(answer.length);
    answer.sort((a, b) => a - b);
    for (var i = 0; i < answer.length; i++) {
        console.log(answer[i]);
    }
});
