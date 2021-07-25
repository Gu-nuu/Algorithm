#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    int answer = 0;

    vector<bool> box(n + 1); // 에라토스테네스의 체를 이용하지 않으면 시간초과에 걸린다.

    for (int i = 2; i <= n; i++)
    {
        if (box[i]) // 지워진 배수들은 검사하지 않아도 된다.
            continue;

        for (int j = i * 2; j <= n; j += i) // 2부터 구하고자 하는 수까지 반복문을 돌리면서 해당 수의 배수들을 지운다.
            box[j] = true;
    }

    for (int i = 2; i <= n; i++) // 배수들을 지우고 남은 수들은 자동적으로 소수가 된다.
    {
        if (!box[i])
            answer++;
    }

    return answer;
}

int main()
{
    int n = 10;

    cout << solution(n) << endl;

    return 0;
}