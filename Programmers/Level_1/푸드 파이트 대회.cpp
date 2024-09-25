#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> food)
{
    string answer = "";

    for (int i = 1; i < food.size(); i++)
    {
        if (food[i] >= 2)
        {
            for (int j = 0; j < food[i] / 2; j++)
            {
                answer += to_string(i);
            }
        }
    }

    string rev = answer;
    reverse(rev.begin(), rev.end());

    answer += "0";
    answer += rev;

    return answer;
}