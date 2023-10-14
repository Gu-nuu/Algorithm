#include <iostream>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a_1, a_0, c, n_0;

    cin >> a_1 >> a_0;
    cin >> c;
    cin >> n_0;

    // 모든 n >= n_0에 대해 f(n)이 만족해야 하므로 해당 조건을 만족하지 않으면 O(n)의 정의를 만족하지 못한다.
    // 2번째 조건은 처음에는 찾지 못한 조건이었는데, 입력 조건에서 a_i는 절댓값으로 0 ~ 100이기 때문에(?)
    // a_1 * n + a_0 <= c * n 에서
    // (a_1 - c) n + a_0 <= 0 로 정리하게 되면
    // (a_1 - c)이 양수가 될 경우 조건식을 절대 만족하지 않기 때문에
    // a_1 - c <= 0 이 추가로 조건으로 붙어야 한다.
    if (c * n_0 >= a_1 * n_0 + a_0 && a_1 <= c)
        cout << 1 << "\n";
    else
        cout << 0 << "\n";

    return 0;
}