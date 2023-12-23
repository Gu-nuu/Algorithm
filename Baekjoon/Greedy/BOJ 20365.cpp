#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    string color;
    cin >> color;

    int cnt_B, cnt_R; // R과 B의 갯수를 셀 변수.

    // 맨 처음 문제의 색깔을 보고 변수의 갯수를 지정한다.
    if (color[0] == 'B')
    {
        cnt_B = 1;
        cnt_R = 0;
    }
    else if (color[0] == 'R')
    {
        cnt_B = 0;
        cnt_R = 1;
    }

    // R과 B의 갯수를 세어 저장한다. 이때 현재 문제의 색깔과 바로 이전의 문제의 색깔이 같다면 한번에 칠할 수 있기 때문에 하나의 색깔로 간주한다.
    // 그리디 알고리즘의 관점에서 접근할 때, 일단 같은 색깔로 모두 칠한 다음, 색깔 수가 적은 것만 따로 칠할 경우에 가장 최소의 횟수로 색깔을 칠할 수 있다.
    // 따라서 색깔이 적은 문제의 갯수 + 1을 하게 되면 최소 횟수가 나오게 된다.
    for (int i = 1; i < N; i++)
    {
        if (color[i] == 'B')
        {
            if (color[i - 1] != 'B')
                cnt_B++;
        }
        else if (color[i] == 'R')
        {
            if (color[i - 1] != 'R')
                cnt_R++;
        }
    }

    if (cnt_B >= cnt_R)
        cout << cnt_R + 1 << "\n";
    else
        cout << cnt_B + 1 << "\n";

    return 0;
}