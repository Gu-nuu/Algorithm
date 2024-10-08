#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

pair<string, string> get_name(string line)
{
    pair<string, string> temp = {"", ""};

    int space_index = line.find(' ');

    temp.first = line.substr(0, space_index);
    temp.second = line.substr(space_index + 1);

    return temp;
}

int solution(vector<string> friends, vector<string> gifts)
{
    int answer = 0;

    map<string, map<string, int>> gift_list;
    map<string, pair<int, int>> gift_score;
    map<string, int> result;

    for (int i = 0; i < friends.size(); i++)
    {
        map<string, int> m;

        for (int j = 0; j < friends.size(); j++)
        {
            if (friends[i] == friends[j])
            {
                m.insert({friends[j], -1});
            }
            else
            {
                m.insert({friends[j], 0});
            }
        }

        gift_list.insert({friends[i], m});
        gift_score.insert({friends[i], {0, 0}});
        result.insert({friends[i], 0});
    }

    for (int i = 0; i < gifts.size(); i++)
    {
        pair<string, string> from_to = get_name(gifts[i]);

        gift_list[from_to.first][from_to.second]++;
        gift_score[from_to.first].first++;
        gift_score[from_to.second].second++;
    }

    for (int i = 0; i < friends.size(); i++)
    {
        string current_friend = friends[i];
        map<string, int> temp = gift_list[current_friend];

        for (auto it = temp.begin(); it != temp.end(); it++)
        {
            string target_friend = it->first;
            int given_gift = it->second;
            int received_gift = gift_list[target_friend][current_friend];

            if (current_friend > target_friend)
            {
                continue;
            }

            int current_friend_balance = gift_score[current_friend].first - gift_score[current_friend].second;
            int target_friend_balance = gift_score[target_friend].first - gift_score[target_friend].second;

            if (given_gift > received_gift)
            {
                result[current_friend]++;
            }
            else if (given_gift < received_gift)
            {
                result[target_friend]++;
            }
            else if (given_gift == received_gift)
            {
                if (current_friend_balance > target_friend_balance)
                {
                    result[current_friend]++;
                }
                else if (current_friend_balance < target_friend_balance)
                {
                    result[target_friend]++;
                }
            }
        }
    }

    vector<int> ans;

    for (auto it = result.begin(); it != result.end(); it++)
    {
        ans.push_back(it->second);
    }
    sort(ans.begin(), ans.end());
    answer = ans[ans.size() - 1];

    return answer;
}