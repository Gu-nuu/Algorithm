#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, L;
int roadCount = 0;

void passRoad(vector<vector<int>> map)
{
    for (int i = 0; i < map.size(); i++)
    {
        bool possible = true;
        vector<int> isSlope(N, 0);

        for (int j = 0; j < map[i].size() - 1; j++)
        {
            if (abs(map[i][j] - map[i][j + 1]) > 1) // 높이 차가 1을 넘음
            {
                possible = false;
                break;
            }

            if (map[i][j] == map[i][j + 1] + 1) // 높은 곳에서 낮은 곳으로 경사로를 만듦
            {
                int currentHeight = map[i][j + 1];

                for (int k = j + 1; k < j + 1 + L; k++)
                {
                    if (k >= N || currentHeight != map[i][k] || isSlope[k] == 1)
                    {
                        possible = false;
                        break;
                    }

                    isSlope[k] = 1;
                }
            }

            if (map[i][j] == map[i][j + 1] - 1) // 낮은 곳에서 높은 곳으로 경사로를 만듦
            {
                int currentHeight = map[i][j];

                for (int k = j; k > j - L; k--)
                {
                    if (k < 0 || currentHeight != map[i][k] || isSlope[k] == 1)
                    {
                        possible = false;
                        break;
                    }

                    isSlope[k] = 1;
                }
            }
        }

        if (possible)
        {
            roadCount++;
        }
    }
}

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> L;

    vector<vector<int>> map1(N, vector<int>(N, 0));
    vector<vector<int>> map2(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map1[i][j];
            map2[j][i] = map1[i][j];
        }
    }

    passRoad(map1);
    passRoad(map2);

    cout << roadCount << "\n";

    return 0;
}