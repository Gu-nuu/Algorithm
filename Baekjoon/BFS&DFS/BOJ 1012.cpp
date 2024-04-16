#include <iostream>
#include <vector>
using namespace std;

int N, M;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<vector<int>> farm;
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

        if (dr >= 0 && dr < N && dc >= 0 && dc < M && farm[dr][dc] == 1 && isVisited[dr][dc] == 0)
        {
            isVisited[dr][dc] = 1;
            DFS(dr, dc);
        }
    }
}

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    vector<int> ans;

    for (int i = 0; i < T; i++)
    {
        int K;
        cin >> N >> M >> K;

        farm.assign(N, vector<int>(M, 0));
        isVisited.assign(N, vector<int>(M, 0));

        for (int j = 0; j < K; j++)
        {
            int X, Y;
            cin >> X >> Y;
            farm[X][Y] = 1;
        }

        int worm = 0;

        for (int r = 0; r < N; r++)
        {
            for (int c = 0; c < M; c++)
            {
                if (farm[r][c] == 1 && isVisited[r][c] == 0)
                {
                    DFS(r, c);
                    worm++;
                }
            }
        }

        ans.push_back(worm);
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << "\n";
    }

    return 0;
}