#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n)
{
    vector<int> answer;

    while (true)
    {
        answer.push_back(n % 10);

        if (n / 10 == 0)
            break;
        else
            n /= 10;
    }

    return answer;
}

int main()
{
    long long n = 12345;

    vector<int> ans = solution(n);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}