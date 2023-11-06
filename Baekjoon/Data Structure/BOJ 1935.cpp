#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    string postFix; // 후위표기식을 입력받는다.
    cin >> postFix;

    stack<double> s;  // 후위표기식을 계산하기 위한 stack
    vector<double> v; // 알파벳에 해당하는 피연산자를 구하기 위한 vector

    for (int i = 0; i < N; i++) // 피연산자를 vector에 저장해준다.
    {
        double num;
        cin >> num;

        v.push_back(num);
    }

    for (int i = 0; i < postFix.size(); i++)
    {
        if (postFix[i] == '+')
        {
            double b = s.top();
            s.pop();
            double a = s.top();
            s.pop();
            s.push(a + b);
        }
        else if (postFix[i] == '-')
        {
            double b = s.top();
            s.pop();
            double a = s.top();
            s.pop();
            s.push(a - b);
        }
        else if (postFix[i] == '*')
        {
            double b = s.top();
            s.pop();
            double a = s.top();
            s.pop();
            s.push(a * b);
        }
        else if (postFix[i] == '/')
        {
            double b = s.top();
            s.pop();
            double a = s.top();
            s.pop();
            s.push(a / b);
        }
        else
        {
            // 이 부분이 중요했는데 vector에 저장되어있는 피연산자와 알파벳을 매칭시키기 위해 아스키코드를 이용하여 후위표기식의 알파벳에서 65를 빼주어
            // vector의 index 값에 접근할 수 있도록 만들었다. 이를 통해 알파벳에 따른 피연산자를 매칭한다.
            s.push(v[(int)postFix[i] - 65]);
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << s.top() << "\n";

    return 0;
}