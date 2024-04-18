#include <iostream>
#include <vector>
using namespace std;

int w, h;
int dir[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
vector<vector<int>> map;
vector<vector<int>> visited;
vector<int> ans;

void DFS(int start_r, int start_c)
{
    int r = start_r;
    int c = start_c;
    visited[r][c] = 1;

    for (int d = 0; d < 8; d++)
    {
        int dr = r + dir[d][0];
        int dc = c + dir[d][1];

        if (dr >= 0 && dr < h && dc >= 0 && dc < w && map[dr][dc] == 1 && visited[dr][dc] == 0)
        {
            visited[dr][dc] = 1;
            DFS(dr, dc);
        }
    }
}

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while (true)
    {
        cin >> w >> h;

        if (w == 0 && h == 0)
        {
            break;
        }
        else
        {
            map.assign(h, vector<int>(w, 0));
            visited.assign(h, vector<int>(w, 0));
            int cnt = 0;

            for (int i = 0; i < h; i++)
            {
                for (int j = 0; j < w; j++)
                {
                    cin >> map[i][j];
                }
            }

            for (int i = 0; i < h; i++)
            {
                for (int j = 0; j < w; j++)
                {
                    if (visited[i][j] == 0 && map[i][j] == 1)
                    {
                        DFS(i, j);
                        cnt++;
                    }
                }
            }

            ans.push_back(cnt);
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << "\n";
    }

    return 0;
}