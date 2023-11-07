#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string bracketExp;
    cin >> bracketExp;

    stack<int> s;

    int cnt = 0; // 잘린 쇠막대기의 갯수를 저장하는 변수

    // ( 인 경우에는 막대기의 시작이므로 stack에 push 해준다.
    // ) 인 경우 2가지의 케이스로 나뉘게 된다.
    // ) 앞의 문자가 ( 인 경우[1]와 ) 앞의 문자가 똑같이 ) 인 경우[2]이다.
    // [1]의 경우 ()가 완성이 되므로 레이저가 된다. 이때, stack에 들어있는 값의 갯수들은 현재 막대기의 갯수가 되며
    // 레이저로 이를 자를 경우 얻을 수 있는 막대기의 갯수가 된다. 따라서 stack의 크기만큼 쇠막대기의 갯수로 추가해준다.
    // 이때 주의할 점은 레이저는 ()로 표현되므로 pop을 한번 진행해준 뒤에 stack의 크기를 더해줘야 한다.
    // [2]의 경우 레이저가 아니라 막대기의 끝이 표현되는 경우이다. 이 경우 해당 부위에서 막대기 하나만 잘린 것이기 때문에 쇠막대기의 갯수에 +1을 해준다.
    // 이때 주의할 점은 막대기가 하나가 다 잘리고 끝난 것이므로 pop을 먼저 해주고 +1을 해줘야 한다.
    for (int i = 0; i < bracketExp.size(); i++)
    {
        if (bracketExp[i] == '(')
        {
            s.push(1);
        }
        else if (bracketExp[i] == ')')
        {
            if (bracketExp[i - 1] == '(')
            {
                s.pop();
                cnt += s.size();
            }
            else
            {
                s.pop();
                cnt += 1;
            }
        }
    }

    cout << cnt << "\n";

    return 0;
}