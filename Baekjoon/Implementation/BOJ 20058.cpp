#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

int N, Q;

int iceGroundSize;

vector<vector<int>> iceGround;

vector<int> fireStorm;

vector<vector<int>> visited;

int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void rotate(int startR, int startC, int level)
{
    int size = pow(2, level);

    vector<vector<int>> temp(size, vector<int>(size, 0));

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            temp[j][size - 1 - i] = iceGround[startR + i][startC + j];
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            iceGround[startR + i][startC + j] = temp[i][j];
        }
    }
}

void melt_ice()
{
    vector<pair<int, int>> melt_coordinate;

    for (int i = 0; i < iceGround.size(); i++)
    {
        for (int j = 0; j < iceGround[i].size(); j++)
        {
            if (iceGround[i][j] > 0)
            {
                int adj_ice = 0;
                for (int d = 0; d < 4; d++)
                {
                    int dr = i + dir[d][0];
                    int dc = j + dir[d][1];

                    if (dr >= 0 && dr < iceGroundSize && dc >= 0 && dc < iceGroundSize && iceGround[dr][dc] > 0)
                    {
                        adj_ice++;
                    }
                }
                if (adj_ice < 3)
                {
                    melt_coordinate.push_back({i, j});
                }
            }
        }
    }

    for (int i = 0; i < melt_coordinate.size(); i++)
    {
        if (iceGround[melt_coordinate[i].first][melt_coordinate[i].second] > 0)
        {
            iceGround[melt_coordinate[i].first][melt_coordinate[i].second]--;
        }
    }
}

int find_ice_chunk(int startR, int startC)
{
    int count = 0;
    queue<pair<int, int>> q;
    q.push({startR, startC});
    visited[startR][startC] = 1;

    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        count++;

        for (int d = 0; d < 4; d++)
        {
            int dr = r + dir[d][0];
            int dc = c + dir[d][1];

            if (dr >= 0 && dr < iceGroundSize && dc >= 0 && dc < iceGroundSize && iceGround[dr][dc] > 0 && visited[dr][dc] == 0)
            {
                visited[dr][dc] = 1;
                q.push({dr, dc});
            }
        }
    }

    return count;
}

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> Q;

    iceGroundSize = pow(2, N);

    iceGround.resize(iceGroundSize, vector<int>(iceGroundSize, 0));

    for (int i = 0; i < iceGroundSize; i++)
    {
        for (int j = 0; j < iceGroundSize; j++)
        {
            cin >> iceGround[i][j];
        }
    }

    for (int i = 0; i < Q; i++)
    {
        int level;
        cin >> level;
        fireStorm.push_back(level);
    }

    for (int i = 0; i < fireStorm.size(); i++)
    {
        for (int j = 0; j < iceGroundSize; j += (pow(2, fireStorm[i])))
        {
            for (int k = 0; k < iceGroundSize; k += (pow(2, fireStorm[i])))
            {
                rotate(j, k, fireStorm[i]);
            }
        }

        melt_ice();
    }

    int sum = 0;
    for (int i = 0; i < iceGroundSize; i++)
    {
        for (int j = 0; j < iceGroundSize; j++)
        {
            sum += iceGround[i][j];
        }
    }

    visited.resize(iceGroundSize, vector<int>(iceGroundSize, 0));

    int chunkSize = 0;
    for (int i = 0; i < iceGroundSize; i++)
    {
        for (int j = 0; j < iceGroundSize; j++)
        {
            if (iceGround[i][j] > 0)
            {
                chunkSize = max(chunkSize, find_ice_chunk(i, j));
            }
        }
    }

    cout << sum << "\n"
         << chunkSize << "\n";

    return 0;
}