#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    int answer = 0;

    if (s[0] == '+')
    {
        s.erase(s.begin());
        answer = stoi(s); // 앞에 부호를 지우고 stoi 함수를 이용하여 string을 한 번에 변환
    }
    else if (s[0] == '-')
    {
        s.erase(s.begin());
        answer = stoi(s);
        answer = -answer; // 앞에 부호를 지우고 stoi 함수를 이용하여 string을 한 번에 변환 후 -를 붙여줌
    }
    else
        answer = stoi(s); // 부호가 없을 경우 단순 양수

    return answer;
}

int main()
{
    string str = "-1234";

    cout << solution(str) << endl;

    return 0;
}