#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int N;
int house = 1;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<vector<int>> chunk;
vector<vector<int>> isVisited;

void DFS(int start_r, int start_c)
{
    int r = start_r;
    int c = start_c;

    isVisited[r][c] = 1;

    for (int d = 0; d < 4; d++)
    {
        int dr = r + dir[d][0];
        int dc = c + dir[d][1];

        if (dr >= 0 && dr < N && dc >= 0 && dc < N && chunk[dr][dc] != 0 && isVisited[dr][dc] == 0)
        {
            isVisited[dr][dc] = 1;
            house++;
            DFS(dr, dc);
        }
    }
}

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    chunk.assign(N, vector<int>(N, 0));
    isVisited.assign(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;

        for (int j = 0; j < N; j++)
        {
            chunk[i][j] = temp[j] - '0';
        }
    }

    int total = 0;
    vector<int> houses;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (chunk[i][j] != 0 && isVisited[i][j] == 0)
            {
                DFS(i, j);
                houses.push_back(house);
                house = 1;
                total++;
            }
        }
    }

    sort(houses.begin(), houses.end());

    cout << total << "\n";
    for (int i = 0; i < houses.size(); i++)
    {
        cout << houses[i] << "\n";
    }

    return 0;
}