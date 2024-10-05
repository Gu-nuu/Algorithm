#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool compare(pair<string, int> a, pair<string, int> b)
{
    return a.second < b.second;
}

vector<string> solution(vector<string> players, vector<string> callings)
{
    vector<string> answer;

    map<string, int> find_rank;
    map<int, string> find_name;

    for (int i = 0; i < players.size(); i++)
    {
        find_rank.insert({players[i], i + 1});
        find_name.insert({i + 1, players[i]});
    }

    for (int i = 0; i < callings.size(); i++)
    {
        int current_rank = find_rank[callings[i]];
        string prev_name = find_name[current_rank - 1];

        find_name[current_rank - 1] = callings[i];
        find_name[current_rank] = prev_name;

        find_rank[callings[i]] = current_rank - 1;
        find_rank[prev_name] = current_rank;
    }

    vector<pair<string, int>> ans;

    for (auto it = find_rank.begin(); it != find_rank.end(); it++)
    {
        ans.push_back({it->first, it->second});
    }

    sort(ans.begin(), ans.end(), compare);

    for (int i = 0; i < ans.size(); i++)
    {
        answer.push_back(ans[i].first);
    }

    return answer;
}