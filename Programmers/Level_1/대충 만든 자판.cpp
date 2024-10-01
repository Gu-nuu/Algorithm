#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets)
{
    vector<int> answer;

    for (int i = 0; i < targets.size(); i++)
    {
        int cnt = 0;

        for (int j = 0; j < targets[i].size(); j++)
        {
            vector<int> search;

            for (int k = 0; k < keymap.size(); k++)
            {

                if (keymap[k].find(targets[i][j]) != string::npos)
                {
                    search.push_back(keymap[k].find(targets[i][j]));
                }
            }

            if (!search.empty())
            {
                sort(search.begin(), search.end());
                cnt += (search[0] + 1);
            }
            else
            {
                cnt = -1;
                break;
            }
        }

        answer.push_back(cnt);
    }

    return answer;
}