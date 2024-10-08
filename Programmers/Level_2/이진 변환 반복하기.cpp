#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

pair<string, int> delete_zero(string line)
{
    pair<string, int> result = {"", 0};

    for (int i = 0; i < line.size(); i++)
    {
        if (line[i] != '0')
        {
            result.first += line[i];
        }
        else
        {
            result.second++;
        }
    }

    return result;
}

string to_binary(int num)
{
    vector<int> temp;
    string result = "";

    while (num != 0)
    {
        if (num % 2 == 1)
        {
            temp.push_back(1);
        }
        else
        {
            temp.push_back(0);
        }

        num /= 2;
    }

    reverse(temp.begin(), temp.end());

    for (int i = 0; i < temp.size(); i++)
    {
        result += (temp[i] + '0');
    }

    return result;
}

vector<int> solution(string s)
{
    vector<int> answer;
    pair<string, int> result = {s, 0};
    int change_count = 0;
    int delete_count = 0;

    while (result.first != "1")
    {
        result = delete_zero(result.first);
        delete_count += result.second;
        result.first = to_binary(result.first.size());
        change_count++;
    }

    answer.push_back(change_count);
    answer.push_back(delete_count);

    return answer;
}