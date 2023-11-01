#include <iostream>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        long long N, M; // 조합의 숫자가 커지면 int 범위를 넘어설 수 있기 때문에 long long으로 선언해줬다.
        cin >> N >> M;

        long long ans = 1; // 조합을 계산하면 (숫자들의 곱) / (숫자들의 곱)이기 때문에 초기 값을 1로 설정한다.
        long long num = 1; // 나누는 수를 구하기 위한 변수

        // mCn의 경우에서 m-n이 n보다 큰 경우는 그냥 mCn으로 계산하면 되지만,
        // m-n이 n보다 작은 경우엔 mCm-n으로 계산하는게 훨씬 계산이 간편하고 속도가 빠르므로 이를 2가지 조건으로 나누어 구분했다.
        if (M - N > N) // ex) 5C2
        {
            for (long long j = M; j > M - N; j--)
            {
                ans *= j;     // (숫자들의 곱) / (숫자들의 곱)에서 나눠지는 수를 먼저 구한다.
                ans /= num++; // 조합의 갯수만큼 1부터 숫자를 하나씩 늘려 이 숫자들을 나눠준다.
            }
        }
        else // ex) 5C3
        {
            for (long long j = M; j > N; j--)
            {
                ans *= j;
                ans /= num++;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}