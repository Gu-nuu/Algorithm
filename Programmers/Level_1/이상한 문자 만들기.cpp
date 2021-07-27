#include <iostream>
#include <string>

using namespace std;

string solution(string s)
{
    string answer = "";

    int cnt = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ') // 공백이면 아래 코드를 실행하지 않고 넘어간다. 이때, 문자의 짝/홀수 인덱스를 결정하는 cnt는 0으로 초기화
        {
            cnt = 0;
            continue;
        }

        if (cnt % 2 == 0 && s[i] != ' ') // 공백이 아니면서 인덱스가 짝수라면 대문자로 변환
        {
            s[i] = toupper(s[i]);
        }
        else if (cnt % 2 == 1 && s[i] != ' ') // 공백이 아니면서 인덱스가 홀수라면 소문자로 변환
        {
            s[i] = tolower(s[i]);
        }

        cnt++; // 문자의 인덱스 값을 증가시켜줌
    }

    answer = s;

    return answer;
}

int main()
{
    string s = "try hello world";

    cout << solution(s) << endl;

    return 0;
}