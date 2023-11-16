#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    // 처음에는 set 자료구조를 이용하여 모든 수를 다 저장하고 N번째로 큰 수를 출력하려고 했는데 이 경우 메모리 초과 오류가 나게 된다.
    // 따라서 우선순위 큐를 이용해 오름차순으로 수를 정렬해주고 큐의 크기를 N으로 유지하면서 가장 작은 수를 제거해주면
    // 우선순위 큐의 top에는 N번째로 큰 숫자가 나오게 된다.
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int num;
            cin >> num;

            pq.push(num);

            while (pq.size() > N)
            {
                pq.pop();
            }
        }
    }

    cout << pq.top() << "\n";

    return 0;
}