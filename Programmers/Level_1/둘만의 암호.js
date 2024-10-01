function solution(s, skip, index) {
    var answer = "";

    var alphabet = [..."abcdefghijklmnopqrstuvwxyz"];
    var skip_index = [];

    for (var i = 0; i < skip.length; i++) {
        skip_index.push(alphabet.indexOf(skip[i]));
    }

    for (var i = 0; i < s.length; i++) {
        var s_index = alphabet.indexOf(s[i]);

        var count = 0;

        while (count !== index) {
            if (s_index + 1 < alphabet.length) {
                s_index++;
            } else {
                s_index = 0;
            }

            if (skip_index.indexOf(s_index) != -1) {
                count--;
            }

            count++;
        }

        answer += alphabet[s_index];
    }

    return answer;
}
