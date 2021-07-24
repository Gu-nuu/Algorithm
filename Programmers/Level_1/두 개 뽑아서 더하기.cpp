#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> sum; // 두 개의 수의 합을 저장할 벡터

// numbers 벡터에 들어있는 수들 중 2개를 조합의 경우로 뽑는 함수. 백트래킹 알고리즘을 사용하였다.
void backtracking(int num, int count, vector<int> numbers, vector<bool> check, vector<int> box)
{
    if (count == 2)
    {
        sum.push_back(box[0] + box[1]);
        return;
    }

    for (int i = num; i < numbers.size(); i++)
    {
        if (!check[i])
        {
            box[count] = numbers[i];
            check[i] = true;
            backtracking(i + 1, count + 1, numbers, check, box);
            check[i] = false;
        }
    }
}

vector<int> solution(vector<int> numbers)
{
    vector<int> answer;
    vector<bool> check(numbers.size());
    vector<int> box(2);

    backtracking(0, 0, numbers, check, box);

    sort(sum.begin(), sum.end());
    sum.erase(unique(sum.begin(), sum.end()), sum.end()); // 서로 다른 수끼리 더하더라도 같은 값을 가질 수 있으므로 중복을 제거하여 문제를 해결

    answer = sum;

    return answer;
}

int main()
{
    vector<int> nums = {5, 0, 2, 7};

    vector<int> ans = solution(nums);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}