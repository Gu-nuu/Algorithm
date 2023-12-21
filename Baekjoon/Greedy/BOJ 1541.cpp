#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string exp;
    cin >> exp;

    string temp = "";
    bool minus = false;
    int ans = 0;

    // 그리디 알고리즘으로 문제를 접근할 때, 결국 - 부호가 나타는 시점부터 괄호를 묶게 되면 식의 결과를 최솟값으로 얻을 수 있다.
    // 따라서 문자열에서 숫자를 temp 변수에 임시로 저장하다 부호가 나타나게 되면 해당 값을 ans에 더해준다.
    // 만약 부호가 -일 경우, 해당 부분부터 괄호로 묶는다고 가정하고 - 부호 이후에 나타나는 숫자에 모두 - 부호를 붙여 더해준다.
    for (int i = 0; i < exp.size(); i++)
    {
        if (48 <= exp[i] && exp[i] <= 57)
        {
            temp += exp[i];
        }

        if (exp[i] == '+' || exp[i] == '-' || i == exp.size() - 1)
        {
            if (minus)
            {
                ans += (-stoi(temp));
            }
            else
            {
                ans += stoi(temp);
            }

            temp.clear();
        }

        if (exp[i] == '-')
        {
            minus = true;
        }
    }

    cout << ans << "\n";

    return 0;
}