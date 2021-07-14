#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    string answer = "";

    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end()); // 참가자와 완주자를 같은 인덱스로 비교하기 위해 정렬

    int i;
    int flag = 0; // 중간에 완주자가 아닌 사람이 나올 경우와 정렬을 진행 후 완주자가 아닌 사람이 가장 끝에 있을 경우를 고려
    for (i = 0; i < completion.size(); i++)
    {
        if (completion[i] != participant[i]) // 참가자와 완주자를 정렬 후 같은 인덱스로 비교하는데 다른 이름이 나온다면 참가자이지만 완주자는 아님
        {
            flag = 1;
            break;
        }
    }

    if (flag == 1)
        answer += participant[i]; //중간에 참가자이지만 완주자가 아닌 사람이 나온 경우
    else
        answer += participant[participant.size() - 1]; // 끝까지 탐색 후 맨 뒤에 참가자이지만 완주자가 아닌 사람이 나온 경우

    return answer;
}

int main()
{
    vector<string> part = {"leo", "kiki", "eden"};
    vector<string> comp = {"eden", "kiki"};

    string answer = solution(part, comp);

    cout << answer << endl;

    return 0;
}