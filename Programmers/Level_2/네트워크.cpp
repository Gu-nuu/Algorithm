#include <string>
#include <vector>

using namespace std;

vector<int> visited;
int answer = 0;

void DFS(int node, vector<vector<int>> &computers)
{

    visited[node] = 1;

    for (int i = 0; i < computers[node].size(); i++)
    {
        int next_node = computers[node][i];
        if (visited[i] == 0 && next_node == 1)
        {
            DFS(i, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers)
{

    visited.assign(n, 0);

    for (int i = 0; i < visited.size(); i++)
    {
        if (visited[i] == 0)
        {
            answer++;
            DFS(i, computers);
        }
    }

    return answer;
}