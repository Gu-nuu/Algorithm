#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s)
{
    string answer = "";

    if (s.size() % 2 == 0)
    {
        answer += s[s.size() / 2 - 1];
        answer += s[s.size() / 2];
    }
    else
    {
        answer += s[s.size() / 2 + 1 - 1];
    }

    return answer;
}

int main()
{
    string str = "abqerde";

    string ans = solution(str);

    cout << ans << endl;

    return 0;
}