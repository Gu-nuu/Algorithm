#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    if (s.size() != 4 && s.size() != 6) // 문자열의 길이는 4이거나 6이어야만 함
        answer = false;

    for (int i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i]) == 0) //isdigit 함수의 return 값이 0이면 숫자가 아닌 수라는 의미임
        {
            answer = false;
            break;
        }
    }

    return answer;
}

int main()
{
    string s = "a234";

    cout << solution(s) << endl;

    return 0;
}