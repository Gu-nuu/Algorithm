#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;

    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i] == arr[i + 1]) // 한 숫자를 기준으로 잡고 그 다음 숫자가 같은 숫자라면 중복된 경우임
        {
            int temp = arr[i];         // 중복된 숫자를 제거해야 하므로 기준이 되는 숫자를 저장
            while (arr[i + 1] == temp) // 기준이 되는 숫자와 다른 숫자가 나올 때까지 벡터를 탐색하면서 중복되는 숫자일 경우 해당 위치의 값을 모두 -1로 바꿔줌
            {
                arr[i + 1] = -1;
                i++;
            }
        }
    }

    arr.erase(remove(arr.begin(), arr.end(), -1), arr.end()); // 앞에서 -1로 표시한 숫자들(중복되는 숫자)을 모두 벡터에서 지워줌

    for (int i = 0; i < arr.size(); i++)
        answer.push_back(arr[i]);

    return answer;
}

int main()
{
    vector<int> arr = {4, 4, 4, 3, 3};

    vector<int> ans = solution(arr);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}