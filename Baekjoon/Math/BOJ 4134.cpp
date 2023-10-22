#include <iostream>
#include <cmath>
using namespace std;

// 소수인지 아닌지 판별해주는 함수
// 입력으로 들어오는 숫자 범위가 4*10^9까지므로 자료형을 long long으로 선언해주었다.
// 시간 초과를 방지하기 위해 2부터 입력받은 숫자의 제곱근까지로 범위를 줄였고 이 중 나눠지는 수가 있다면 소수가 아니게 되므로 false를, 만약 나눠지는 수가 없다면 소수이므로 true를 반환해주었다.
bool isPrimeNum(long long n)
{
    if (n < 2)
        return false;
    else
    {
        for (long long i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
                return false;
        }

        return true;
    }
}

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int test_case;

    cin >> test_case;

    for (int i = 0; i < test_case; i++)
    {
        long long n;
        cin >> n;

        bool find = false;

        while (!find) // 입력받은 수보다 같거나 큰 수들 중 제일 작은 소수를 찾아야 하므로 입력받은 수가 소수가 아니면 1씩 증가시켜 소수인지를 판별하고 만약 소수면 반복문을 종료하도록 했다.
        {
            if (isPrimeNum(n))
            {
                find = true;
                cout << n << "\n";
            }
            else
                n++;
        }
    }

    return 0;
}