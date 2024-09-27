#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo)
{
    vector<int> answer;

    for (int i = 0; i < photo.size(); i++)
    {
        int score = 0;

        sort(photo[i].begin(), photo[i].end());

        for (int j = 0; j < name.size(); j++)
        {
            if (binary_search(photo[i].begin(), photo[i].end(), name[j]))
            {
                score += yearning[j];
            }
        }

        answer.push_back(score);
    }

    return answer;
}