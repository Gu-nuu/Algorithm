#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int M, N, K;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<vector<int>> paper;
vector<vector<int>> visited;
int area_count = 0;
int area_num = 0;
vector<int> area;

void DFS(int start_r, int start_c)
{
    area_num++;

    int r = start_r;
    int c = start_c;

    visited[r][c] = 1;

    for (int d = 0; d < 4; d++)
    {
        int dr = r + dir[d][0];
        int dc = c + dir[d][1];

        if (dr >= 0 && dr < M && dc >= 0 && dc < N && paper[dr][dc] == 0 && visited[dr][dc] == 0)
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

    cin >> M >> N >> K;

    paper.assign(M, vector<int>(N, 0));
    visited.assign(M, vector<int>(N, 0));

    for (int i = 0; i < K; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int r = y1; r < y2; r++)
        {
            for (int c = x1; c < x2; c++)
            {
                paper[r][c] = 1;
                visited[r][c] = 1;
            }
        }
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (paper[i][j] == 0 && visited[i][j] == 0)
            {
                DFS(i, j);
                area.push_back(area_num);
                area_num = 0;
                area_count++;
            }
        }
    }

    sort(area.begin(), area.end());

    cout << area_count << "\n";
    for (int i = 0; i < area.size(); i++)
    {
        cout << area[i];

        if (i == area.size() - 1)
        {
            cout << "\n";
        }
        else
        {
            cout << " ";
        }
    }

    return 0;
}