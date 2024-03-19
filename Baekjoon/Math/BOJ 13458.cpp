#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long N;
    cin >> N;

    vector<long long> A;

    for (int i = 0; i < N; i++)
    {
        long long num_A;
        cin >> num_A;

        A.push_back(num_A);
    }

    long long B, C;
    cin >> B >> C;

    long long person = 0;

    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] <= B) // 총감독관이 감독할 수 있는 인원이 시험장의 인원보다 많은 경우 총감독관 1명이면 충분
        {
            person++;
        }
        else
        {
            person++; // 총감독관 1명은 무조건 시험장에 배치
            A[i] -= B;

            if (A[i] <= C) // 부감독관이 감독할 수 있는 인원이 시험장의 인원보다 많은 경우 부감독관 1명이면 충분
            {
                person++;
            }
            else
            {
                // 시험장의 인원을 나눴을 때 나머지가 0이면 (시험장의 인원 / 부감독관이 감독할 수 있는 인원)이
                // 필요한 부감독관의 수가 된다.
                if (A[i] % C == 0)
                {
                    person += (A[i] / C);
                }
                // 시험장의 인원을 나눴을 때 나머지가 0이 아니면면 (시험장의 인원 / 부감독관이 감독할 수 있는 인원)에 +1을 한 값이
                // 필요한 부감독관의 수가 된다.
                else
                {
                    person += (A[i] / C);
                    person++;
                }
            }
        }
    }

    cout << person << "\n";

    return 0;
}