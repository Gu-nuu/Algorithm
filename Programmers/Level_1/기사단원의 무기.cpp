#include <string>
#include <vector>
#include <cmath>

using namespace std;

int findWeapon(int n)
{
    int count = 0;

    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            count++;

            if (i < sqrt(n))
            {
                count++;
            }
        }
    }

    return count;
}

int solution(int number, int limit, int power)
{
    int answer = 0;

    for (int i = 1; i <= number; i++)
    {
        if (findWeapon(i) > limit)
        {
            answer += power;
        }
        else
        {
            answer += findWeapon(i);
        }
    }

    return answer;
}