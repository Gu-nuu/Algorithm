#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(string str1, string str2)
{
    int answer = 0;
    transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
    transform(str2.begin(), str2.end(), str2.begin(), ::toupper);

    int cnt = 0;
    string temp = "";
    vector<string> ss1;

    for (int i = 0; i < str1.size(); i++)
    {
        if (str1[i] >= 65 && str1[i] <= 90)
        {
            temp += str1[i];
            cnt++;
        }
        else
        {
            temp = "";
            cnt = 0;
        }

        if (cnt == 2)
        {
            ss1.push_back(temp);
            cnt = 0;
            temp = "";
            i--;
        }
    }

    cnt = 0;
    temp = "";
    vector<string> ss2;

    for (int i = 0; i < str2.size(); i++)
    {
        if (str2[i] >= 65 && str2[i] <= 90)
        {
            temp += str2[i];
            cnt++;
        }
        else
        {
            temp = "";
            cnt = 0;
        }

        if (cnt == 2)
        {
            ss2.push_back(temp);
            cnt = 0;
            temp = "";
            i--;
        }
    }

    if (ss1.size() == 0 && ss2.size() == 0)
    {
        answer = 65536;
    }
    else
    {
        vector<string> uni;
        vector<string> inter;

        sort(ss1.begin(), ss1.end());
        sort(ss2.begin(), ss2.end());
        uni.resize(ss1.size() + ss2.size());
        inter.resize(ss1.size() + ss2.size());

        auto it1 = set_union(ss1.begin(), ss1.end(), ss2.begin(), ss2.end(), uni.begin());
        uni.erase(it1, uni.end());

        auto it2 = set_intersection(ss1.begin(), ss1.end(), ss2.begin(), ss2.end(), inter.begin());
        inter.erase(it2, inter.end());

        double cal = (double(inter.size()) / double(uni.size())) * 65536;
        answer = floor(cal);
    }

    return answer;
}