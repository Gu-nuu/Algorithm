#include <iostream>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    // 처음에는 에라토스테네스의 체와 비슷하다고 생각해서 이를 직접 구현해서 하려했으나 N의 범위가 너무 커서 시간 초과 또는 메모리 초과가 날 거 같았다.
    // 직접 1부터 규칙을 찾아보려고 했고,
    // N이 1부터 3일 땐 열린 창문은 1개, N이 4부터 8일 때는 열린 창문이 2개가 되었다.
    // 따라서 열린 창문의 갯수는 제곱수마다 1개씩 늘어나게 되므로 입력받은 숫자 이전의 제곱수들의 개수를 알 수 있다면 열린 창문의 개수를 알 수 있게 된다.

    int count = 0;
    for (int i = 1; i * i <= N; i++)
    {
        count++;
    }

    cout << count << "\n";

    return 0;
}