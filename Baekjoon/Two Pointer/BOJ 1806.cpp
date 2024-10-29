#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int N, S;

    cin >> N >> S;

    vector<int> v;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }

    int start = 0;
    int end = 0;
    int sum = v[start];
    int length = 987654321;
    while (start <= end && end < N)
    {
        if (sum >= S)
        {
            int cur_length = end - start + 1;
            length = min(cur_length, length);
        }

        if (sum < S)
        {
            end++;
            sum += v[end];
        }
        else
        {
            sum -= v[start];
            start++;
        }
    }

    if (length == 987654321)
    {
        cout << "0\n";
    }
    else
    {
        cout << length << "\n";
    }

    return 0;
}