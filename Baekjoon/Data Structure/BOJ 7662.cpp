#include <iostream>
#include <set>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        // 이중 우선순위 큐의 동작 구조를 보았을 때, 최솟값과 최댓값을 바로 파악할 수 있어야 하기 때문에 미리 정렬이 되어있어야 하고
        // 자료의 맨 앞과 맨 뒤에서 삭제가 용이해야 해야 한다. 중복된 값이 들어올 수도 있기 때문에 set이 아닌 multiset을 선택했다.
        multiset<int> doublePriorityQueue;

        int k;
        cin >> k;

        for (int j = 0; j < k; j++)
        {
            char cal;
            cin >> cal;

            if (cal == 'I') // I가 들어올 경우 다음 숫자를 입력받아 multiset에 넣어준다.
            {
                int num;
                cin >> num;

                doublePriorityQueue.insert(num);
            }
            else if (cal == 'D') // D가 들어올 경우 다음 숫자가 -1인지 1인지를 입력받는다.
            {
                int priority;
                cin >> priority;

                if (!doublePriorityQueue.empty()) // 만약 multiset이 비어있다면 D 연산은 무시해야 하므로 비어있지 않을 경우에만 연산을 수행한다.
                {
                    if (priority == -1) // multiset은 기본적으로 오름차순 정렬이며 숫자가 -1일 경우 최솟값을 제거해야 하므로 맨 앞의 값을 제거해준다.
                    {
                        auto it = doublePriorityQueue.begin();
                        doublePriorityQueue.erase(it);
                    }
                    else if (priority == 1) // 숫자가 1일 경우 최댓값을 제거해야 하므로 맨 뒤의 값을 제거해준다.
                    {
                        auto it = doublePriorityQueue.end();
                        it--;
                        doublePriorityQueue.erase(it);
                    }
                }
            }
        }

        // 만약 multiset이 비어있지 않다면 최댓값과 최솟값을 출력하고 비어있다면 EMPTY를 출력한다.
        if (!doublePriorityQueue.empty())
        {
            auto it = doublePriorityQueue.end();
            it--;
            cout << *it << " ";
            it = doublePriorityQueue.begin();
            cout << *it << "\n";
        }
        else
        {
            cout << "EMPTY\n";
        }
    }

    return 0;
}