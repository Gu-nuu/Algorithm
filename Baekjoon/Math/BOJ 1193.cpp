#include <iostream>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int X;
    cin >> X;

    int diagonalCount = 1; // 입력 받은 숫자가 몇번째 대각선에 위치하는지를 저장하는 변수

    // 분수가 위치하는 행과 열을 더한 후 모두 나열했을 때 0,1,1,2,2,2,3,3,3,3,4...와 같은 수열을 이룬다는 것을 알 수 있다.
    // 따라서 0 / 1 1 / 2 2 2 / 3 3 3 3 / ...으로 나눴을 때 이는 각각 첫번째, 두번째, 세번째 대각선을 나타냄을 알 수 있다.
    // 입력 받은 숫자에서 1, 2, 3씩 차례대로 빼다가(diagonalCount) 입력받은 숫자가 빼는 숫자보다 작아지는 그 시점에 빼는 숫자(diagonalCount)가 곧 몇번째 대각선인지를 나타낸다.
    while (X > diagonalCount)
    {
        X -= diagonalCount;
        diagonalCount++;
    }

    // if (diagonalCount % 2 == 1) // 대각선이 홀수번째인지 짝수번째인지에 따라 분모와 분자가 대칭되기 때문에 이를 구분한다.
    //     cout << diagonalCount + 1 - X << "/" << X << "\n";
    // else
    //     cout << X << "/" << diagonalCount + 1 - X << "\n";

    if (diagonalCount % 2 == 1) // 대각선이 홀수번째인지 짝수번째인지에 따라 분모와 분자가 대칭되기 때문에 이를 구분한다.
        cout << diagonalCount - (X - 1) << "/" << X << "\n";
    else
        cout << X << "/" << diagonalCount - (X - 1) << "\n";

    // 솔직히 위 수식은 손으로 계산하다가 연관 관계를 알게 되었는데 해당 수식의 이유는 모르겠다...
    // => 홀수번째 대각선에서는 분자가 감소함에 따라 분모는 증가하고 짝수번째 대각선에서는 분자가 증가함에 따라 분모는 감소한다.

    return 0;
}