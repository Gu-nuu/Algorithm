#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 각 부서의 신청 금액을 오름차순으로 정렬한 후, 반복문을 이용하여 각 부서의 신청 금액을 더해가면서 예산을 넘어가지 않는다면 answer을 증가시켜주고
// 예산을 초과한다면 넘어가도록 하였다. 가장 작은 값부터 더해가기 때문에 정해진 예산 안에서 가능한 많은 부서를 지원할 수 있도록 하는 알고리즘이다.
int solution(vector<int> d, int budget)
{
    int answer = 0;

    sort(d.begin(), d.end());

    int sum = 0;
    for (int i = 0; i < d.size(); i++)
    {
        sum += d[i];
        if (sum <= budget)
            answer++;
        else
            break;
    }

    return answer;
}

int main()
{
    vector<int> d = {2, 2, 3, 3};
    int budget = 10;

    cout << solution(d, budget) << endl;

    return 0;
}