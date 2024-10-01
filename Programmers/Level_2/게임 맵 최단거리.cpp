#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> isVisited;
vector<vector<int>> copyMap;
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int N, M;

void BFS(int start_r, int start_c)
{

    queue<pair<int, int>> q;
    q.push({start_r, start_c});
    isVisited[start_r][start_c] = 1;

    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int d = 0; d < 4; d++)
        {
            int dr = r + dir[d][0];
            int dc = c + dir[d][1];

            if (dr >= 0 && dr < N && dc >= 0 && dc < M && copyMap[dr][dc] == 1 && isVisited[dr][dc] == 0)
            {
                isVisited[dr][dc] = 1;
                copyMap[dr][dc] = copyMap[r][c] + 1;
                q.push({dr, dc});
            }
        }
    }
}

int solution(vector<vector<int>> maps)
{
    int answer = 0;

    N = maps.size();
    M = maps[0].size();
    isVisited.assign(N, vector<int>(M, 0));
    copyMap = maps;

    BFS(0, 0);

    if (copyMap[N - 1][M - 1] == 1)
    {
        answer = -1;
    }
    else
    {
        answer = copyMap[N - 1][M - 1];
    }

    return answer;
}