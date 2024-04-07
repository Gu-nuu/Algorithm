#include <iostream>
#include <vector>
#include <deque>
using namespace std;

// 오른쪽, 아래쪽, 왼쪽, 위쪽
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K, L;
    cin >> N;
    vector<vector<int>> board(N, vector<int>(N, 0));

    cin >> K;
    for (int i = 0; i < K; i++)
    {
        int apple_r, apple_c;
        cin >> apple_r >> apple_c;
        board[apple_r - 1][apple_c - 1] = 1;
    }

    cin >> L;
    vector<pair<int, char>> direction_info;
    for (int i = 0; i < L; i++)
    {
        int X;
        char C;
        cin >> X >> C;
        direction_info.push_back({X, C});
    }

    deque<pair<int, int>> snake;
    snake.push_back({0, 0});
    board[0][0] = 2;
    int time = 0;
    int d = 0;
    int idx = 0;

    while (true)
    {
        time++;

        int nr = snake.front().first + dir[d][0];
        int nc = snake.front().second + dir[d][1];

        if (nr < 0 || nr >= N || nc < 0 || nc >= N || board[nr][nc] == 2)
        {
            break;
        }
        else if (board[nr][nc] == 0)
        {
            board[nr][nc] = 2;
            snake.push_front({nr, nc});

            board[snake.back().first][snake.back().second] = 0;
            snake.pop_back();
        }
        else if (board[nr][nc] == 1)
        {
            board[nr][nc] = 2;
            snake.push_front({nr, nc});
        }

        if (idx < L)
        {
            if (time == direction_info[idx].first)
            {
                if (direction_info[idx].second == 'L')
                {
                    if (d == 0)
                    {
                        d = 3;
                    }
                    else if (d == 1)
                    {
                        d = 0;
                    }
                    else if (d == 2)
                    {
                        d = 1;
                    }
                    else if (d == 3)
                    {
                        d = 2;
                    }
                }
                else if (direction_info[idx].second == 'D')
                {
                    if (d == 0)
                    {
                        d = 1;
                    }
                    else if (d == 1)
                    {
                        d = 2;
                    }
                    else if (d == 2)
                    {
                        d = 3;
                    }
                    else if (d == 3)
                    {
                        d = 0;
                    }
                }

                idx++;
            }
        }
    }

    cout << time << "\n";

    return 0;
}