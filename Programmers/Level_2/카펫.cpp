#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> getDivisor(int num)
{
    vector<int> divisors;

    int i;

    for (i = 1; i * i < num; i++)
    {
        if (num % i == 0)
        {
            divisors.push_back(i);
            divisors.push_back(num / i);
        }
    }

    if (i * i == num)
        divisors.push_back(i);

    sort(divisors.begin(), divisors.end());

    return divisors;
}

vector<int> solution(int brown, int yellow)
{
    vector<int> answer;

    int sum = brown + yellow;

    vector<int> divisors = getDivisor(sum);

    int left = 0;
    int right = divisors.size() - 1;

    while (left <= right) // 주어진 갈색 개수와 노란색 개수의 합의 약수를 구한 뒤 각각 맨 앞과 맨 뒤에서부터 차례로 방정식에 대입
    {
        if ((divisors[left] - 2) * (divisors[right] - 2) == yellow) // 중앙에는 노란색이고 테두리 1줄은 갈색인 것을 이용한 방정식
        {
            answer.push_back(divisors[right]);
            answer.push_back(divisors[left]);
            break;
        }

        left++;
        right--;
    }

    // if (divisors.size() % 2 == 0)        // 반쪽짜리 정답 : brown 개수와 yellow 개수 사이의 상관 관계를 고려하지 않음
    // {
    //     answer.push_back(divisors[divisors.size() / 2]);
    //     answer.push_back(divisors[divisors.size() / 2 - 1]);
    // }
    // else
    // {
    //     answer.push_back(divisors[divisors.size() / 2]);
    //     answer.push_back(divisors[divisors.size() / 2]);
    // }

    return answer;
}

int main()
{
    int b = 8;
    int y = 1;

    vector<int> ans = solution(b, y);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}