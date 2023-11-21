#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    map<string, int> m; // 참가자와 완주 여부를 저장하기 위한 map

    for (int i = 0; i < N; i++)
    {
        string name;
        cin >> name;

        // 처음으로 등장한 이름이라면 이름과 함께 1을 저장한다.
        // 동명이인이 있을 수도 있기 때문에 만약 이미 존재하는 이름이라면 함께 저장된 변수를 1 증가시킨다.
        if (m.find(name) == m.end())
        {
            m.insert({name, 1});
        }
        else
        {
            m.find(name)->second++;
        }
    }

    for (int i = 0; i < N - 1; i++)
    {
        string complete;
        cin >> complete;

        m.find(complete)->second--; // 완주한 사람의 경우 함께 저장된 변수를 1 감소시킨다.
    }

    // 위 연산을 마치고 나면 완주하지 못한 사람은 0이라는 값을 절대 가질 수가 없다.
    // 동명이인의 경우에도 한 명만 완주하고 한 명만 완주하지 못하는 경우도 있지만 이때도 0이라는 값을 갖지 못한다.
    for (auto it = m.begin(); it != m.end(); it++)
    {
        if (it->second != 0)
        {
            cout << it->first << "\n";
            break;
        }
    }

    return 0;
}