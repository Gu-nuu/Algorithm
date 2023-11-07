#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    deque<int> dq; // 양방향 순환 큐의 연산은 덱의 연산과 같다.

    for (int i = 1; i <= N; i++) // 1부터 큐의 크기만큼의 숫자를 덱이 넣어준다.
        dq.push_back(i);

    int result = 0; // 연산 횟수를 저장할 변수

    for (int i = 0; i < M; i++)
    {
        int num;
        cin >> num;

        // 현재 뽑아내려고 하는 숫자의 인덱스 값을 덱에서 찾아 저장한다.
        int currentPos;
        for (int j = 0; j < dq.size(); j++)
        {
            if (dq[j] == num)
            {
                currentPos = j;
                break;
            }
        }
        int standard = dq.size() / 2; // 덱의 크기 값을 절반으로 나눠 기준값을 설정한다.

        // 만약 현재 뽑아내려고 하는 숫자의 인덱스 값이 기준값보다 크다면 덱의 중심에서 오른쪽에 위치한 것이기 때문에 왼쪽으로 한칸 이동시키는 2번 연산을 수행해야한다.
        // 반대로 뽑아내려고 하는 숫자의 인덱스 값이 기준값보다 작다면 덱의 중심에서 왼쪽에 위치한 것이기 때문에 오른쪽으로 한칸 이동시키는 3번 연산을 수행해야 한다.
        // 이때 첫번째 원소를 뽑아내는 1번 연산은 연산 횟수에 반영시키지 않는다.
        if (currentPos > standard)
        {
            while (dq.front() != num)
            {
                dq.push_front(dq.back());
                dq.pop_back();
                result++;
            }
            dq.pop_front();
        }
        else
        {
            while (dq.front() != num)
            {
                dq.push_back(dq.front());
                dq.pop_front();
                result++;
            }
            dq.pop_front();
        }
    }

    cout << result << "\n";

    return 0;
}