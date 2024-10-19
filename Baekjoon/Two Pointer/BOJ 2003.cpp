#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

    int N, M;

    cin >> N >> M;

    vector<int> arr;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    int start = 0;
    int end = 0;
    int answer = 0;
    int sum = arr[start];

    while (end < N)
    {
        if (sum < M)
        {
            end++;
            if (end < N)
            {
                sum += arr[end];
            }
        }
        else if (sum > M)
        {
            sum -= arr[start];
            start++;
        }
        else
        {
            sum -= arr[start];
            start++;
            end++;
            if (end < N)
            {
                sum += arr[end];
            }
            answer++;
        }
    }

    cout << answer << "\n";

    return 0;
}