#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int countA, countB;
    cin >> countA >> countB;

    set<int> A;

    for (int i = 0; i < countA; i++) // 집합 A를 저장할 set을 만들어주고 원소를 입력받아 set에 저장한다.
    {
        int num;
        cin >> num;

        A.insert(num);
    }

    set<int> B;
    for (int i = 0; i < countB; i++) // 집합 B를 저장할 set을 만들어주고 입력받는 과정에서 바로 차집합을 계산하여 집합 A와 B에 바로 적용시켜준다.
    {
        int num;
        cin >> num;

        if (A.find(num) != A.end()) // 만약 집합 B에 있는 원소가 집합 A에도 있는 경우 이는 교집합에 포합된 원소이므로 집합 A에서 이를 제거해준다.
            A.erase(num);
        else // 만약 집합 A에 존재하지 않는 원소인 경우 집합 B에만 존재하는 원소이기 때문에 집합 B에 넣어준다.
            B.insert(num);
    }

    cout << A.size() + B.size() << "\n"; // 위 과정을 거치고 나면 교집합을 제외한 차집합들만 남기 때문에 바로 집합 A와 집합 B의 개수를 더해준다.

    return 0;
}