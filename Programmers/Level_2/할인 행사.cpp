#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount)
{
    int answer = 0;

    map<string, int> buy_count;

    for (int i = 0; i < want.size(); i++)
    {
        buy_count.insert({want[i], number[i]});
    }

    for (int i = 0; i <= discount.size() - 10; i++)
    {
        vector<string> range(discount.begin() + i, discount.begin() + i + 10);
        sort(range.begin(), range.end());
        bool flag = true;

        for (int j = 0; j < range.size(); j++)
        {

            int cnt = upper_bound(range.begin(), range.end(), range[j]) - lower_bound(range.begin(), range.end(), range[j]);

            if (buy_count.find(range[j]) == buy_count.end() || buy_count[range[j]] != cnt)
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            answer++;
        }
    }

    return answer;
}