#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    // 에라토스테네스의 체를 만들어 소수를 구했다.
    // 입력받은 특정 숫자보다 작은 소수들에 대해 더해서 입력받은 숫자를 만들 수 있는지를 판단해야 함으로
    // 범위 내 소수들을 빠르게 구할 수 있는 에라토스테네스의 체를 선택했다.
    vector<bool> box(1000001, true);
    box[0] = false;
    box[1] = false;

    for (int i = 0; i < T; i++)
    {
        int N;
        cin >> N;

        for (int j = 2; j <= sqrt(N); j++)
        {
            if (box[j] == true)
            {
                for (int k = j + j; k <= N; k += j)
                {
                    box[k] = false;
                }
            }
        }

        int cnt = 0;

        // 입력 받은 숫자의 절반만 판단 범위로 넣었는데 두 소수의 순서만 다르고 합이 같은 경우는 같은 파티션이라고 했기 때문에
        // 절반 이후는 순서만 바뀐 경우이므로 보지 않아도 된다.
        for (int m = 2; m <= N / 2; m++)
        {
            if (box[m] == true && box[N - m] == true) // 만약 입력 받은 숫자 내에서 한 소수(m)가 있을 때 입력받은 숫자에서 그 소수를 뺀 값(N - m)도 소수라면 골드바흐 파티션이 된다.
                cnt++;
        }

        cout << cnt << "\n";
    }

    return 0;
}