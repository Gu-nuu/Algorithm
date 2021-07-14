#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;

    int pick = nums.size() / 2; // 고를 수 있는 폰켓몬의 수를 계산

    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end()); // 가능한 많은 종류로 뽑아가야 하므로 중복되는 폰켓몬을 제거

    if (pick >= nums.size()) // 만약 골라할 폰켓몬의 수가 폰켓몬의 종류보다 많다면 모든 폰켓몬의 종류의 수만큼 뽑을 수 있음
        answer = nums.size();
    else
        answer = pick; // 만약 폰켓몬의 종류가 더 많다면 고를 수 있는 폰켓몬의 수까지만 뽑을 수 있음

    return answer;
}

int main()
{
    vector<int> testcase = {3, 1, 2, 3};

    int ans = solution(testcase);

    cout << ans << endl;
}