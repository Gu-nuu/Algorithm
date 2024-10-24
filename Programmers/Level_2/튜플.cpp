#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}

vector<int> solution(string s)
{
    vector<int> answer;

    map<int, int> m;

    string temp = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != '{' && s[i] != '}' && s[i] != ',')
        {
            temp += s[i];
        }
        else
        {
            if ((s[i] == '}' || s[i] == ',') && temp != "")
            {

                if (m.find(stoi(temp)) != m.end())
                {
                    m[stoi(temp)]++;
                }
                else
                {
                    m.insert({stoi(temp), 1});
                }

                temp = "";
            }
        }
    }

    vector<pair<int, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < v.size(); i++)
    {
        answer.push_back(v[i].first);
    }

    return answer;
}