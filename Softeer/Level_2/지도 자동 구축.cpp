#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
    int N;
    cin >> N;

    vector<int> dp(16, 0);

    dp[0] = 2;
    dp[1] = 3;

    for (int i = 2; i <= N; i++)
    {
        dp[i] = 2 * (dp[i - 1] - dp[i - 2]) + dp[i - 1];
    }

    cout << dp[N] * dp[N] << "\n";

    return 0;
}