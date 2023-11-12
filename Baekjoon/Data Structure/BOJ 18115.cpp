#include <iostream>
#include <deque>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<int> after; // 기술을 모두 사용한 후의 카드 상태를 저장할 vector

    for (int i = 0; i < N; i++)
    {
        after.push_back(i + 1);
    }

    stack<int> techniques; // 사용한 기술들을 저장할 stack. 초기 카드 상태를 구하기 위해서는 기술을 역순으로 보면서 카드에 적용시켜줘야하기 때문에 후입선출인 stack을 사용했다.

    for (int i = 0; i < N; i++)
    {
        int tech;
        cin >> tech;
        techniques.push(tech);
    }

    deque<int> before; // 초기 카드 상태를 저장할 deque. 앞 뒤로 카드의 삽입이 일어나기 때문에 deque를 사용했다.

    int cnt = 0;

    while (!techniques.empty())
    {
        if (techniques.top() == 1) // 1번 기술을 사용했을 경우 현재 카드를 맨 앞으로 옮겨준다.
        {
            before.push_front(after[cnt]);
        }
        else if (techniques.top() == 2) // 2번 기술을 사용했을 경우 현재 카드를 맨 앞에서 두번째에 위치하도록 옮겨준다.
        {
            int temp = before.front();
            before.pop_front();
            before.push_front(after[cnt]);
            before.push_front(temp);
        }
        else if (techniques.top() == 3) // 3번 기술을 사용했을 경우 현재 카드를 맨 뒤로 옮겨준다.
        {
            before.push_back(after[cnt]);
        }

        techniques.pop();
        cnt++;
    }

    for (int i = 0; i < before.size(); i++)
    {
        cout << before[i];

        if (i == before.size() - 1)
            cout << "\n";
        else
            cout << " ";
    }

    return 0;
}