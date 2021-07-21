#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b)
{
    long long answer = 0;

    int var1 = 0;
    int var2 = 0;

    if (a >= b)     // 주어지는 a와 b 값의 대소 관계가 정해지지 않았으므로 두 값을 비교하여 var1에 큰 수를, var2에 작은 수를 저장
    {
        var1 = a;
        var2 = b;
    }
    else
    {
        var1 = b;
        var2 = a;
    }

    for (int i = var2; i <= var1; i++)
        answer += i;

    return answer;
}

int main()
{
    int a = 3;
    int b = 3;

    cout << solution(a, b) << endl;

    return 0;
}