#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

int M, N;

// 상, 하, 좌, 우
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

vector<vector<int>> box;

queue<pair<int, int>> q;

void BFS()
{
    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int d = 0; d < 4; d++)
        {
            int dr = r + dir[d][0];
            int dc = c + dir[d][1];

            if (dr >= 0 && dr < M && dc >= 0 && dc < N && box[dr][dc] == 0)
            {
                box[dr][dc] = box[r][c] + 1;
                q.push({dr, dc});
            }
        }
    }
}

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    bool allRipen = true;

    for (int i = 0; i < M; i++)
    {
        vector<int> temp;
        for (int j = 0; j < N; j++)
        {
            int temp_num;
            cin >> temp_num;
            temp.push_back(temp_num);

            if (temp_num == 0)
            {
                allRipen = false;
            }
            else if (temp_num == 1)
            {
                q.push({i, j});
            }
        }

        box.push_back(temp);
    }

    if (allRipen)
    {
        cout << "0\n";
    }
    else
    {
        BFS();

        bool cannotRipen = false;

        int max_days = INT_MIN;

        for (int i = 0; i < box.size(); i++)
        {
            for (int j = 0; j < box[i].size(); j++)
            {
                if (max_days < box[i][j])
                {
                    max_days = box[i][j];
                }

                if (box[i][j] == 0)
                {
                    cannotRipen = true;
                    break;
                }
            }

            if (cannotRipen)
            {
                max_days = 0;
                break;
            }
        }

        cout << max_days - 1 << "\n";
    }

    return 0;
}