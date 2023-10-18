#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    // 특정 자료를 빠르게 탐색하고 찾아야 하기 때문에 set을 사용하였다.
    // 듣도 못한 사람을 입력받은 후 이를 set에 저장한다.
    set<string> listen;
    for (int i = 0; i < N; i++)
    {
        string name;
        cin >> name;
        listen.insert(name);
    }

    set<string> unheardOf; // 듣도 보도 못한 사람을 저장할 set

    // 보도 못한 사람을 입력받은 후, 듣도 못한 사람의 set에서 입력받은 이름을 찾았을 때 만약 이름이 존재하면 듣도 보도 못한 사람이므로 unheardOf set에 저장해준다.
    for (int i = 0; i < M; i++)
    {
        string name;
        cin >> name;

        if (listen.find(name) != listen.end())
            unheardOf.insert(name);
    }

    cout << unheardOf.size() << "\n";

    for (auto it = unheardOf.begin(); it != unheardOf.end(); it++)
        cout << *it << "\n";

    return 0;
}