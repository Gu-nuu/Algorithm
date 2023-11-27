#include <iostream>
#include <set>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    set<int> note1; // 수첩 1에 적힌 숫자를 저장하기 위한 set

    for (int i = 0; i < T; i++)
    {
        int N;
        cin >> N;

        for (int j = 0; j < N; j++) // set에 수첩 1에 적힌 숫자들을 저장한다.
        {
            int num1;
            cin >> num1;
            note1.insert(num1);
        }

        int M;
        cin >> M;

        for (int j = 0; j < M; j++)
        {
            int num2;
            cin >> num2;

            if (note1.find(num2) != note1.end()) // 수첩 2에 적힌 숫자들이 수첩 1에 적힌 숫자들 중 존재하는지를 확인하고 있다면 1을 출력, 없으면 0을 출력하도록 한다.
            {
                cout << "1\n";
            }
            else
            {
                cout << "0\n";
            }
        }

        note1.clear(); // 테스트 케이스가 여러 개일 경우 set을 초기화시켜 사용한다.
    }

    return 0;
}