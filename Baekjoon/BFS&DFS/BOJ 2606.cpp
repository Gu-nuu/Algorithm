#include <iostream>
#include <vector>
using namespace std;

int computers, conntected;
int cnt;
vector<int> network[101];
vector<int> visited(101, 0);

void DFS(int start)
{
    visited[start] = 1;

    for (int i = 0; i < network[start].size(); i++)
    {
        int next_node = network[start][i];
        if (visited[next_node] == 0)
        {
            cnt++;
            DFS(next_node);
        }
    }
}

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> computers;
    cin >> conntected;

    for (int i = 0; i < conntected; i++)
    {
        int from, to;
        cin >> from >> to;

        network[from].push_back(to);
        network[to].push_back(from);
    }

    DFS(1);

    cout << cnt << "\n";

    return 0;
}