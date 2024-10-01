#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool compare(int a, int b)
{
    return a > b;
}

string solution(string X, string Y)
{
    string answer = "";

    map<char, int> Xmap;
    map<char, int> Ymap;
    vector<int> v;

    for (int i = 0; i < X.size(); i++)
    {
        if (Xmap.find(X[i]) != Xmap.end())
        {
            Xmap[X[i]]++;
        }
        else
        {
            Xmap.insert({X[i], 1});
        }
    }

    for (int i = 0; i < Y.size(); i++)
    {
        if (Ymap.find(Y[i]) != Ymap.end())
        {
            Ymap[Y[i]]++;
        }
        else
        {
            Ymap.insert({Y[i], 1});
        }
    }

    for (auto it = Xmap.begin(); it != Xmap.end(); it++)
    {

        if (Ymap.find(it->first) != Ymap.end())
        {

            int repeat = min(it->second, Ymap[it->first]);

            for (int j = 0; j < repeat; j++)
            {
                v.push_back(it->first - '0');
            }
        }
    }

    if (v.empty())
    {
        answer += "-1";
    }
    else
    {
        sort(v.begin(), v.end(), compare);

        if (v[0] == 0)
        {
            answer += "0";
        }
        else
        {
            for (int i = 0; i < v.size(); i++)
            {
                answer += (v[i] + '0');
            }
        }
    }

    return answer;
}