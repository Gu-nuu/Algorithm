#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <cmath>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<vector<int>> S(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> S[i][j];
        }
    }

    vector<int> box(N, 0);
    for (int i = 0; i < N / 2; i++)
    {
        box[i] = 1;
    }

    sort(box.begin(), box.end());

    int smallestGap = INT_MAX;

    do
    {
        vector<int> start;
        vector<int> link;

        for (int i = 0; i < box.size(); i++)
        {
            if (box[i] == 1)
            {
                start.push_back(i);
            }
            else
            {
                link.push_back(i);
            }
        }

        int start_sum = 0;
        int link_sum = 0;

        for (int i = 0; i < N / 2; i++)
        {
            for (int j = 0; j < N / 2; j++)
            {
                if (i != j)
                {
                    start_sum += S[start[i]][start[j]];
                    link_sum += S[link[i]][link[j]];
                }
            }
        }

        if (smallestGap > abs(start_sum - link_sum))
        {
            smallestGap = abs(start_sum - link_sum);
        }

    } while (next_permutation(box.begin(), box.end()));

    cout << smallestGap << "\n";

    return 0;
}