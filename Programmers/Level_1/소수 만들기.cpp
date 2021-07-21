#include <vector>
#include <iostream>
using namespace std;

int result = 0;     // 조건에 만족하는 경우에 개수를 카운트하는 변수

bool calculator(int sum)        // 소수인지 아닌지를 판단하는 함수. backtracking 함수에서 뽑힌 3개의 조합의 합을 파라미터로 받아 계산
{
    bool flag = true;
    for (int i = 2; i < sum; i++)
    {
        if (sum % i == 0)
        {
            flag = false;
            break;
        }
    }

    return flag;
}

// 3개의 조합을 만들어내는 함수로 백트래킹 알고리즘을 이용. 백준 15650 문제를 참고!
void backtracking(int x, int count, vector<int> nums, vector<bool> check, vector<int> box)      // nums 벡터에서 3개의 숫자를 조합의 경우로 뽑아주는 함수
{
    if (count == 3)     // 3개의 숫자를 뽑았을 경우
    {
        int temp = 0;
        for (int i = 0; i < box.size(); i++)        // 3개의 숫자의 합을 구함
            temp += box[i];

        if (calculator(temp))       // 소수 판단 함수를 통해 소수로 판단되면 전역변수 result를 증가
            result++;

        return;
    }

    for (int i = x; i < nums.size(); i++)       
    {
        if (!check[i])
        {
            box[count] = nums[i];
            check[i] = true;
            backtracking(i + 1, count + 1, nums, check, box);
            check[i] = false;
        }
    }
}

int solution(vector<int> nums)
{
    int answer = -1;

    vector<bool> check(nums.size());        // nums 벡터의 크기만큼 check 벡터를 생성
    vector<int> box(3);     // 3개의 조합을 저장항 벡터 생성

    backtracking(0, 0, nums, check, box);

    answer = result;

    return answer;
}

int main()
{
    result = 0;
    vector<int> nums = {1, 2, 7, 6, 4};

    cout << solution(nums) << endl;

    return 0;
}