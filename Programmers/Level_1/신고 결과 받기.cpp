#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

pair<string, string> find_name(string line)
{
    pair<string, string> names;
    string temp = "";
    int space_idx = 0;

    for (int i = 0; i < line.size(); i++)
    {
        if (line[i] == ' ')
        {
            space_idx = i;
            names.first = temp;
            temp = "";
            break;
        }
        else
        {
            temp += line[i];
        }
    }

    for (int i = space_idx + 1; i < line.size(); i++)
    {
        temp += line[i];
    }
    names.second = temp;

    return names;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k)
{
    vector<int> answer;

    map<string, vector<string>> report_list;
    map<string, int> reported_count;

    for (int i = 0; i < id_list.size(); i++)
    {
        vector<string> temp;
        report_list.insert({id_list[i], temp});
        reported_count.insert({id_list[i], 0});
    }

    for (int i = 0; i < report.size(); i++)
    {
        pair<string, string> report_name = find_name(report[i]);
        vector<string> copy = report_list[report_name.first];

        if (find(copy.begin(), copy.end(), report_name.second) == copy.end())
        {
            report_list[report_name.first].push_back(report_name.second);
            reported_count[report_name.second]++;
        }
    }

    vector<string> stop;
    for (auto it = reported_count.begin(); it != reported_count.end(); it++)
    {
        if (it->second >= k)
        {
            stop.push_back(it->first);
        }
    }

    for (int i = 0; i < id_list.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < stop.size(); j++)
        {
            vector<string> copy = report_list[id_list[i]];
            if (find(copy.begin(), copy.end(), stop[j]) != copy.end())
            {
                count++;
            }
        }
        answer.push_back(count);
    }

    return answer;
}