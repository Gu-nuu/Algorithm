#include <iostream>
#include <string>
#include <vector>

using namespace std;

//65 ~ 90 = 대문자 97 ~ 122 = 소문자
string solution(string s, int n)
{
    string answer = "";

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ') // 띄어쓰기는 밀어도 띄어쓰기임
            continue;

        int cnt = 0;
        while (cnt != n)
        {
            cnt++;

            if (s[i] == 122) // 소문자의 끝에 도달하면 다시 앞으로 돌려주는데 이때 'a'의 앞으로 돌려서 카운팅되도록 함
                s[i] = 96;
            else if (s[i] == 90) // 대문자의 끝에 도달하면 다시 앞으로 돌려주는데 이때 'A'의 앞으로 돌려서 카운팅되도록 함
                s[i] = 64;

            s[i] += 1;
        }
    }

    answer += s;

    return answer;
}

int main()
{
    string s = "AB";
    int n = 3;

    cout << solution(s, n) << endl;

    return 0;
}