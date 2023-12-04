#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int a, int b)
{
    return a > b;
}

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // 만약 로프들이 N개 존재할 경우 해당 로프들로 버틸 수 있는 최대 중량은 (N개의 로프들 중 최소 중량) * N이 된다.
    // 이때 최대 중량이 가장 높은 로프를 우선 선택하고 중량의 내림차순으로 하나씩 로프들을 추가하면서 각각의 최대 중량을 계산한 뒤
    // 이들 중 가장 큰 중량이 나올 때 해당 로프들로 들 수 있는 최대 중량을 구할 수 있다.

    int N;
    cin >> N;

    vector<int> v;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;

        v.push_back(num);
    }

    sort(v.begin(), v.end(), compare); // 로프들의 최대 중량을 내림차순으로 정렬

    int biggest = v[0]; // 초기 최대 중량을 최대 중량이 가장 큰 로프로 선택

    for (int i = 1; i < v.size(); i++)
    {
        int current = v[i] * (i + 1); // 로프를 하나씩 추가하면서 최대 중량을 계산 후 만약 이전의 최대 중량보다 현재 값이 크다면 biggest 변수에 최대 중량 값을 업데이트한다.

        if (current > biggest)
            biggest = current;
    }

    cout << biggest << "\n";

    return 0;
}