#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
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

// 백준 11000 문제와 아예 같은 문제이기 때문에 똑같은 풀이 방식으로 헤결했다.
// 시작 시간과 종료 시간을 입력 받아 pair 객체로 저장한 뒤 시작 시간을 기준으로 정렬한다.
// 그 후 오름차순으로 정렬되는 우선순위 큐에 종료 시간을 하나씩 저장하면서 벡터에 저장된 시작 시간과 우선순위 큐에 저장된 종료시간을 비교한다.
// 만약 시작 시간이 종료 시간보다 크거나 같을 경우 해당 강의는 한 강의실에서 진행이 가능한 강의이므로 우선순위 큐에서 빼준다.
// 우선순위 큐에 존재하는 강의들은 곧 강의실을 사용해야 하는 강의들이므로 우선순위 큐에 저장된 시간의 갯수가 최소 강의실의 갯수가 된다.
int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<pair<int, int>> v;

    for (int i = 0; i < N; i++)
    {
        int S, T;
        cin >> S >> T;

        v.push_back({S, T});
    }

    sort(v.begin(), v.end(), compare);

    priority_queue<int, vector<int>, greater<int>> pq;

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