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

    stack<pair<char, int>> s;          // 괄호의 위치 index를 저장할 stack
    vector<pair<int, int>> bracketPos; // 괄호 한쌍의 위치 index를 저장할 vector

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

    // 우선 괄호의 위치 값을 index 값으로 파악한 뒤 이를 조합으로 뽑아내어 괄호 쌍을 제거하여 나올 수 있는 모든 경우의 수를 구할 수 있도록 하였다.
    // 예를 들어 괄호 쌍이 2개가 존재할 경우 나올 수 있는 경우의 수는 총 3가지가 되는데 이는 2C1 + 2C2로 계산된다.
    // 마찬가지로 괄호 쌍이 3개가 존재할 경우 나올 수 있는 경우의 수는 총 7가지로 3C1 + 3C2 + 3C3이 된다.

    vector<int> combination;

    for (int i = 0; i < bracketPos.size(); i++)
    {
        combination.push_back(i); // 괄호 쌍의 위치 값이 저장되어 있는 vector를 기반으로 배열의 index를 조합으로 뽑아내도록 하기 위해 0부터 괄호 쌍 위치를 저장한 vector의 크기만큼의 수를 저장해준다.
    }

    vector<int> select; // STL에 있는 next_permutation 함수를 이용하여 조합을 구하기 위해서는 0과 1로 이루어진 같은 크기의 vector 한 쌍이 더 필요하다.
    int cnt = 1;        // 한가지 조합에 대한 계산이 아닌 괄호 쌍에 따라 구해야 하는 조합의 계산이 늘어나기 때문에 cnt 변수로 이를 관리하였다.

    set<string> ans; // 정답은 사전 순으로 나열하여 출력해야 하기 때문에 set을 이용하여 저장할 때 바로 정렬될 수 있도록 하였다.

    while (cnt <= combination.size())
    {
        // 우선 select vector에 0과 1로 수를 채워준다. 만약 2C1을 계산할 경우 벡터에는 {0, 1}, 3C2를 계산할 경우 벡터에는 {0, 1, 1}이 들어가야 한다. nCr에서 select 배열의 크기를 n만큼 맞춰주고
        // 뽑고자 하는 수(r)의 크기만큼 1을 채워주고 나머지 공간을 0으로 채워준다.
        for (int i = 0; i < cnt; i++)
        {
            select.push_back(1);
        }

        for (int i = 0; i < combination.size() - cnt; i++)
        {
            select.push_back(0);
        }

        sort(select.begin(), select.end());

        vector<int> deleteBracket; // 조합으로 뽑은 숫자를 통해 괄호 쌍을 제거하며 삭제해야할 괄호 쌍의 위치를 저장할 vector

        do
        {
            for (int i = 0; i < select.size(); i++)
            {
                if (select[i] == 1)
                {
                    deleteBracket.push_back(combination[i]);
                }
            }

            // 원본 괄호식을 temp에 복사한 뒤, 조합 계산을 통해 뽑은 수를 이용해 괄호 쌍 위치의 index에 접근하여 괄호 쌍을 제거해나간다.
            // 이때 괄호 쌍 제거는 index를 기반으로 이루어지기 때문에 전체 string 길이 값에 변화가 생기면 안된다.
            // 따라서 지우고자 하는 괄호 쌍으로 공백으로 우선 바꾸고, 계산이 끝나면 공백을 제거해 최종적인 제거 값을 구한다.
            // 계산이 끝나면 새로운 조합 값을 저장해야 하기 때문에 vector를 초기화해준다.
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

        cnt++;          // 괄호 쌍 갯수에 따라 조합 계산이 늘어나게 되므로 cnt를 증가시켜준다.
        select.clear(); // 마찬가지로 새로운 조합 계산을 해야하기 때문에 select vector도 초기화 시켜준다.
    }

    for (auto it = ans.begin(); it != ans.end(); it++)
        cout << *it << "\n";

    return 0;
}