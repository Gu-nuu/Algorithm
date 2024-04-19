#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int R, C;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<vector<char>> board;
vector<vector<int>> visited;
vector<bool> alphabet;
int ans;

void DFS(int start_r, int start_c, int pass)
{
    ans = max(ans, pass);
    int r = start_r;
    int c = start_c;

    visited[r][c] = 1;
    alphabet[board[r][c] - 'A'] = true;

    for (int d = 0; d < 4; d++)
    {
        int dr = r + dir[d][0];
        int dc = c + dir[d][1];
        if (dr >= 0 && dr < R && dc >= 0 && dc < C && visited[dr][dc] == 0 && alphabet[board[dr][dc] - 'A'] == false)
        {
            visited[dr][dc] = 1;
            alphabet[board[dr][dc] - 'A'] = true;
            DFS(dr, dc, pass + 1);
            visited[dr][dc] = 0;
            alphabet[board[dr][dc] - 'A'] = false;
        }
    }
}

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C;

    board.assign(R, vector<char>(C, 'A'));
    visited.assign(R, vector<int>(C, 0));
    alphabet.assign(26, false);

    for (int i = 0; i < R; i++)
    {
        string input;
        cin >> input;
        for (int j = 0; j < C; j++)
        {
            board[i][j] = input[j];
        }
    }

    DFS(0, 0, 1);

    cout << ans << "\n";

    return 0;
}