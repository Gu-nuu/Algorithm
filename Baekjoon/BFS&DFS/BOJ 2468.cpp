#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int N;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<vector<int>> area;
vector<vector<int>> visited;

void DFS(int start_r, int start_c, int height)
{
    int r = start_r;
    int c = start_c;

    visited[r][c] = 1;

    for (int d = 0; d < 4; d++)
    {
        int dr = r + dir[d][0];
        int dc = c + dir[d][1];

        if (dr >= 0 && dr < N && dc >= 0 && dc < N && visited[dr][dc] == 0 && area[dr][dc] > height)
        {
            visited[dr][dc] = 1;
            DFS(dr, dc, height);
        }
    }
}

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    area.assign(N, vector<int>(N, 0));
    visited.assign(N, vector<int>(N, 0));
    set<int> height;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> area[i][j];
            height.insert(area[i][j]);
        }
    }

    auto maxHeight = *height.rbegin();

    vector<int> select_cnt;

    for (int h = 0; h <= maxHeight; h++)
    {
        visited.assign(N, vector<int>(N, 0));
        int cnt = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (visited[i][j] == 0 && area[i][j] > h)
                {
                    DFS(i, j, h);
                    cnt++;
                }
            }
        }
        select_cnt.push_back(cnt);
    }

    sort(select_cnt.begin(), select_cnt.end());
    cout << *select_cnt.rbegin() << "\n";

    return 0;
}