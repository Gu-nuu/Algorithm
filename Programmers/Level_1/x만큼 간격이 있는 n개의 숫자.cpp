#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n)
{
    vector<long long> answer;

    int temp = x;
    for (int i = 0; i < n; i++)
    {
        answer.push_back(temp);
        temp = temp + x;
    }

    return answer;
}

int main()
{
    int x = 2;
    int n = 5;

    vector<long long> ans = solution(x, n);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}