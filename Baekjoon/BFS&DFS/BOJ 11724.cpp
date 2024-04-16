#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> graph[1001];
vector<int> visited(1001, 0);

void DFS(int start)
{
    visited[start] = 1;

    for (int i = 0; i < graph[start].size(); i++)
    {
        int next_node = graph[start][i];

        if (visited[next_node] == 0)
        {
            DFS(next_node);
        }
    }
}

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int cnt = 0;

    for (int i = 1; i <= N; i++)
    {
        if (visited[i] == 0)
        {
            DFS(i);
            cnt++;
        }
    }

    cout << cnt << "\n";

    return 0;
}