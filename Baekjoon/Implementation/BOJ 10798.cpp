#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string box[5]; // 문자열을 저장하는 변수

    for (int i = 0; i < 5; i++) // 한 줄씩 문자열을 입력받는다.
    {
        cin >> box[i];
    }

    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i < box[j].length()) // 제일 긴 문자열에 비해 짧은 문자열도 존재하기 때문에 i 범위를 모두 출력하면 빈 값을 출력하게 되므로 입력받은 문자열의 최대 길이를 넘지 않도록 조건을 만들어 출력한다.
                cout << box[j][i];
        }
    }

    cout << "\n";

    return 0;
}