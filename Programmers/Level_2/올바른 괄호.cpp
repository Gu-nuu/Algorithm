#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    stack<int> check; // 스택을 이용하여 '('가 나타나면 특정 값을 push하고 ')'가 나타나면 스택에서 pop해서 올바른 괄호 한쌍을 확인하도록 했다.

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            check.push(1);
        else if (s[i] == ')')
        {
            if (check.empty())
            {
                answer = false;
                break;
            }
            else
                check.pop();
        }
    }

    // 올바른 괄호가 아닐 경우는 이미 괄호가 모두 바르게 짝지어졌는데 ')'가 나타나는 경우, 즉 스택이 비어있는데 또 pop을 하는 경우와
    // 모든 괄호에 대한 검사가 끝났는데 '('의 여분 괄호가 남는 경우, 즉 모든 반복문이 끝나도 스택이 비어있지 않은 경우이다.
    if (!check.empty() || answer == false)
        return false;
    else
        return true;
}

int main()
{
    string s = "()()";

    cout << solution(s) << endl;

    return 0;
}