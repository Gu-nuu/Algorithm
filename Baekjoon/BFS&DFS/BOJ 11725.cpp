#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> graph[100001];
vector<int> visited(100001, 0);
vector<int> ans(100001, 0);

void DFS(int start)
{
    visited[start] = 1;

    for (int i = 0; i < graph[start].size(); i++)
    {
        int next_node = graph[start][i];

        if (visited[next_node] == 0)
        {
            ans[next_node] = start;
            DFS(next_node);
        }
    }
}

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 0; i < N - 1; i++)
    {
        int from, to;
        cin >> from >> to;

        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    DFS(1);

    for (int i = 2; i <= N; i++)
    {
        cout << ans[i] << "\n";
    }

    return 0;
}