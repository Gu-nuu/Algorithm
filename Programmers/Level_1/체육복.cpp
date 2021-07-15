#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    int answer = 0;

    answer = n - lost.size(); // 현재 체육 수업을 들을 수 있는 사람의 수 계산

    int lost_num = lost.size(); // 현재 체육복을 잃어버린 사람의 수 계산

    // 제한 사항 5 : 여벌 체육복을 가져온 사람이 도난당한 경우엔 lost와 reserve에 모두 같은 값이 존재하는 경우이며,
    // 이들은 자신의 체육복을 하나만 가지고 있기 때문에 체육복을 빌려줄 수 없지만 수업은 들을 수 있다.
    // 따라서 현재 수업을 들을 수 있는 사람의 수를 이들의 수만큼 증가시켜 주고, lost와 reserve에서 제외시킨다.
    for (int i = 0; i < lost.size(); i++)
    {
        for (int j = 0; j < reserve.size(); j++)
        {
            if (lost[i] == reserve[j])
            {
                lost.erase(lost.begin() + i);
                reserve.erase(reserve.begin() + j);
                answer++;
            }
        }
    }

    for (int i = 0; i < reserve.size(); i++)
    {
        if (lost_num == 0) // 잃어버린 사람 모두에게 체육복을 빌려줬으면 반복문을 종료.
            break;

        for (int j = 0; j < lost.size(); j++)
        {
            if (reserve[i] == 1) // 빌려주는 사람이 1번인 경우에 대한 예외 처리
            {
                if (reserve[i] + 1 == lost[j])
                {
                    answer += 1; // 체육 수업을 들을 수 있는 사람의 수를 증가
                    lost_num--;  // 체육복을 잃어버리 사람의 수는 감소
                    break;
                }
            }
            else if (reserve[i] == n) // 빌려주는 사람이 끝 번호인 경우에 대한 예외 처리
            {
                if (reserve[i] - 1 == lost[j])
                {
                    answer += 1;
                    lost_num--;
                    break;
                }
            }
            else
            {
                if (reserve[i] - 1 == lost[j] || reserve[i] + 1 == lost[j]) // 맨 앞 번호와 맨 끝 번호의 경우를 제외한 경우
                {
                    answer += 1;
                    lost_num--;
                    break;
                }
            }
        }
    }

    return answer;
}

int main()
{
    int n = 5;
    vector<int> lost = {2, 3, 4};
    vector<int> reserve = {3, 4, 5};

    int ans = solution(n, lost, reserve);

    cout << ans << endl;

    return 0;
}