#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n)
{
    int answer = 0;

    vector<int> box; // 3진법으로 변환된 수들을 담을 벡터

    // 10진법 -> 3진법 : 3으로 나눈 나머지를 벡터로 담는다. 이때 나눈 나머지가 자기 자신이 될 경우 끝까지 나누어서 계산을 멈춰야 하는 경우이므로
    // 이 경우 반복문을 break하며 그 경우가 아니라면 수를 계속 3으로 나눠준다. 이 때 vector에 담겨있는 수는 이미 앞뒤 반전이 되어 있는 상태이다.
    while (true)
    {
        box.push_back(n % 3);

        if (n % 3 == n)
            break;
        else
            n /= 3;
    }

    for (int i = 0; i < box.size(); i++)
    {
        if (box[i] == 0) // 0이면 계산해줄 필요가 없으므로 continue
            continue;

        answer = answer + (box[i] * (pow(3, box.size() - i - 1))); // 3진법 -> 10진법 : 숫자 * 해당 자릿수 ^ 3을 해주어 10진법으로 변환한다.
    }

    return answer;
}

int main()
{
    int n = 125;

    cout << solution(n) << endl;

    return 0;
}