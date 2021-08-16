#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    int answer = 0;

    // 이중 for문을 이용하여 숫자를 하나씩 늘려가면서 연속된 숫자들의 합을 계산
    for (int i = 1; i <= n; i++)
    {
        int temp = 0;
        for (int j = i; j <= n; j++)
        {
            temp += j;

            if (temp == n) // 연속된 숫자의 합이 주어진 숫자 n이 되면 answer를 증가시킨 후 break
            {
                answer++;
                break;
            }
            else if (temp > n) // 계산을 하다가 주어진 숫자 n을 넘어가면 더 계산할 필요가 없으므로 break
                break;
        }
    }

    return answer;
}

int main()
{
    int n = 15;

    cout << solution(n) << endl;

    return 0;
}
