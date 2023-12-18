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

    vector<long long> muscleLoss; // 근손실 정도를 저장할 vector. 오버플로우를 고려하여 int형이 아닌 long long형을 선택했다.

    for (int i = 0; i < N; i++)
    {
        long long num;
        cin >> num;

        muscleLoss.push_back(num);
    }

    // 그리디 알고리즘의 관점으로 접근할 때, PT 1회에 최대 2가지의 운동을 진행하므로 근손실이 가장 적은 운동과 근손실이 가장 큰 운동을 묶어 모든 운동을 진행했을 떼
    // 근손실의 정도가 가장 최소로 나오게 된다. 따라서 근손실의 정도에 따라 오름차순으로 정렬하고 운동의 갯수가 짝수일 때와 홀수일 때로 구분한 뒤
    // 짝수의 경우에 가장 처음의 운동에서 뒤로 하나씩, 가장 마지막의 운동에서 앞으로 하나씩 순차적으로 탐색하여 더한 값 중에 가장 큰 값이 곧 최소의 근손실 정도가 된다.
    // 홀수의 경우에도 똑같이 진행하나 가장 마지막 위치에 있는 근손실의 가장 큰 운동과 순차적으로 탐색 후 얻어낸 근손실의 최솟값 중에 더 큰 것이 곧 모든 운동을 했을 때 근손실의 최솟값이 된다.
    sort(muscleLoss.begin(), muscleLoss.end());

    long long M = -1;

    if (N % 2 == 0)
    {

        for (int i = 0; i < N / 2; i++)
        {
            if (M < muscleLoss[i] + muscleLoss[N - 1 - i])
            {
                M = muscleLoss[i] + muscleLoss[N - 1 - i];
            }
        }
    }
    else
    {
        if (N == 1)
        {
            M = muscleLoss[0];
        }
        else
        {
            for (int i = 0; i < N / 2; i++)
            {
                if (M < muscleLoss[i] + muscleLoss[N - 2 - i])
                {
                    M = muscleLoss[i] + muscleLoss[N - 2 - i];
                }
            }

            if (M < muscleLoss[N - 1])
            {
                M = muscleLoss[N - 1];
            }
        }
    }

    cout << M << "\n";

    return 0;
}