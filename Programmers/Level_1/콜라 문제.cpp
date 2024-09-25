#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n)
{
    int answer = 0;

    while (a <= n)
    {
        int left_coke = (n % a);
        int drink_coke = (n / a);
        n = drink_coke * b + left_coke;   // 마시고 나온 빈 병으로 마트에서 받은 콜라의 수 + 남아있던 콜라의 수
        answer = answer + drink_coke * b; // 마신 콜라의 수
    }

    return answer;
}