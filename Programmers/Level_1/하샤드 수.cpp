#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solution(int x)
{
    bool answer = true;

    int sum = 0;
    int temp = x; // 각 자릿수의 합을 구하기 위해 숫자를 나눠야하므로 기존의 숫자를 보존하기 위해 temp 변수로 계산을 진행

    while (true)
    {
        sum = sum + (temp % 10); // 나눈 자릿수의 합을 저장

        if (temp / 10 == 0)
            break;
        else
            temp /= 10;
    }

    if (x % sum != 0)
        answer = false;

    return answer;
}

int main()
{
    int x = 12;

    cout << solution(x) << endl;

    return 0;
}