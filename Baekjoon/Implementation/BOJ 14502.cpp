#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

int N, M;

int dir[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

int safe_area = INT_MIN;

void BFS(vector<vector<int>> &infection)
{
    queue<pair<int, int>> q;

    for (int i = 0; i < infection.size(); i++)
    {
        for (int j = 0; j < infection[i].size(); j++)
        {
            if (infection[i][j] == 2)
            {
                q.push({i, j});
            }
        }
    }

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int d = 0; d < 4; d++)
        {
            int dx = x + dir[d][0];
            int dy = y + dir[d][1];

            if (dx >= 0 && dx < N && dy >= 0 && dy < M)
            {
                if (infection[dx][dy] == 0)
                {
                    infection[dx][dy] = 2;
                    q.push({dx, dy});
                }
            }
        }
    }

    int cnt = 0;

    for (int i = 0; i < infection.size(); i++)
    {
        for (int j = 0; j < infection[i].size(); j++)
        {
            if (infection[i][j] == 0)
            {
                cnt++;
            }
        }
    }

    safe_area = max(safe_area, cnt);
}

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    vector<vector<int>> lab(N, vector<int>(M, -1));
    vector<pair<int, int>> blank;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> lab[i][j];

            if (lab[i][j] == 0)
            {
                blank.push_back({i, j});
            }
        }
    }

    vector<int> box(blank.size(), 0);
    for (int i = 0; i < 3; i++)
    {
        box[i] = 1;
    }

    sort(box.begin(), box.end());

    do
    {
        vector<vector<int>> copy_lab(lab);

        for (int i = 0; i < box.size(); i++)
        {
            if (box[i] == 1)
            {
                copy_lab[blank[i].first][blank[i].second] = 1;
            }
        }

        BFS(copy_lab);

    } while (next_permutation(box.begin(), box.end()));

    cout << safe_area << "\n";

    return 0;
}