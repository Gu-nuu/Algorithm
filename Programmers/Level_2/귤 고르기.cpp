#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}

int solution(int k, vector<int> tangerine)
{
    int answer = 0;

    map<int, int> m;

    for (int i = 0; i < tangerine.size(); i++)
    {
        if (m.find(tangerine[i]) != m.end())
        {
            m[tangerine[i]]++;
        }
        else
        {
            m.insert({tangerine[i], 1});
        }
    }

    vector<pair<int, int>> v;

    for (auto it = m.begin(); it != m.end(); it++)
    {
        v.push_back({it->first, it->second});
    }

    sort(v.begin(), v.end(), compare);

    int count = 0;
    int sum = 0;

    for (int i = 0; i < v.size(); i++)
    {
        sum += v[i].second;
        count++;

        if (sum >= k)
        {
            answer = count;
            break;
        }
    }

    return answer;
}