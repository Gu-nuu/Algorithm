#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b)
{
    int answer = 1234567890;

    int temp = 0;
    for (int i = 0; i < a.size(); i++)
        temp += (a[i] * b[i]);

    answer = temp;

    return answer;
}

int main()
{
    vector<int> a = {1, 2, 3, 4};
    vector<int> b = {-3, -1, 0, 2};

    int ans = solution(a, b);

    cout << ans << endl;
}