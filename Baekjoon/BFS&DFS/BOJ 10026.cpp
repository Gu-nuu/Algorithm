#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<vector<char>> grid;
vector<vector<char>> grid_abnormal;
vector<vector<int>> visited;

void DFS(int start_r, int start_c, char state)
{
    int r = start_r;
    int c = start_c;

    visited[r][c] = 1;

    for (int d = 0; d < 4; d++)
    {
        int dr = r + dir[d][0];
        int dc = c + dir[d][1];

        if (dr >= 0 && dr < N && dc >= 0 && dc < N && visited[dr][dc] == 0 && grid[dr][dc] == state)
        {
            visited[dr][dc] = 1;
            DFS(dr, dc, state);
        }
    }
}

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    grid.assign(N, vector<char>(N, 'R'));
    grid_abnormal.assign(N, vector<char>(N, 'R'));
    visited.assign(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++)
    {
        string input;
        cin >> input;

        for (int j = 0; j < N; j++)
        {
            grid[i][j] = input[j];

            if (input[j] != 'G')
            {
                grid_abnormal[i][j] = input[j];
            }
        }
    }

    int normal_cnt = 0;
    int abnormal_cnt = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (visited[i][j] == 0)
            {
                DFS(i, j, grid[i][j]);
                normal_cnt++;
            }
        }
    }

    visited.assign(N, vector<int>(N, 0));
    grid = grid_abnormal;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (visited[i][j] == 0)
            {
                DFS(i, j, grid[i][j]);
                abnormal_cnt++;
            }
        }
    }

    cout << normal_cnt << " " << abnormal_cnt << "\n";

    return 0;
}