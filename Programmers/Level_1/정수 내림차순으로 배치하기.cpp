#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

bool compare(int a, int b)
{
    return a > b;
}

long long solution(long long n)
{
    long long answer = 0;

    vector<int> nums;

    while (true) // 숫자의 자릿수를 하나씩 분리
    {
        nums.push_back(n % 10);

        if (n / 10 == 0)
            break;
        else
            n /= 10;
    }

    sort(nums.begin(), nums.end(), compare); // 내림차순으로 정렬

    // 내림차순으로 정렬되어 있으므로 각 숫자가 저장되어 있는 벡터의 처음 값은 가장 큰 자릿수가 된다.
    // 따라서 자릿수를 곱해줄 때는 가장 큰 자릿수부터 벡터의 처음과 곱하여 계산해준다.
    for (int i = 0; i < nums.size(); i++)
        answer = answer + (nums[i] * pow(10, nums.size() - (i + 1)));

    return answer;
}

int main()
{
    long long n = 118372;

    cout << solution(n) << endl;

    return 0;
}