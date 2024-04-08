#include <iostream>
#include <vector>
using namespace std;

// 동, 서, 북, 남
int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

// top[0], back[1], right[2], left[3], front[4], bottom[5]
int dice[6] = {0, 0, 0, 0, 0, 0};

void rollDice(int num)
{
    int temp;

    if (num == 1) // 동쪽으로
    {
        temp = dice[0];
        dice[0] = dice[3];
        dice[3] = dice[5];
        dice[5] = dice[2];
        dice[2] = temp;
    }
    else if (num == 2) // 서쪽으로
    {
        temp = dice[0];
        dice[0] = dice[2];
        dice[2] = dice[5];
        dice[5] = dice[3];
        dice[3] = temp;
    }
    else if (num == 3) // 북쪽으로
    {
        temp = dice[0];
        dice[0] = dice[4];
        dice[4] = dice[5];
        dice[5] = dice[1];
        dice[1] = temp;
    }
    else if (num == 4) // 남쪽으로
    {
        temp = dice[0];
        dice[0] = dice[1];
        dice[1] = dice[5];
        dice[5] = dice[4];
        dice[4] = temp;
    }
}

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M, x, y, k;

    cin >> N >> M >> x >> y >> k;

    vector<vector<int>> map(N, vector<int>(M, 0));

    for (int i = 0; i < map.size(); i++)
    {
        for (int j = 0; j < map[i].size(); j++)
        {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < k; i++)
    {
        int order;
        cin >> order;

        int nx = x + dir[order - 1][0];
        int ny = y + dir[order - 1][1];

        if (nx >= 0 && nx < N && ny >= 0 && ny < M)
        {
            rollDice(order);

            if (map[nx][ny] != 0)
            {
                dice[5] = map[nx][ny];
                map[nx][ny] = 0;
            }
            else
            {
                map[nx][ny] = dice[5];
            }

            x = nx;
            y = ny;

            cout << dice[0] << "\n";
        }
    }

    return 0;
}