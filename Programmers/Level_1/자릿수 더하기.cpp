#include <iostream>
#include <vector>

using namespace std;

int solution(int n)
{
    int answer = 0;

    vector<int> nums;

    while (true)
    {
        nums.push_back(n % 10); // 10로 나눈 나머지는 한 자릿수가 됨

        if (n / 10 == 0) // 10으로 나눈 몫의 값이 0이라면 자릿수를 모두 분리한 것임
            break;
        else
            n /= 10; // 몫이 0이 아니라면 10으로 나눠주어 자릿수를 분리함
    }

    for (int i = 0; i < nums.size(); i++)
        answer += nums[i];

    return answer;
}

int main()
{
    int N = 123;

    cout << solution(N) << endl;

    return 0;
}