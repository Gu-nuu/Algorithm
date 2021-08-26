#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K)
{
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> pq; // 가장 맵지 않은 음식의 스코빌 지수부터 뽑아야 하므로 최솟값부터 pop하는 우선순위 큐 생성

    for (int i = 0; i < scoville.size(); i++)
        pq.push(scoville[i]);

    while (true)
    {
        if (pq.size() == 1) // 만약 음식을 계속 섞어도 K 이상의 스코빌 지수가 나오지 않을 경우 -1을 return
        {
            answer = -1;
            break;
        }

        int first_food = pq.top();
        pq.pop();

        int second_food = pq.top();
        pq.pop();

        int mixed_food = first_food + (second_food * 2); // 가장 맵지 않은 음식의 스코빌 지수와 두 번째로 맵지 않은 음식의 스코빌 지수를 뽑아 계산 후 큐에 push
        answer++;
        pq.push(mixed_food);

        if (pq.top() >= K) // 큐에서의 top은 가장 최솟값이기 때문에 만약 top이 K 이상이면 그 외 스코빌 지수는 모두 K 이상이 된다.
            break;
    }

    return answer;
}

int main()
{
    vector<int> scoville = {1, 2, 3, 9, 10, 12};

    int K = 7;

    cout << solution(scoville, K) << endl;

    return 0;
}