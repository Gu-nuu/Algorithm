#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

int N;
vector<vector<int>> map;
vector<vector<int>> isVisited;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<int> obstacle;

void BFS(int start_r, int start_c)
{
    queue<pair<int, int>> q;

    isVisited[start_r][start_c] = 1;

    int area = 1;

    q.push({start_r, start_c});

    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int d = 0; d < 4; d++)
        {
            int dr = r + dir[d][0];
            int dc = c + dir[d][1];

            if (dr >= 0 && dr < N && dc >= 0 && dc < N && map[dr][dc] == 1 && isVisited[dr][dc] == 0)
            {
                isVisited[dr][dc] = 1;
                area++;
                q.push({dr, dc});
            }
        }
    }

    obstacle.push_back(area);
}

int main(int argc, char **argv)
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    map.assign(N, vector<int>(N, 0));
    isVisited.assign(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++)
    {
        string input;
        cin >> input;

        for (int j = 0; j < N; j++)
        {
            map[i][j] = input[j] - '0';
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (map[i][j] == 1 && isVisited[i][j] == 0)
            {
                BFS(i, j);
            }
        }
    }

    sort(obstacle.begin(), obstacle.end());

    cout << obstacle.size() << "\n";
    for (int i = 0; i < obstacle.size(); i++)
    {
        cout << obstacle[i] << "\n";
    }

    return 0;
}