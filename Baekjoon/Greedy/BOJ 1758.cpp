#include <iostream>
#include <set>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    // 주려는 팁이 큰 사람일수록 앞 순서에 세울 때 가장 큰 팁의 함계를 얻을 수 있다.
    // 따라서 multiset을 내림차순으로 정렬하도록 해서 팁을 입력받을 때 바로 내림차순으로 정렬될 수 있도록 했다.
    // 이때 최대 나올 수 있는 팁의 값을 고려했을 때 계산하게 되면 int형에서는 오버플로우가 발생할 수 있기 때문에 long long형을 사용했다.
    multiset<long long, greater<long long>> ms;

    for (int i = 0; i < N; i++)
    {
        long long tip;
        cin >> tip;

        ms.insert(tip);
    }

    long long order = 1; // 줄을 선 순서이며 팁을 계산 후 하나씩 증가시켜 순서를 표현한다.
    long long sum = 0;

    for (auto it = ms.begin(); it != ms.end(); it++)
    {
        long long cal = *it - (order - 1);

        if (cal < 0) // 만약 계산한 팁의 값이 음수라면 0을 합에 더해주고 아니라면 해당 팁의 값을 더해준다.
            sum += 0;
        else
            sum += cal;

        order++;
    }

    cout << sum << "\n";

    return 0;
}