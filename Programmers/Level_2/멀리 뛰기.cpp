#include <string>
#include <vector>

using namespace std;

long long solution(int n)
{
    long long answer = 0;

    vector<long long> dp(2001);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
        dp[i] = dp[i] % 1234567;
    }

    answer = dp[n];

    return answer;
}