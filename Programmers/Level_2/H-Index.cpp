#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations)
{
    int answer = 0;

    sort(citations.begin(), citations.end());

    int h = 0;

    while (true)
    {
        int h_bigger = 0; // h번 이상 인용된 논문의 갯수

        for (int i = 0; i < citations.size(); i++)
        {
            if (citations[i] >= h)
                h_bigger++;
        }

        if (h_bigger >= h) // h번 이상 인용된 논문의 갯수가 h 이상일 경우에 그 값들 중 최댓값은 H-Index
            answer = h;

        if (h == citations.size())
            break;

        h++; // h 값을 계속 증가시켜주면서 조건에 해당하는 h의 최댓값을 찾는다.
    }

    return answer;
}

int main()
{
    vector<int> citations = {22, 42};

    cout << solution(citations) << endl;

    return 0;
}