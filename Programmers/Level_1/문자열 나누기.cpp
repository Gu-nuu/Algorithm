#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string s)
{
    int answer = 0;

    char start = s[0];
    int diff = 0;
    int same = 0;
    bool change = false;

    for (int i = 0; i < s.size(); i++)
    {

        if (change)
        {
            change = false;
            start = s[i];
        }

        if (start == s[i])
        {
            same++;
        }
        else
        {
            diff++;
        }

        if (same == diff)
        {
            same = 0;
            diff = 0;
            answer++;
            change = true;
        }
    }

    if (same != 0 || diff != 0)
    {
        answer++;
    }

    return answer;
}