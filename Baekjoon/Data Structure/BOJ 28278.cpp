#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    stack<int> s;

    for (int i = 0; i < N; i++)
    {
        int order;
        cin >> order;

        if (order == 1)
        {
            int X;
            cin >> X;

            s.push(X);
        }
        else if (order == 2)
        {
            if (!s.empty())
            {
                cout << s.top() << "\n";
                s.pop();
            }
            else
                cout << "-1\n";
        }
        else if (order == 3)
        {
            cout << s.size() << "\n";
        }
        else if (order == 4)
        {
            if (!s.empty())
                cout << "0\n";
            else
                cout << "1\n";
        }
        else if (order == 5)
        {
            if (!s.empty())
                cout << s.top() << "\n";
            else
                cout << "-1\n";
        }
    }

    return 0;
}