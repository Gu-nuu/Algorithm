#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n)
{
    int answer = 0;

    // 500번의 횟수가 넘어가는 테스트케이스의 경우에 시간 초과가 나는데 문제 상의 오류로 보인다.
    // 인자로 들어오는 int 값을 long long 타입으로 변형해주면 문제가 해결된다.
    long long num = n;

    while (num != 1)
    {
        if (answer == 500)
            break;

        if (num % 2 == 0)
        {
            num /= 2;
            answer++;
        }
        else if (num % 2 == 1)
        {
            num *= 3;
            num += 1;
            answer++;
        }
    }

    if (answer == 500)
        answer = -1;

    return answer;
}

int main()
{
    int num = 6;

    cout << solution(num) << endl;

    return 0;
}