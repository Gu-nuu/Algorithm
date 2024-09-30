#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, int m, vector<int> section)
{
    int answer = 0;

    vector<bool> area(n, false);

    for (int i = 0; i < section.size(); i++)
    {
        area[section[i] - 1] = true;
    }

    for (int i = 0; i < area.size(); i++)
    {
        if (area[i])
        {

            for (int j = i; j < i + m; j++)
            {

                if (j > area.size() - 1)
                {
                    break;
                }

                area[j] = false;
            }
            answer++;
        }
    }

    return answer;
}