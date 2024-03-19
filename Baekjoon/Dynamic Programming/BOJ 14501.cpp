#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<pair<int, int>> consulting; // <상담을 완료하는데 걸리는 시간 T, 상담을 했을 때 받을 수 있는 금액 P>
    for (int i = 0; i < N; i++)
    {
        int T, P;
        cin >> T >> P;

        consulting.push_back({T, P});
    }

    vector<int> dp(N + 1, 0);

    for (int i = 0; i < N; i++)
    {
        for (int j = i + consulting[i].first; j <= N; j++)
        {
            dp[j] = max(dp[j], consulting[i].second + dp[i]);
        }
    }

    cout << dp[N] << "\n";

    return 0;
}