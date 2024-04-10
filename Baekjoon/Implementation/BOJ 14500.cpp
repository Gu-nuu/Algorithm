#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

vector<vector<int>> paper;

int calculateTetromino(int start_r, int start_c)
{
    int cal = 0;

    if (start_c + 3 < M)
    {
        cal = max(cal, paper[start_r][start_c] + paper[start_r][start_c + 1] + paper[start_r][start_c + 2] + paper[start_r][start_c + 3]);
    }
    if (start_r + 3 < N)
    {
        cal = max(cal, paper[start_r][start_c] + paper[start_r + 1][start_c] + paper[start_r + 2][start_c] + paper[start_r + 3][start_c]);
    }

    if (start_r + 1 < N && start_c + 1 < M)
    {
        cal = max(cal, paper[start_r][start_c] + paper[start_r][start_c + 1] + paper[start_r + 1][start_c] + paper[start_r + 1][start_c + 1]);
    }

    if (start_r + 2 < N && start_c + 1 < M)
    {
        cal = max(cal, paper[start_r][start_c] + paper[start_r + 1][start_c] + paper[start_r + 2][start_c] + paper[start_r + 2][start_c + 1]);
    }
    if (start_r + 2 < N && start_c - 1 >= 0)
    {
        cal = max(cal, paper[start_r][start_c] + paper[start_r + 1][start_c] + paper[start_r + 2][start_c] + paper[start_r + 2][start_c - 1]);
    }
    if (start_r - 2 >= 0 && start_c + 1 < M)
    {
        cal = max(cal, paper[start_r][start_c] + paper[start_r - 1][start_c] + paper[start_r - 2][start_c] + paper[start_r - 2][start_c + 1]);
    }
    if (start_r - 2 >= 0 && start_c - 1 >= 0)
    {
        cal = max(cal, paper[start_r][start_c] + paper[start_r - 1][start_c] + paper[start_r - 2][start_c] + paper[start_r - 2][start_c - 1]);
    }
    if (start_r + 1 < N && start_c + 2 < M)
    {
        cal = max(cal, paper[start_r][start_c] + paper[start_r][start_c + 1] + paper[start_r][start_c + 2] + paper[start_r + 1][start_c]);
    }
    if (start_r - 1 >= 0 && start_c + 2 < M)
    {
        cal = max(cal, paper[start_r][start_c] + paper[start_r][start_c + 1] + paper[start_r][start_c + 2] + paper[start_r - 1][start_c]);
    }
    if (start_r + 1 < N && start_c - 2 >= 0)
    {
        cal = max(cal, paper[start_r][start_c] + paper[start_r][start_c - 1] + paper[start_r][start_c - 2] + paper[start_r + 1][start_c]);
    }
    if (start_r - 1 >= 0 && start_c - 2 >= 0)
    {
        cal = max(cal, paper[start_r][start_c] + paper[start_r][start_c - 1] + paper[start_r][start_c - 2] + paper[start_r - 1][start_c]);
    }

    if (start_r - 1 >= 0 && start_r + 1 < N && start_c - 1 >= 0)
    {
        cal = max(cal, paper[start_r][start_c] + paper[start_r - 1][start_c] + paper[start_r][start_c - 1] + paper[start_r + 1][start_c - 1]);
    }
    if (start_r - 1 >= 0 && start_r + 1 < N && start_c - 1 >= 0)
    {
        cal = max(cal, paper[start_r][start_c] + paper[start_r + 1][start_c] + paper[start_r][start_c - 1] + paper[start_r - 1][start_c - 1]);
    }
    if (start_c - 1 >= 0 && start_c + 1 < M && start_r + 1 < N)
    {
        cal = max(cal, paper[start_r][start_c] + paper[start_r + 1][start_c] + paper[start_r][start_c + 1] + paper[start_r + 1][start_c - 1]);
    }
    if (start_c - 1 >= 0 && start_c + 1 < M && start_r + 1 < N)
    {
        cal = max(cal, paper[start_r][start_c] + paper[start_r + 1][start_c] + paper[start_r][start_c - 1] + paper[start_r + 1][start_c + 1]);
    }

    if (start_r - 1 >= 0 && start_c - 1 >= 0 && start_c + 1 < M)
    {
        cal = max(cal, paper[start_r][start_c - 1] + paper[start_r][start_c] + paper[start_r - 1][start_c] + paper[start_r][start_c + 1]);
    }
    if (start_r + 1 < N && start_c - 1 >= 0 && start_c + 1 < M)
    {
        cal = max(cal, paper[start_r][start_c - 1] + paper[start_r][start_c] + paper[start_r + 1][start_c] + paper[start_r][start_c + 1]);
    }
    if (start_r - 1 >= 0 && start_r + 1 < N && start_c - 1 >= 0)
    {
        cal = max(cal, paper[start_r - 1][start_c] + paper[start_r][start_c] + paper[start_r][start_c - 1] + paper[start_r + 1][start_c]);
    }
    if (start_r - 1 >= 0 && start_r + 1 < N && start_c + 1 < M)
    {
        cal = max(cal, paper[start_r - 1][start_c] + paper[start_r][start_c] + paper[start_r][start_c + 1] + paper[start_r + 1][start_c]);
    }

    return cal;
}

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    paper.resize(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> paper[i][j];
        }
    }

    int maximum = -1;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            maximum = max(maximum, calculateTetromino(i, j));
        }
    }

    cout << maximum << "\n";

    return 0;
}