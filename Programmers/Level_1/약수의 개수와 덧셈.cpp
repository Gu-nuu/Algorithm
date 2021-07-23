#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check(int num)
{
    int cnt = 0;

    // 약수를 구할 때 시간을 단축시키는 알고리즘을 적용. 중복을 피해서 시간을 단축시키는 방법을 사용하였다.
    // 처음에 나눠지는 수를 구하면 해당 수를 다시 곱해서 약수를 구하고자 하는 수보다 작다면 해당 경우가 하나 더 있는 경우이므로 카운팅을 추가한다.
    // ex) 12 = {1 * 12}, {2 * 6}, {3 * 4} => 1, 2, 3의 경우까지 n % i의 경우에서 카운팅하고 i * i < num의 경우에서 나머지 4 ,6 ,12의 경우를 카운팅한다.
    // 이때 i * i < num인 이유는 제곱수의 약수의 경우엔 하나만 포함되기 때문이다.

    for (int i = 1; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            cnt++;

            if (i * i < num)
                cnt++;
        }
    }

    if (cnt % 2 == 0)       // 약수의 개수가 짝수면 true를, 홀수면 false를 return
        return true;
    else
        return false;
}

int solution(int left, int right)
{
    int answer = 0;

    vector<int> nums;

    for (int i = left; i <= right; i++)
    {
        if (check(i) == true)
            nums.push_back(i);
        else
            nums.push_back(-i);
    }

    for (int i = 0; i < nums.size(); i++)
        answer += nums[i];

    return answer;
}

int main()
{
    int left = 24;
    int right = 27;

    cout << solution(left, right) << endl;

    return 0;
}