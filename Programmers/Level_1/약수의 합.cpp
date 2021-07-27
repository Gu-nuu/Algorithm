#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n)
{
    int answer = 0;

    vector<int> nums;

    int i;
    for (i = 1; i * i < n; i++)
    {
        if (n % i == 0)
        {
            nums.push_back(i);
            nums.push_back(n / i);
        }
    }
    if (i * i == n)
        nums.push_back(i);

    for (int i = 0; i < nums.size(); i++)
        answer += nums[i];

    return answer;
}

int main()
{
    int n = 12;

    cout << solution(n) << endl;

    return 0;
}