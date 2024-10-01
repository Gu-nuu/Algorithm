#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> ingredient)
{
    int answer = 0;

    vector<int> pack;

    for (int i = 0; i < ingredient.size(); i++)
    {
        pack.push_back(ingredient[i]);

        if (pack.size() > 3 && pack[pack.size() - 1] == 1 && pack[pack.size() - 2] == 3 && pack[pack.size() - 3] == 2 && pack[pack.size() - 4] == 1)
        {
            answer++;

            for (int j = 0; j < 4; j++)
            {
                pack.pop_back();
            }
        }
    }

    return answer;
}