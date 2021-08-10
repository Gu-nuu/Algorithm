#include <iostream>
#include <string>
#include <vector>

using namespace std;

int grade(int num) // 순위를 계산하는 함수. (7 - 일치하는 번호 갯수)를 하면 순위가 나온다.
{
    if (num < 2)
        return 6;
    else
        return 7 - num;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums)
{
    vector<int> answer;

    int correct = 0; // 일치하는 번호의 갯수
    int wrong = 0;   // 일치하지 않는 번호의 갯수
    for (int i = 0; i < lottos.size(); i++)
    {
        for (int j = 0; j < win_nums.size(); j++)
        {
            if (lottos[i] == 0) // 만약 알아볼 수 없는 번호라면 일치하는 번호일 수도 있고 일치하지 않는 번호일 수도 있음
            {
                correct++;
                wrong++;
                break;
            }
            else if (lottos[i] == win_nums[j]) // 번호가 일치하는 경우 일치하는 번호의 갯수를 증가
            {
                correct++;
                break;
            }
        }
    }

    answer.push_back(grade(correct));         // 최고 순위는 0을 맞는 번호라고 생각한 경우
    answer.push_back(grade(correct - wrong)); // 최저 순위는 0을 틀리다고 생각한 경우이므로 일치하는 번호의 갯수에서 일치하지 않는 번호의 갯수를 빼줌

    return answer;
}

int main()
{
    vector<int> lotto = {44, 1, 0, 0, 31, 25};
    vector<int> win_num = {31, 10, 45, 1, 6, 19};

    vector<int> ans = solution(lotto, win_num);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}