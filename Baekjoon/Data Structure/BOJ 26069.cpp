#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    set<string> rainbowDance; // 무지개 댄스를 춘 사람을 저장할 set. 한번 추기 시작했으면 또 추지 않으므로 중복이 없어야 해서 set을 선택했다.

    for (int i = 0; i < N; i++)
    {
        string nameA, nameB;
        cin >> nameA >> nameB;

        if (nameA == "ChongChong" || nameB == "ChongChong") // 총총이는 무지개 댄스를 추게 된 이후부터 사람들이 따라하기 시작하므로 총총이를 발견하면 옆 사람과 총총이를 set에 저장한다.
        {
            rainbowDance.insert(nameA);
            rainbowDance.insert(nameB);
        }

        if (rainbowDance.find(nameA) != rainbowDance.end()) // 무지개 댄스를 춘 사람이 나오면 그 옆 사람도 따라 추기 때문에 옆 사람을 set에 저장한다.
        {
            rainbowDance.insert(nameB);
        }
        else if (rainbowDance.find(nameB) != rainbowDance.end())
        {
            rainbowDance.insert(nameA);
        }
    }

    cout << rainbowDance.size() << "\n";

    return 0;
}