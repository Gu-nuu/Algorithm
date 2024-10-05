function solution(today, terms, privacies) {
    var answer = [];

    var today_day =
        Number(today.split(".")[0]) * 12 * 28 + Number(today.split(".")[1]) * 28 + Number(today.split(".")[2]);

    var terms_day = new Map();
    for (var i = 0; i < terms.length; i++) {
        var split_terms = terms[i].split(" ");
        terms_day.set(split_terms[0], Number(split_terms[1]) * 28);
    }

    for (var i = 0; i < privacies.length; i++) {
        var privacies_day =
            Number(privacies[i].split(" ")[0].split(".")[0]) * 12 * 28 +
            Number(privacies[i].split(" ")[0].split(".")[1]) * 28 +
            Number(privacies[i].split(" ")[0].split(".")[2]);

        if (today_day >= privacies_day + terms_day.get(privacies[i].split(" ")[1])) {
            answer.push(i + 1);
        }
    }

    return answer;
}
