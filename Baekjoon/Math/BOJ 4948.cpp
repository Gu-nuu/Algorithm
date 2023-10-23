#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // 에라토스테네스의 체를 이용하면 특정 범위 내 소수들을 빠르게 구할 수 있다.
    // 입력 받은 수 n보다 크고 2n보다 작은 범위 내 소수들을 구해야하므로 (최대 범위) * 2 + 1 크기의 vector를 설정해준다.
    vector<int> box(246913, 1);
    box[0] = 0;
    box[1] = 0;
    // 에라토스테네스의 체는 모든 수가 소수라는 가정 하에 계산을 진행하므로 모두 1로 두되 0과 1은 소수가 아니므로 0으로 설정한다.

    while (1)
    {
        int n;
        cin >> n;

        if (n == 0) // 0을 입력 받으면 더 이상 수를 입력받지 않는다.
            break;
        else
        {
            // 입력받은 수의 2배를 한 수까지의 소수를 판별한다.
            // 2부터 입력받은 수의 제곱근까지 순차적으로 확인하며 만약 해당 자리의 숫자가 1, 즉 소수라면 소수는 어떤 수와 곱해도 무조건 합성수이기 때문에
            // 해당 수를 제외한 배수들은 모두 지워주도록 한다.
            // 이 과정을 반복하면 찾고자 하는 숫자 이전의 범위 내에서 소수들을 판별할 수 있다.
            for (int i = 2; i <= sqrt(2 * n); i++)
            {
                if (box[i] == 1)
                {
                    for (int j = 2 * i; j <= 2 * n; j += i)
                    {
                        box[j] = 0;
                    }
                }
            }

            int cnt = 0;

            for (int k = n + 1; k <= 2 * n; k++) // 입력받은 수 n보다 크고 2 * n보다는 작거나 같은 범위에서 소수를 발견하면 cnt를 증가시킨다.
            {
                if (box[k] == 1)
                    cnt++;
            }

            cout << cnt << "\n";
        }
    }

    return 0;
}