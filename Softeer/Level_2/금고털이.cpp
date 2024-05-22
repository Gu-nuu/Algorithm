#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}

int main(int argc, char **argv)
{

    int W, N;
    cin >> W >> N;

    vector<pair<int, int>> metals;

    for (int i = 0; i < N; i++)
    {
        int M, P;
        cin >> M >> P;

        metals.push_back({M, P});
    }

    sort(metals.begin(), metals.end(), compare);

    int price = 0;

    for (int i = 0; i < metals.size(); i++)
    {
        int minWeight = min(W, metals[i].first);

        price += (minWeight * metals[i].second);
        W -= minWeight;

        if (W == 0)
        {
            break;
        }
    }

    cout << price << "\n";

    return 0;
}