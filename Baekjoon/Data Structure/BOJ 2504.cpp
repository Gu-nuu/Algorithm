#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string line;
    cin >> line;

    stack<char> bracket;

    int ans = 0;         // 괄호값을 저장할 변수
    int temp = 1;        // 계산에 활용되는 변수
    bool balance = true; // 올바른 괄호열인지 아닌지를 판단하는 변수

    for (int i = 0; i < line.size(); i++)
    {
        if (line[i] == '(') // 만약 소괄호가 나오면 소괄호의 괄호값은 2이므로 임시 계산 변수 temp에 2를 곱해준다.
        {
            bracket.push(line[i]);
            temp *= 2;
        }
        else if (line[i] == '[') // 만약 대괄호가 나오면 대괄호의 괄호값은 3이므로 임시 계산 변수 temp에 3을 곱해준다.
        {
            bracket.push(line[i]);
            temp *= 3;
        }
        // 만약 닫는 소괄호가 나왔을 경우 크게 2가지의 경우가 있다.
        // 만약 괄호를 담는 stack이 비어있거나 바로 앞의 괄호가 여는 대괄호일 경우 올바르지 않은 괄호열이기 때문에 balance를 false로 바꾸고 반복문을 탈출한다.
        // 만약 바로 앞의 괄호가 여는 소괄호인 경우에는 현재까지의 계산값을 ans에 더해준뒤, 임시 계산 변수 temp를 2로 나눈 후 stack을 한번 pop 한다.
        // () 한 쌍의 괄호가 만들어진 것이기 때문에 stack에서 괄호 하나를 지워주고, 임시 변수 값을 2로 나눠 한 쌍의 괄호에 대한 계산을 끝냈음을 의미한다.
        // 바로 앞의 괄호가 여는 소괄호가 아닌 경우는 닫는 소괄호 또는 닫는 대괄호가 나오는 경우인데 이 경우에는 아직 한 쌍의 괄호에 대한 계산이 아직 끝난 것이 아니므로
        // ans에 계산 값을 더해주지 않고 임시 계산 변수를 2로 나눠준다. 이때 하나의 괄호는 쌍을 이루게 되므로 stack을 한번 pop 한다.
        else if (line[i] == ')')
        {
            if (bracket.empty() || bracket.top() == '[')
            {
                balance = false;
                break;
            }
            else
            {
                if (line[i - 1] == '(')
                {
                    ans += temp;
                    temp /= 2;
                    bracket.pop();
                }
                else
                {
                    temp /= 2;
                    bracket.pop();
                }
            }
        }
        // 만약 닫는 대괄호가 나왔을 경우에도 크게 2가지의 경우가 있다.
        // 만약 괄호를 담는 stack이 비어있거나 바로 앞의 괄호가 여는 소괄호일 경우 올바르지 않은 괄호열이기 때문에 balance를 false로 바꾸고 반복문을 탈출한다.
        // 만약 바로 앞의 괄호가 여는 대괄호인 경우에는 현재까지의 계산값을 ans에 더해준뒤, 임시 계산 변수 temp를 3으로 나눈 후 stack을 한번 pop 한다.
        // [] 한 쌍의 괄호가 만들어진 것이기 때문에 stack에서 괄호 하나를 지워주고, 임시 변수 값을 3으로 나눠 한 쌍의 괄호에 대한 계산을 끝냈음을 의미한다.
        // 바로 앞의 괄호가 여는 대괄호가 아닌 경우는 닫는 소괄호 또는 닫는 대괄호가 나오는 경우인데 이 경우에는 아직 한 쌍의 괄호에 대한 계산이 아직 끝난 것이 아니므로
        // ans에 계산 값을 더해주지 않고 임시 계산 변수를 3으로 나눠준다. 이때 하나의 괄호는 쌍을 이루게 되므로 stack을 한번 pop 한다.
        else if (line[i] == ']')
        {
            if (bracket.empty() || bracket.top() == '(')
            {
                balance = false;
                break;
            }
            else
            {
                if (line[i - 1] == '[')
                {
                    ans += temp;
                    temp /= 3;
                    bracket.pop();
                }
                else
                {
                    temp /= 3;
                    bracket.pop();
                }
            }
        }
    }

    if (!balance || !bracket.empty()) // 만약 balance가 false이거나 괄호열에 있는 모든 계산이 끝났음에도 stack이 비어있지 않다면 이는 올바르지 않은 괄호열이다.
        cout << "0\n";
    else
        cout << ans << "\n";

    return 0;
}