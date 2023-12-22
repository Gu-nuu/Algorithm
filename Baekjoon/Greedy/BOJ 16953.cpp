#include <iostream>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int A, B;
    cin >> A >> B;

    int step = 0; // 연산 횟수를 저장할 변수

    // A -> B로 가는 연산횟수를 알기 위해 역으로 B에서 계산했을 때 A를 만드는 방법을 이용했다.
    // B가 2로 나눠지거나 10으로 나눴을 때 나머지가 1이 나오게 된다면 연산 방법을 만족하는 것이므로 B를 나눠주어 A에 가까워지도록 만들었다.
    // 만약 연산을 반복하며 step 변수를 1씩 증가시키고 A라는 숫자가 나오면 해당 step 변수에 +1한 값을 출력하고 반복문을 종료시킨다.
    // 만약 연산을 반복하다가 B가 A보다 작아지는 경우 또는 더 이상 나눠지지 않는 경우에는 A에서 B로 만들 수 없는 경우이므로 -1을 출력하고 반복문을 종료한다.
    while (1)
    {
        if (A == B)
        {
            cout << step + 1 << "\n";
            break;
        }
        else if (A > B)
        {
            cout << "-1\n";
            break;
        }
        else if (B % 2 == 0)
        {
            B /= 2;
            step++;
        }
        else if (B % 10 == 1)
        {
            B--;
            B /= 10;
            step++;
        }
        else
        {
            cout << "-1\n";
            break;
        }
    }

    return 0;
}