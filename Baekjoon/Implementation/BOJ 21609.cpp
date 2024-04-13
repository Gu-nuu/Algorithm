#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

int N, M;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<vector<int>> map;
vector<vector<int>> isVisited;
int group_size;
int rainbow_block;
pair<int, int> standard_block;
vector<pair<int, int>> group_coordinate;

bool is_adj(int r1, int c1, int r2, int c2)
{
    if (abs(r1 - r2) + abs(c1 - c2) == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void BFS(int start_r, int start_c, int standard)
{
    queue<pair<int, int>> q;
    q.push({start_r, start_c});
    isVisited[start_r][start_c] = 1;

    int temp_group_size = 1;
    int temp_rainbow_block = 0;
    vector<pair<int, int>> temp_rainbow_coordinate;
    pair<int, int> temp_standard_block = {start_r, start_c};
    vector<pair<int, int>> temp_group_coordinate;

    temp_group_coordinate.push_back({start_r, start_c});

    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int d = 0; d < 4; d++)
        {
            int dr = r + dir[d][0];
            int dc = c + dir[d][1];

            if (dr >= 0 && dr < N && dc >= 0 && dc < N && is_adj(r, c, dr, dc) && isVisited[dr][dc] == 0 && (map[dr][dc] == standard || map[dr][dc] == 0))
            {
                isVisited[dr][dc] = 1;

                temp_group_coordinate.push_back({dr, dc});
                temp_group_size++;
                if (map[dr][dc] == 0)
                {
                    temp_rainbow_block++;
                    temp_rainbow_coordinate.push_back({dr, dc});
                }
                else if (dr < temp_standard_block.first || (dr == temp_standard_block.first && dc < temp_standard_block.second))
                {
                    temp_standard_block = {dr, dc};
                }

                q.push({dr, dc});
            }
        }
    }

    for (int i = 0; i < temp_rainbow_coordinate.size(); i++)
    {
        isVisited[temp_rainbow_coordinate[i].first][temp_rainbow_coordinate[i].second] = 0;
    }

    if (group_size < temp_group_size)
    {
        group_size = temp_group_size;
        rainbow_block = temp_rainbow_block;
        standard_block = temp_standard_block;
        group_coordinate = temp_group_coordinate;
    }
    else if (group_size == temp_group_size)
    {
        if (rainbow_block < temp_rainbow_block)
        {
            group_size = temp_group_size;
            rainbow_block = temp_rainbow_block;
            standard_block = temp_standard_block;
            group_coordinate = temp_group_coordinate;
        }
        else if (rainbow_block == temp_rainbow_block)
        {
            if (standard_block.first < temp_standard_block.first)
            {
                group_size = temp_group_size;
                rainbow_block = temp_rainbow_block;
                standard_block = temp_standard_block;
                group_coordinate = temp_group_coordinate;
            }
            else if (standard_block.first == temp_standard_block.first)
            {
                if (standard_block.second < temp_standard_block.second)
                {
                    group_size = temp_group_size;
                    rainbow_block = temp_rainbow_block;
                    standard_block = temp_standard_block;
                    group_coordinate = temp_group_coordinate;
                }
            }
        }
    }
}

void gravity()
{
    for (int i = N - 2; i >= 0; i--)
    {
        for (int j = 0; j < N; j++)
        {
            if (map[i][j] >= 0 && map[i][j] <= M)
            {
                for (int k = i + 1; k < N; k++)
                {
                    if (map[k][j] == -2)
                    {
                        map[k][j] = map[k - 1][j];
                        map[k - 1][j] = -2;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
    }
}

void rotate()
{
    vector<vector<int>> temp(map);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            temp[N - 1 - j][i] = map[i][j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            map[i][j] = temp[i][j];
        }
    }
}

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    map.resize(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
        }
    }

    int score = 0;

    while (true)
    {
        isVisited.assign(N, vector<int>(N, 0));
        group_size = 0;
        rainbow_block = 0;
        standard_block = {N, N};
        group_coordinate.clear();

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (map[i][j] != -2 && map[i][j] != -1 && map[i][j] != 0 && isVisited[i][j] == 0)
                {
                    BFS(i, j, map[i][j]);
                }
            }
        }

        if (group_size <= 1)
        {
            cout << score << "\n";
            break;
        }

        for (int i = 0; i < group_coordinate.size(); i++)
        {
            map[group_coordinate[i].first][group_coordinate[i].second] = -2;
        }
        score += (group_size * group_size);

        gravity();
        rotate();
        gravity();
    }

    return 0;
}