#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string S;
    cin >> S;

    set<string> part; // 부분 문자열을 저장할 set. 서로 다른 부분 문자열의 개수를 구해야 하므로 중복을 허용하지 않는 set을 선택했다.

    for (int i = 0; i < S.length(); i++)
    {
        // 문자열의 맨 처음 문자부터 길이를 하나씩 늘려가며 부분 문자열을 찾도록 하였다.
        // ex) a -> ab -> aba -> abab -> ababc -> b -> ba -> ...
        // substr 함수는 자르고 싶은 문자열의 길이(두번째 인자)가 현재 문자열(S)의 길이를 넘어가면 자동으로 문자열의 끝까지만 잘라주는 기능이 있고
        // set이 중복 처리를 해주기 때문에 - i를 해줄 필요는 없지만 불필요한 작업을 방지하고 시간 복잡도를 줄이기 위해 - i를 추가해주었다.
        for (int j = 1; j <= S.length() - i; j++)
        {
            part.insert(S.substr(i, j));
        }
    }

    cout << part.size() << "\n";

    return 0;
}