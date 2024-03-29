#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 기존의 3진법과 크게 다르지 않다. 3의 배수를 제외한 나머지 숫자들은 3진법으로 변환했을 때와 값이 같고 3의 배수일 경우에만 값이 달라지는데
// 이는 숫자 0이 존재하면 안되기 떄문이다. 따라서 만약 3의 배수일 경우 기존의 3진법처럼 몫을 그대로 두고 나머지를 추가하는 것이 아니라
// 3으로 나눠져서 나머지인 0이 추가되지 않도록 몫에서 1을 빼고 나머지인 0 대신 4를 추가해주어야 한다.
string solution(int n)
{
    string answer = "";

    while (n != 0)
    {
        int temp = n % 3; // 수를 3으로 나눈 후 나머지
        n /= 3;           // 수를 3으로 나눈 후 몫

        if (temp == 0) // 나머지가 0인 경우(3의 배수일 경우)
        {
            n -= 1;                // 구한 몫에서 1을 빼줌
            answer = "4" + answer; // 4를 더해줌
        }
        else
            answer = to_string(temp) + answer;
    }

    return answer;
}
// ex) 9 ==> 기존의 3진법의 경우 100.
// 하지만 이 문제에서는 9를 나눴을 때 3이라는 몫과 0이라는 나머지가 나왔을 경우 기존처럼 나머지인 0을 추가하지 않고 몫에서 1을 빼고 0 대신 4를 추가한다.
// 그러면 첫 반복문에서 4가 추가되어 있는 상태이며 n(몫) 값은 2가 된다. 다음 반복문에서 다시 2에 대해 3으로 나눈 몫과 나머지를 구하면 나머지는 2, 몫은 0이 된다.
// 따라서 나머지는 0이 아니므로 두 번째 조건문에 의해 2가 추가되어 24라는 숫자가 완성되며 while 문에 조건에 의해 n(몫)은 0이 되므로 계산을 종료한다.

int main()
{
    int n = 9;

    cout << solution(n) << endl;

    return 0;
}