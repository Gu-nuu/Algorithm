#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s, string skip, int index)
{
    string answer = "";

    vector<char> alphabet;

    for (int i = 97; i <= 122; i++)
    {
        alphabet.push_back(i);
    }

    vector<int> skip_index;

    for (int i = 0; i < skip.size(); i++)
    {
        skip_index.push_back(find(alphabet.begin(), alphabet.end(), skip[i]) - alphabet.begin());
    }

    for (int i = 0; i < s.size(); i++)
    {
        int s_index = find(alphabet.begin(), alphabet.end(), s[i]) - alphabet.begin();
        int count = 0;

        while (count != index)
        {

            if (s_index + 1 < alphabet.size())
            {
                s_index++;
            }
            else
            {
                s_index = 0;
            }

            if (find(skip_index.begin(), skip_index.end(), s_index) != skip_index.end())
            {
                count--;
            }

            count++;
        }

        answer += (alphabet[s_index]);
    }

    return answer;
}