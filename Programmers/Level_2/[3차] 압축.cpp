#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string msg)
{
    vector<int> answer;
    map<string, int> dic;

    for (int i = 65; i <= 90; i++)
    {
        string str(1, char(i));
        dic.insert({str, i - 64});
    }

    string w = "";

    for (int i = 0; i < msg.size(); i++)
    {

        w += msg[i];

        if (i + 1 < msg.size())
        {

            string wc = w + msg[i + 1];

            if (dic.find(wc) != dic.end())
            {
                continue;
            }
            else
            {
                answer.push_back(dic[w]);
                dic.insert({wc, dic.size() + 1});
                w = "";
            }
        }
        else
        {
            answer.push_back(dic[w]);
        }
    }

    return answer;
}