#include <iostream>
#include <vector>
using namespace std;

int days = 0;
// 상, 하, 좌, 우
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int M, N;

    vector<vector<int>> box(M, vector<int>(N, 0));
    vector<pair<int, int>> tomato_coordinate;
    bool allRipen = true;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> box[i][j];

            if (box[i][j] == 0)
            {
                allRipen = false;
            }
            else if (box[i][j] == 1)
            {
                tomato_coordinate.push_back({i, j});
            }
        }
    }

    if (allRipen)
    {
        cout << "0\n";
    }
    else
    {
        
    }

    return 0;
}