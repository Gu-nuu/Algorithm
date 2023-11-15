#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string infix;
    cin >> infix;

    string postfix = "";

    stack<char> s;

    // 문제에서 고려해야 할 연산 기호들은 크게 +, -와 *, /와 괄호로 총 3가지가 있다.
    // 1. 알파벳 대문자인 경우 후위 표기식은 피연산자가 앞에 나오기 때문에 바로 출력한다.
    // 2. '('가 나왔을 경우 스택에 똑같이 넣어준다. 괄호로 인해 연산자의 우선순위가 바뀔 수 있기 때문이다.
    // 3. '*'. '/'가 나왔을 경우 스택의 top이 '*'. '/'인 경우에만 출력하고 현재 연산자를 스택에 넣는다. '*'. '/'는 괄호를 제외한 연산자보다 우선순위가 제일 높기 때문에 앞에 나온 '*'. '/'가 아니라면 출력하지 않는다.
    // 4. '+', '-'가 나왔을 경우 스택의 top이 '('인 경우를 제외하고 모두 출력하고 현재 연산자를 스택에 넣는다. '+', '-'는 모든 연산자들 중에서 우선순위가 제일 낮기 때문에 괄호를 제외하고는 스택의 가장 아래에 들어가야 한다.
    // 5. ')'가 나왔을 경우 '('이 나올 때까지 모든 연산자들을 출력한다.
    // 위 조건들로 입력받은 중위 표기식의 길이만큼 반복한 뒤 스택에 남은 연산자들을 출력하여 후위 표기식을 만들 수 있다.
    for (int i = 0; i < infix.size(); i++)
    {
        if (infix[i] >= 'A' && infix[i] <= 'Z')
        {
            postfix += infix[i];
        }
        else if (infix[i] == '(')
        {
            s.push(infix[i]);
        }
        else if (infix[i] == '*' || infix[i] == '/')
        {
            while (!s.empty() && (s.top() == '*' || s.top() == '/'))
            {
                postfix += s.top();
                s.pop();
            }

            s.push(infix[i]);
        }
        else if (infix[i] == '+' || infix[i] == '-')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }

            s.push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }

            s.pop();
        }
    }

    while (!s.empty())
    {
        postfix += s.top();
        s.pop();
    }

    cout << postfix << "\n";

    return 0;
}