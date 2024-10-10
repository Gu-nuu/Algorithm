#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    int round = 1;

    if (a > b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    while (true)
    {

        if (a + 1 == b && a % 2 == 1)
        {
            break;
        }

        if (a % 2 != 0)
        {
            a = a / 2 + 1;
        }
        else
        {
            a = a / 2;
        }

        if (b % 2 != 0)
        {
            b = b / 2 + 1;
        }
        else
        {
            b = b / 2;
        }

        round++;
    }

    answer = round;
    return answer;
}