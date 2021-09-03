#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices)
{
    vector<int> answer;

    for (int i = 0; i < prices.size() - 1; i++) // 마지막 시점의 주식 가격은 무조건 0초간 가격을 유지하므로 검사할 필요가 없다.
    {
        int sec = 0;

        for (int j = i + 1; j < prices.size(); j++) // 현재 시점의 주식 가격보다 뒤에 있는 시점의 주식 가격이 더 낮다면 가격이 떨어지지 않았으므로 sec를 증가
        {
            sec++;

            if (prices[i] > prices[j]) // 만약 현재 시점의 주식 가격이 더 크다면 가격이 떨어진 것임
                break;
        }

        answer.push_back(sec);
    }

    answer.push_back(0); // 마지막 시점의 주식 가격은 무조건 0초간 가격을 유지한다.

    return answer;
}

int main()
{
    vector<int> prices = {1, 2, 3, 2, 3};

    vector<int> ans = solution(prices);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}