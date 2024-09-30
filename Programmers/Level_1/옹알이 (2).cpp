#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling)
{
    int answer = 0;

    for (int i = 0; i < babbling.size(); i++)
    {
        bool flag = true;
        string prevBabbling = "";

        for (int j = 0; j < babbling[i].size(); j++)
        {
            if (babbling[i].substr(j, 3) == "aya" && babbling[i].substr(j, 3) != prevBabbling)
            {
                prevBabbling = babbling[i].substr(j, 3);
                j += 2;
            }
            else if (babbling[i].substr(j, 2) == "ye" && babbling[i].substr(j, 2) != prevBabbling)
            {
                prevBabbling = babbling[i].substr(j, 2);
                j += 1;
            }
            else if (babbling[i].substr(j, 3) == "woo" && babbling[i].substr(j, 3) != prevBabbling)
            {
                prevBabbling = babbling[i].substr(j, 3);
                j += 2;
            }
            else if (babbling[i].substr(j, 2) == "ma" && babbling[i].substr(j, 2) != prevBabbling)
            {
                prevBabbling = babbling[i].substr(j, 2);
                j += 1;
            }
            else
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            answer++;
        }
    }

    return answer;
}