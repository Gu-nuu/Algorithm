#include <iostream>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    // 그리디 알고리즘을 이용해 해결하는 문제이다. 따라서 동전을 최소 갯수로 사용하면서 거스름돈을 거슬러 주기 위해서는 큰 단위의 동전부터 먼저 사용해야 한다.
    // 5원짜리 동전을 최대한 많이 사용한 뒤 남은 금액을 2원짜리 동전으로 채웠을 때 거스름돈을 만족한다면 이를 최소 갯수로 계산하도록 하였다.

    int cnt_5 = n / 5;                 // 거스름돈을 넘지 않으면서 최대로 사용한 5원짜리 동전의 갯수
    int cnt_2 = (n - (5 * cnt_5)) / 2; // 5원짜리 동전을 최대로 사용한 뒤 남은 금액을 채울 때의 2원짜리 동전의 갯수

    if (n % 5 == 0) // 만약 5원짜리 동전으로 거스름돈을 모두 거슬러 줄 수 있다면 최소 갯수로 동전을 사용한 것이 된다.
    {
        cout << cnt_5 << "\n";
    }
    else
    {
        // 5원짜리 동전의 최대 사용 갯수부터 1씩 줄여나가면서 남은 금액을 2원짜리 동전으로 채울 수 있는지를 확인했다.
        // 만약 5원짜리 동전의 갯수가 음수가 되면 해당 거스름돈은 거슬러 줄 수 없으므로 -1을 출력하도록 하였다.
        while (cnt_5 >= 0)
        {
            int cal = (n - (5 * cnt_5)) % 2; // 5원짜리 동전과 2원짜리 동전을 사용했을 때 0이 나온다면 해당 거스름돈은 거슬러 줄 수 있다.

            if (cal == 0)
            {
                cnt_2 = (n - (5 * cnt_5)) / 2;
                break;
            }
            else // 만약 결과값이 0이 나오지 않는다면 5원짜리 동전의 갯수를 하나 줄여 다시 계산할 수 있도록 한다.
            {
                cnt_5--;
            }
        }

        if (cnt_5 < 0)
            cout << "-1\n";
        else
            cout << cnt_5 + cnt_2 << "\n";
    }

    return 0;
}