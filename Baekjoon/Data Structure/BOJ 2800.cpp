#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string exp;
    cin >> exp;

    stack<pair<char, int>> s;
    vector<pair<int, int>> bracketPos;

    for (int i = 0; i < exp.size(); i++)
    {
        if (exp[i] == '(')
        {
            s.push({'(', i});
        }
        else if (exp[i] == ')')
        {
            bracketPos.push_back({s.top().second, i});
            s.pop();
        }
    }

    vector<int> combination;

    for (int i = 0; i < bracketPos.size(); i++)
    {
        combination.push_back(i);
    }

    vector<int> select;
    int cnt = 1;

    set<string> ans;

    while (cnt <= combination.size())
    {
        for (int i = 0; i < cnt; i++)
        {
            select.push_back(1);
        }

        for (int i = 0; i < combination.size() - cnt; i++)
        {
            select.push_back(0);
        }

        sort(select.begin(), select.end());

        vector<int> deleteBracket;

        do
        {
            for (int i = 0; i < select.size(); i++)
            {
                if (select[i] == 1)
                {
                    deleteBracket.push_back(combination[i]);
                }
            }

            string temp = exp;
            for (int i = 0; i < deleteBracket.size(); i++)
            {
                temp[bracketPos[deleteBracket[i]].first] = ' ';
                temp[bracketPos[deleteBracket[i]].second] = ' ';
            }

            temp.erase(remove(temp.begin(), temp.end(), ' '), temp.end());
            ans.insert(temp);
            deleteBracket.clear();

        } while (next_permutation(select.begin(), select.end()));

        cnt++;
        select.clear();
    }

    for (auto it = ans.begin(); it != ans.end(); it++)
        cout << *it << "\n";

    return 0;
}