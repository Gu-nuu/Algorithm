#include <iostream>
#include <vector>
using namespace std;

// https://programmers.co.kr/questions/11991
// 우선적으로 피보나치 수를 구하는 문제라고 했을 때, 재귀함수를 이용하면 시간 초과 or 스택오버플로우에 걸릴 것이라고 판단하여
// 동적 프로그래밍으로 문제를 해결하기로 했다. n번째 피보나치 수를 구한 후 이를 1234567로 나눈 나머지를 answer에 저장했는데
// 이미 10번째 피보나치 수부터는 int의 범위를 벗어나기 때문에 10번째 이상의 피보나치 수부터는 이미 오류가 나게 된다.
// 따라서 미리 1234567로 나눈 나머지를 저장해줌으로써 문제를 해결하였다.
int solution(int n)
{
    int answer = 0;

    int fibonacci[100001];

    fibonacci[0] = 0;
    fibonacci[1] = 1;

    for (int i = 2; i <= n; i++)
        fibonacci[i] = (fibonacci[i - 1] + fibonacci[i - 2]) % 1234567;

    answer = fibonacci[n];

    return answer;
}

int main()
{
    int n = 5;

    cout << solution(n) << endl;

    return 0;
}