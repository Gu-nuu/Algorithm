#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N;
    cin >> M;

    vector<vector<int>> box(N, vector<int>(N, 0));

    box[0][0] = N * N;
    int r = 0, c = 0;
    bool exitFlag = false;

    while (true)
    {
        while (box[r + 1][c] == 0)
        {
            box[r + 1][c] = box[r][c] - 1;
            r++;

            if (r == N - 1)
                break;
            else if (box[r][c] == 1)
            {
                exitFlag = true;
                break;
            }
        }

        if (exitFlag)
            break;

        while (box[r][c + 1] == 0)
        {
            box[r][c + 1] = box[r][c] - 1;
            c++;

            if (c == N - 1)
                break;
        }

        while (box[r - 1][c] == 0)
        {
            box[r - 1][c] = box[r][c] - 1;
            r--;

            if (r == 0)
                break;
        }

        while (box[r][c - 1] == 0)
        {
            box[r][c - 1] = box[r][c] - 1;
            c--;

            if (c == 0)
                break;
        }
    }

    pair<int, int> coordinate;

    for (int i = 0; i < box.size(); i++)
    {
        for (int j = 0; j < box[i].size(); j++)
        {
            if (M == box[i][j])
                coordinate = {i + 1, j + 1};

            cout << box[i][j] << " ";
        }
        cout << "\n";
    }

    cout << coordinate.first << " " << coordinate.second << "\n";

    return 0;
}