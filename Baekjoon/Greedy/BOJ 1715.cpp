#include <iostream>
#include <queue>
using namespace std;

// 그리디 알고리즘의 관점에서 문제를 해결하기 위해서는 가장 작은 카드 더미끼리 비교를 하고 계속해서 그 다음으로 작은 카드 더미와의 비교를 반복해야 함을 알 수 있다.
// 따라서 우선순위 큐을 오름차순 정렬로 만들어준 뒤 우선순위 큐 가장 위에 있는 가장 작은 카드 더미 2개를 서로 비교하고 만들어진 새로운 카드 더미를 우선순위 큐에 삽입함으로써
// 계속해서 작은 카드 더미끼리 비교해나갈 수 있도록 했다.
int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < N; i++)
    {
        int numberCard;
        cin >> numberCard;

        pq.push(numberCard);
    }

    int result = 0;

    while (1)
    {
        if (pq.size() == 1) // 만약 카드 더미가 하나만 남게 되면 모든 카드 더미끼리의 비교가 끝난 후 하나로 합쳐진 것이므로 반복문을 종료한다.
        {
            pq.pop();
            break;
        }

        int dummy1 = pq.top();
        pq.pop();
        int dummy2 = pq.top();
        pq.pop();

        result += (dummy1 + dummy2); // 카드 더미끼리 비교한 횟수를 결과 값에 저장한다.

        pq.push(dummy1 + dummy2); // 두 카드 더미를 합쳐 나온 카드 묶음을 우선순위 큐에 새로 저장한다.
    }

    cout << result << "\n";

    return 0;
}