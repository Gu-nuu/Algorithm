#include <iostream>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    // 처음에는 vector로 구현했다가 시간 초과가 나서 다른 자료 구조를 고민하게 되었다.
    // 특졍 자료를 탐색하고 이를 지우는데에는 vector보다 set이 시간복잡도 상 O(logn)으로 훨씬 효율적이기 때문에 set으로 다시 구현하였다.
    // set은 자료를 삽입할 때부터 기본적으로 오름차순 정렬이 되지만 결과는 내림차순으로 출력해야 하므로 greater<> 인자를 통해 내림차순으로 만들어주었다.
    set<string, greater<string>> company;

    for (int i = 0; i < n; i++) // 사람 이름과 출입 여부를 입력받고 만약 출입 여부가 enter일 경우 set에 사람 이름을 추가해주고 leave일 경우 이를 찾아 삭제한다.
    {
        string person, record;
        cin >> person >> record;

        if (record == "enter")
            company.insert(person);
        else
            company.erase(person);
    }

    for (auto it = company.begin(); it != company.end(); it++)
        cout << *it << "\n";

    return 0;
}