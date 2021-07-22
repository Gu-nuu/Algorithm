#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int var;

// sort 함수의 정렬 기준을 다시 설정. n번째 문자를 기준으로 정렬하되 만약 해당 문자가 같다면 단어 자체를 사전 순으로 정렬.
bool compare(string x, string y)
{
    if (x[var] == y[var])
        return x < y;
    else
        return x[var] < y[var];
}

vector<string> solution(vector<string> strings, int n)
{
    vector<string> answer;

    var = n;

    sort(strings.begin(), strings.end(), compare);

    for (int i = 0; i < strings.size(); i++)
        answer.push_back(strings[i]);

    return answer;
}

int main()
{
    vector<string> strings = {"sun", "bed", "car"};

    int n = 1;

    vector<string> ans = solution(strings, n);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}