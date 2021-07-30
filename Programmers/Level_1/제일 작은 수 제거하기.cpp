#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;

    int min_index = 0;

    for (int i = 1; i < arr.size(); i++) // 가장 작은 수를 찾으면 해당 수의 index 값을 저장
    {
        if (arr[min_index] > arr[i])
            min_index = i;
    }

    arr.erase(arr.begin() + min_index); // 가장 작은 수의 index를 이용하여 값을 제거

    if (arr.size() == 0)
        answer.push_back(-1);
    else
        answer = arr;

    return answer;
}

int main()
{
    vector<int> arr = {10};

    vector<int> ans = solution(arr);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}