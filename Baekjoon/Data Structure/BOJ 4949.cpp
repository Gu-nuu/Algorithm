#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    stack<char> bracket;

    while (1)
    {
        string sentence;
        getline(cin, sentence, '.');

        // getline 함수에서 '.'을 제한자를 문자열을 구분했기 때문에 제한자 전까지의 문자열이 string으로 저장된다.
        // 따라서 온점 하나만 들어올 경우 저장된 string의 길이는 0이 되고 이는 곧 테스트 케이스 입력의 종료이므로 문자열 길이가 0일 경우를 종료 조건으로 설정한다.
        if (sentence.size() == 0)
            break;

        bool balance = true; // 균형이 맞는지 아닌지 판단하는 변수

        for (int i = 0; i < sentence.size(); i++)
        {
            if (sentence[i] == '(' || sentence[i] == '[') // 만약 열린 괄호가 나오면 소괄호든 대괄호든 스택에 넣어준다.
                bracket.push(sentence[i]);
            else if (sentence[i] == ')')
            {
                // 닫는 소괄호가 나왔을 경우,
                // 1. 스택이 비어있는지를 확인한다. 올바른 닫는 소괄호의 경우 열린 소괄호가 먼저 들어왔어야 하므로 스택이 비어있지 않아야 올바른 닫는 소괄호이다.
                // 2. 닫는 소괄호 바로 이전에 들어온 소괄호가 열린 소괄호인지 확인한다. 만약 열린 대괄호가 들어와 있을 경우 이는 올바르지 않은 소괄호이기 때문이다.
                // 위 두 조건을 모두 만족할 경우 스택을 pop 해주고 만약 조건을 만족하지 않는다면 균형을 이루지 않는 것이므로 balance를 false로 설정한 뒤 반복문을 탈출한다.
                if (!bracket.empty() && bracket.top() == '(')
                    bracket.pop();
                else
                {
                    balance = false;
                    break;
                }
            }
            else if (sentence[i] == ']')
            {
                // 닫는 대괄호가 나왔을 경우,
                // 1. 스택이 비어있는지를 확인한다. 올바른 닫는 대괄호의 경우 열린 대괄호가 먼저 들어왔어야 하므로 스택이 비어있지 않아야 올바른 닫는 대괄호이다.
                // 2. 닫는 대괄호 바로 이전에 들어온 대괄호가 열린 대괄호인지 확인한다. 만약 열린 소괄호가 들어와 있을 경우 이는 올바르지 않은 대괄호이기 때문이다.
                // 위 두 조건을 모두 만족할 경우 스택을 pop 해주고 만약 조건을 만족하지 않는다면 균형을 이루지 않는 것이므로 balance를 false로 설정한 뒤 반복문을 탈출한다.
                if (!bracket.empty() && bracket.top() == '[')
                    bracket.pop();
                else
                {
                    balance = false;
                    break;
                }
            }
        }

        if (bracket.empty() && balance)
            cout << "yes\n";
        else
            cout << "no\n";

        while (!bracket.empty()) // 다음 문자열 검사를 위해 스택을 비워준다.
            bracket.pop();

        cin.ignore(); // getline으로 문자열을 계속 입력받게 되면 버퍼에 남아있는 "\n"가 다음 입력으로 넘어가게 되어 오류가 발생하게 되므로 ignore() 함수를 통해 이를 방지한다.
    }

    return 0;
}