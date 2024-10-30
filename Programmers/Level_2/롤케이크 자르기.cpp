#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> topping)
{
    int answer = 0;

    map<int, int> a;
    map<int, int> b;

    for (int i = 0; i < topping.size(); i++)
    {
        if (a.find(topping[i]) != a.end())
        {
            a[topping[i]]++;
        }
        else
        {
            a.insert({topping[i], 1});
        }
    }

    for (int i = 0; i < topping.size(); i++)
    {
        if (b.find(topping[i]) != b.end())
        {
            b[topping[i]]++;
        }
        else
        {
            b.insert({topping[i], 1});
        }

        a[topping[i]]--;

        if (a[topping[i]] == 0)
        {
            a.erase(topping[i]);
        }

        if (a.size() == b.size())
        {
            answer++;
        }
    }

    return answer;
}