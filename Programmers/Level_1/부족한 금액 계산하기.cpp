#include <iostream>

using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1; // 주어지는 숫자의 곱을 반복할 경우 int형의 범위를 넘어서게 되는 경우가 발생하므로 미리 형을 변환

    long long temp = 0;
    for (int i = 0; i < count; i++)
        temp = temp + (price * (i + 1));

    if (temp - money > 0)
        answer = temp - money;
    else
        answer = 0;

    return answer;
}

int main()
{
    int p = 3;
    int m = 30;
    int c = 4;

    cout << solution(p, m, c);

    return 0;
}