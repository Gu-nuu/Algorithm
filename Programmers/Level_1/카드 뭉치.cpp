#include <string>
#include <vector>
#include <queue>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal)
{
    string answer = "";

    queue<string> cd1;
    queue<string> cd2;

    for (int i = 0; i < cards1.size(); i++)
    {
        cd1.push(cards1[i]);
    }

    for (int i = 0; i < cards2.size(); i++)
    {
        cd2.push(cards2[i]);
    }

    bool flag = true;

    for (int i = 0; i < goal.size(); i++)
    {
        if (cd1.front() == goal[i] && !cd1.empty())
        {
            cd1.pop();
        }
        else if (cd2.front() == goal[i] && !cd2.empty())
        {
            cd2.pop();
        }
        else
        {
            flag = false;
            break;
        }
    }

    if (flag)
    {
        answer = "Yes";
    }
    else
    {
        answer = "No";
    }

    return answer;
}