#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

string decimal_to_binary(int num) // 10진수를 2진수로 변환하여 string 형태로 반환하는 함수
{
    string bin = "";

    while (true)
    {
        bin = to_string(num % 2) + bin;

        if (num / 2 == 0)
            break;
        else
            num /= 2;
    }

    return bin;
}

int oneCounter(string num) // string 형태의 2진수 값에서 1의 갯수를 세는 함수
{
    int cnt = 0;
    for (int i = 0; i < num.size(); i++)
    {
        if (num[i] == '1')
            cnt++;
    }

    return cnt;
}

int solution(int n)
{
    int answer = 0;

    int oneCnt = oneCounter(decimal_to_binary(n)); // 주어진 숫자를 2진수로 변환 후 1의 갯수를 세서 저장

    while (true)
    {
        n++; // 주어진 숫자 n보다 큰 숫자이므로 숫자를 하나씩 증가시키면서 탐색

        if (oneCnt == oneCounter(decimal_to_binary(n))) // 주어진 숫자 n의 1의 갯수와 n에서 숫자를 1씩 늘려가면서 얻은 숫자의 2진수의 1의 갯수가 같다면 반복문을 break
        {
            answer = n;
            break;
        }
    }

    return answer;
}

int main()
{
    int n = 78;

    cout << solution(n) << endl;

    return 0;
}