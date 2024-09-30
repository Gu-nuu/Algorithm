#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool compare(int a, int b)
{
    return a > b;
}

int solution(int k, int m, vector<int> score)
{
    int answer = 0;

    sort(score.begin(), score.end(), compare);

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < score.size(); i++)
    {

        pq.push(score[i]);

        if (pq.size() == m)
        {
            int smallest = pq.top();
            answer += (smallest * m);

            while (!pq.empty())
            {
                pq.pop();
            }
        }
    }

    return answer;
}