function solution(s) {
    var answer = [];
    var temp = "";

    for (var i = 0; i < s.length; i++) {
        if (temp.lastIndexOf(s[i]) === -1) {
            answer.push(-1);
        } else {
            answer.push(i - temp.lastIndexOf(s[i]));
        }

        temp += s[i];
    }

    return answer;
}
