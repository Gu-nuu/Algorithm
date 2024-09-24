#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s)
{
    vector<int> answer;
    string temp = "";

    for (int i = 0; i < s.size(); i++)
    {
        bool flag = false;
        for (int j = i; j >= 0; j--)
        {
            if (temp[j - 1] == s[i])
            {
                flag = true;
                answer.push_back(i - j + 1);
                break;
            }
        }
        if (!flag)
        {
            answer.push_back(-1);
        }
        temp += s[i];
    }

    return answer;
}