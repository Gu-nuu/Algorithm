#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }
    else
    {
        return a.first < b.first;
    }
}

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<pair<int, int>> v; // 강의 시작 시간과 종료 시간을 저장할 벡터

    priority_queue<int, vector<int>, greater<int>> pq; // 종료 시간을 오름차순으로 정렬한 우선순위 큐

    for (int i = 0; i < N; i++)
    {
        int S, T;
        cin >> S >> T;

        v.push_back({S, T});
    }

    sort(v.begin(), v.end(), compare); // 강의 시작 시간을 기준으로 오름차순 정렬해준다.

    // 우선순위 큐에 강의 종료 시간을 push 해준 뒤, 우선순위 큐에 저장된 강의 종료 시간(top)과 벡터에 저장된 강의 시작 시간(v[i].first)를 비교한다.
    // 만약 시작 시간이 종료 시간보다 크거나 같을 경우 해당 강의는 바로 이어서 한 강의실에서 진행할 수 있는 강의이므로 이전 강의를 pop 해준다.
    // 반복문이 종료됐을 때 우선순위 큐에 남아있는 시간의 갯수가 곧 최소한의 강의실 사용 갯수가 된다.
    for (int i = 0; i < N; i++)
    {
        pq.push(v[i].second);

        if (v[i].first >= pq.top())
        {
            pq.pop();
        }
    }

    cout << pq.size() << "\n";

    return 0;
}