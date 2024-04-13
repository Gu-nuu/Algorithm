#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int N, M;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

vector<vector<int>> maze;
vector<vector<vector<int>>> dist;

void BFS()
{
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {0, 0}});
    dist[0][0][0] = 1;

    while (!q.empty())
    {
        int r = q.front().second.first;
        int c = q.front().second.second;
        int wall_broken = q.front().first;
        q.pop();

        for (int d = 0; d < 4; d++)
        {
            int dr = r + dir[d][0];
            int dc = c + dir[d][1];

            if (dr >= 0 && dr < N && dc >= 0 && dc < M)
            {
                if (maze[dr][dc] == 1 && wall_broken == 0 && dist[dr][dc][1] == 0)
                {
                    dist[dr][dc][1] = dist[r][c][0] + 1;
                    q.push({1, {dr, dc}});
                }
                if (maze[dr][dc] == 0 && dist[dr][dc][wall_broken] == 0)
                {
                    dist[dr][dc][wall_broken] = dist[r][c][wall_broken] + 1;
                    q.push({wall_broken, {dr, dc}});
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    maze.assign(N, vector<int>(M));
    dist.assign(N, vector<vector<int>>(M, vector<int>(2, 0)));

    for (int i = 0; i < N; i++)
    {
        string line;
        cin >> line;
        for (int j = 0; j < M; j++)
        {
            maze[i][j] = line[j] - '0';
        }
    }

    BFS();

    int result = INT_MAX;
    if (dist[N - 1][M - 1][0] != 0)
        result = dist[N - 1][M - 1][0];

    if (dist[N - 1][M - 1][1] != 0)
        result = min(result, dist[N - 1][M - 1][1]);

    if (result == INT_MAX)
        cout << "-1\n";
    else
        cout << result << "\n";

    return 0;
}