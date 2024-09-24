#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string t, string p)
{
    int answer = 0;
    long long p_num = stoll(p);

    for (int i = 0; i <= t.size() - p.size(); i++)
    {
        string temp = "";
        for (int j = i; j < i + p.size(); j++)
        {
            temp += t[j];
        }
        if (stoll(temp) <= p_num)
        {
            answer++;
        }
    }

    return answer;
}