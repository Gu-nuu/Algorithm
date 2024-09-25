#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int k, vector<int> score)
{
    vector<int> answer;

    priority_queue<int, vector<int>, greater<int>> MJ;

    for (int i = 0; i < score.size(); i++)
    {
        MJ.push(score[i]);

        if (MJ.size() > k)
        {
            MJ.pop();
            answer.push_back(MJ.top());
        }
        else
        {
            answer.push_back(MJ.top());
        }
    }

    return answer;
}