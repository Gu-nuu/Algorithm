function solution(t, p) {
    var answer = 0;
    var cnt = 0;

    for (var i = 0; i <= t.length - p.length; i++) {
        var temp = "";
        for (var j = i; j < i + p.length; j++) {
            temp += t[j];
        }
        console.log(Number(temp));
        if (Number(temp) <= Number(p)) {
            answer += 1;
        }
    }
    console.log(cnt);
    return answer;
}
