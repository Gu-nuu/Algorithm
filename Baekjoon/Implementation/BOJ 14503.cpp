#include <iostream>
#include <vector>
using namespace std;

// 북, 동, 남, 서
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int N, M;

int r, c, d;

int clean = 0;

vector<vector<int>> room;

vector<vector<int>> visited;

void DFS()
{
    for (int i = 0; i < 4; i++)
    {
        int nd = (d + 3 - i) % 4;
        int nr = r + dir[nd][0];
        int nc = c + dir[nd][1];

        if (nr >= 0 && nr < N && nc >= 0 && nc < M && room[nr][nc] != 1)
        {
            if (room[nr][nc] == 0 && visited[nr][nc] == 0)
            {
                visited[nr][nc] = 1;
                room[nr][nc] = 2;
                clean++;
                d = nd;
                r = nr;
                c = nc;
                DFS();
            }
        }
    }

    int back_r = r;
    int back_c = c;

    if (d == 0)
    {
        back_r += dir[2][0];
        back_c += dir[2][1];
    }
    else if (d == 1)
    {
        back_r += dir[3][0];
        back_c += dir[3][1];
    }
    else if (d == 2)
    {
        back_r += dir[0][0];
        back_c += dir[0][1];
    }
    else if (d == 3)
    {
        back_r += dir[1][0];
        back_c += dir[1][1];
    }

    if (back_r >= 0 && back_r < N && back_c >= 0 && back_c < M)
    {
        if (room[back_r][back_c] != 1)
        {
            r = back_r;
            c = back_c;
            DFS();
        }
        else
        {
            cout << clean << "\n";
            exit(0);
        }
    }
}

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    room.resize(N, vector<int>(M, 0));

    visited.resize(N, vector<int>(M, 0));

    cin >> r >> c >> d;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> room[i][j];
        }
    }
    
    room[r][c] = 2;
    visited[r][c] = 1;
    clean++;

    DFS();

    return 0;
}