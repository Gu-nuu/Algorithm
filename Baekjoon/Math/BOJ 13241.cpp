#include <iostream>
using namespace std;

int main()
{
    long long int A, B;

    cin >> A >> B;

    long long int quotient;         // 두 수룰 나눈 뒤의 몫
    long long int remainder;        // 두 수를 나눈 뒤의 나머지
    long long int multiple = A * B; // 두 수의 곱은 최대공약수와 최소공배수의 곱과 같으며 이를 이용해 최대 공약수를 구한 뒤 최소 공배수를 구해야 하므로 두 수의 곱을 미리 구한다.
    long long int GCD;

    if (A > B) // 입력 받은 두 수 중 작은 수로 큰 수를 나눠야 하기 때문에 이를 구분한다.
    {
        // 유클리드 호제법을 이용해 최대 공약수를 구한다.
        // A를 B로 나눠 나머지(remainder)를 구한 뒤 B를 다시 나머지(remainder)로 나눠 새로운 나머지(remainder')를 구한다.
        // 이를 계속 반복하다가 나머지가 0이 되는 순간에 나누는 수가 최대공약수가 된다.

        while (B != 0) // 반복문 내에서 나누는 수(B)에 나머지(remainder)를 대입하므로 B가 0이 되는지의 여부를 판단해야 한다.
        {
            quotient = A / B;
            remainder = A % B;
            A = B;         // 나누는 수(B)를 다시 나눠지는 수(A)에 대입한다.
            B = remainder; // 나머지(remainder)를 나누는 수(B)에 대입한다
        }

        GCD = A; // 나누는 수(B)를 나눠지는 수(A)에 대입한 후 반복문이 종료되므로 A 값이 곧 최대공약수가 된다.
    }
    else
    {
        while (A != 0) // B가 더 클 경우는 A와 B의 순서를 바꿔 계산한다.
        {
            quotient = B / A;
            remainder = B % A;
            B = A;
            A = remainder;
        }

        GCD = B;
    }

    cout << multiple / GCD << "\n"; // 두 수의 곱은 최대공약수와 최소공배수의 곱과 같으므로 두 수의 곱에서 최대공약수를 나눠주면 최소공배수를 구할 수 있다.

    return 0;
}