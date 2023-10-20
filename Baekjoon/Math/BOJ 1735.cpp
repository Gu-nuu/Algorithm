#include <iostream>
using namespace std;

int getGCD(int a, int b)
{
    int c;

    if (a > b)
    {
        while (b != 0)
        {
            c = a % b;
            a = b;
            b = c;
        }

        return a;
    }
    else
    {
        while (a != 0)
        {
            c = b % a;
            b = a;
            a = c;
        }

        return b;
    }
}

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int numerator1, numerator2, denominator1, denominator2; // 각각 분자1, 분자2, 분모1, 분모2를 입력받을 변수

    cin >> numerator1 >> denominator1;

    cin >> numerator2 >> denominator2;

    // int originDenominator1 = denominator1; // 유클리드 호제법을 이용해 계산하면 두 수의 값이 바뀌게 되므로 원래 값을 저장해준다.
    // int originDenominator2 = denominator2;

    int multiple = denominator1 * denominator2; // 두 수의 곱은 두 수의 최대공약수와 최소공배수의 곱과 같음을 이용해 최소공배수를 구한다.
    int quotient, remainder;                    // 몫, 나머지
    int GCD, LCM;                               // 최대공약수, 최소공배수

    // 두 분수를 합할 때는 분모를 통분해주는 과정이 필요한데 이때 두 분모는 최소공배수 값으로 통분되어야 하므로
    // 유클리드 호제법을 이용해 최대공약수를 구하고 이를 통해 최소공배수를 구한다.

    GCD = getGCD(denominator1, denominator2);

    LCM = multiple / GCD; // 두 수의 곱은 최소공배수와 최대공약수의 곱과 같으므로 두 수의 곱을 최대공약수로 나눠 최소공배수를 구한다.

    // 최소공배수를 분모로 나눈 뒤 분자에 곱해주면 두 분모의 최소공배수로 분모를 통분한 뒤 분자 값이 된다.
    // 처음에는 여기에서 계산을 마무리했는데 약분하는 과정을 빼먹어서 문제를 틀렸다.
    // 통분해서 구한 분수는 기약분수가 아닐 수도 있기 때문에 분자와 분모의 최대공약수를 다시 구해 이를 분자와 분모에 각각 나눠주게 되면 기약분수 형태인 최총 값을 얻을 수 있다.

    int afterNumerator = (LCM / denominator1) * numerator1 + (LCM / denominator2) * numerator2;
    int afterDenominator = LCM;

    cout << afterNumerator / getGCD(afterNumerator, afterDenominator) << " " << afterDenominator / getGCD(afterNumerator, afterDenominator) << "\n";

    return 0;
}