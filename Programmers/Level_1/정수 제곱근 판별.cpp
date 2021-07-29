#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n)
{
    long long answer = 0;

    long long temp = (long long)sqrt(n); // 제곱근을 구함

    if (pow(temp, 2) == n) // 해당 수를 다시 제곱하여 원래의 수가 나오는지를 확인
        answer = pow(temp + 1, 2);
    else
        answer = -1;

    return answer;
}

int main()
{
    long long n = 121;

    cout << solution(n) << endl;

    return 0;
}