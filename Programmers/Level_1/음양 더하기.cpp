#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs)
{
    int answer = 123456789;

    for (int i = 0; i < absolutes.size(); i++)
    {
        if (signs[i] == false)
            absolutes[i] = -absolutes[i];
    }

    int temp = 0;
    for (int i = 0; i < absolutes.size(); i++)
        temp += absolutes[i];

    answer = temp;

    return answer;
}

int main()
{
    vector<int> absolutes = {1, 2, 3};
    vector<bool> signs = {false, false, true};

    int ans = solution(absolutes, signs);

    cout << ans << endl;

    return 0;
}