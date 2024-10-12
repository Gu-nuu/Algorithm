#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> answer;
vector<int> visited;

bool compare(vector<string> a, vector<string> b)
{
    return a[1] < b[1];
}

bool visit_all(vector<int> v)
{

    bool flag = true;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == 0)
        {
            flag = false;
            break;
        }
    }

    return flag;
}

void DFS(string start, vector<vector<string>> &tickets)
{

    answer.push_back(start);

    if (visit_all(visited))
    {
        return;
    }

    for (int i = 0; i < tickets.size(); i++)
    {
        if (visited[i] == 0 && tickets[i][0] == start)
        {
            visited[i] = 1;
            DFS(tickets[i][1], tickets);
            if (visit_all(visited))
            {
                return;
            }
            visited[i] = 0;
        }
    }

    answer.pop_back();
}

vector<string> solution(vector<vector<string>> tickets)
{

    visited.assign(tickets.size(), 0);

    sort(tickets.begin(), tickets.end(), compare);

    DFS("ICN", tickets);

    return answer;
}
