#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    queue<int> q;

    for (int i = 0; i < N; i++)
    {
        string order;
        cin >> order;

        if (order == "push")
        {
            int X;
            cin >> X;
            q.push(X);
        }
        else if (order == "pop")
        {
            if (!q.empty())
            {
                cout << q.front() << "\n";
                q.pop();
            }
            else
                cout << "-1\n";
        }
        else if (order == "size")
        {
            cout << q.size() << "\n";
        }
        else if (order == "empty")
        {
            if (!q.empty())
                cout << "0\n";
            else
                cout << "1\n";
        }
        else if (order == "front")
        {
            if (!q.empty())
                cout << q.front() << "\n";
            else
                cout << "-1\n";
        }
        else if (order == "back")
        {
            if (!q.empty())
                cout << q.back() << "\n";
            else
                cout << "-1\n";
        }
    }

    return 0;
}