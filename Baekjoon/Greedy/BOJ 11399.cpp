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

    // 돈을 뽑는 시간이 적게 걸리는 사람일수록 앞 순서에서 업무를 보는게 가장 최소 시간으로 모든 사람들이 업무를 볼 수 있는 방법이다.
    // 따라서 set을 이용하여 시간을 입력받을 때 오름차순으로 바로 정렬되어 저장할 수 있도록 하였다.
    multiset<int> ms;

    for (int i = 0; i < N; i++)
    {
        int P;
        cin >> P;

        ms.insert(P);
    }

    int waiting = 0; // 앞 사람이 돈을 뽑고 본인이 돈을 뽑는데 걸리는 시간을 저장하는 변수
    int total = 0;   // 모든 사람이 돈을 뽑았을 때 걸리는 시간을 저장하는 변수

    for (auto it = ms.begin(); it != ms.end(); it++)
    {
        total += (waiting + *it);
        waiting += *it; // 앞에서 걸린 시간만큼 기다리는 시간에 포함되므로 이를 저장 후 다음 사람의 돈 뽑는 시간에 더해준다.
    }

    cout << total << "\n";

    return 0;
}