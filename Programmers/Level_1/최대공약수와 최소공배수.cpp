#include <string>
#include <vector>
#include <iostream>

using namespace std;

int gcd(int x, int y) // 최대공약수 : 유클리드 호제법을 이용
{
    int z;
    while (y != 0)
    {
        z = x % y;
        x = y;
        y = z;
    }

    return x;
}

int lcm(int x, int y) // 최소공배수 : a * b = 최대공약수(a, b) * 최소공배수(a, b)의 증명된 공식을 이용
{
    return (x * y) / gcd(x, y);
}

vector<int> solution(int n, int m)
{
    vector<int> answer;

    answer.push_back(gcd(n, m));

    answer.push_back(lcm(n, m));

    return answer;
}

int main()
{
    int n = 2;
    int m = 5;

    vector<int> ans = solution(n, m);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}