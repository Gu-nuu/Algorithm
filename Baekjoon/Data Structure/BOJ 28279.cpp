#include <iostream>
#include <deque>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    deque<int> dq;

    for (int i = 0; i < N; i++)
    {
        int order;
        cin >> order;

        if (order == 1)
        {
            int X;
            cin >> X;
            dq.push_front(X);
        }
        else if (order == 2)
        {
            int X;
            cin >> X;
            dq.push_back(X);
        }
        else if (order == 3)
        {
            if (!dq.empty())
            {
                cout << dq.front() << "\n";
                dq.pop_front();
            }
            else
                cout << "-1\n";
        }
        else if (order == 4)
        {
            if (!dq.empty())
            {
                cout << dq.back() << "\n";
                dq.pop_back();
            }
            else
                cout << "-1\n";
        }
        else if (order == 5)
        {
            cout << dq.size() << "\n";
        }
        else if (order == 6)
        {
            if (!dq.empty())
                cout << "0\n";
            else
                cout << "1\n";
        }
        else if (order == 7)
        {
            if (!dq.empty())
                cout << dq.front() << "\n";
            else
                cout << "-1\n";
        }
        else if (order == 8)
        {
            if (!dq.empty())
                cout << dq.back() << "\n";
            else
                cout << "-1\n";
        }
    }

    return 0;
}