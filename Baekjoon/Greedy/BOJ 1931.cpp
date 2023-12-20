#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
        return a.first < b.first;
    else
        return a.second < b.second;
}

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<pair<int, int>> time; // 희의 시작 시간과 끝나는 시간을 저장하기 위해 pair 객체로 vector를 만든다.

    for (int i = 0; i < N; i++)
    {
        int start, end;
        cin >> start >> end;

        time.push_back({start, end});
    }

    // vector 내에서 정렬을 진행하는데 이때 회의 시작 시간이 아닌 회의가 끝나는 시간을 기준으로 정렬한다.
    // 회의가 아무리 일찍 시작해도 회의 시간이 길어져 늦게 끝나게 되면 가능한 많은 회의를 진행해야 하는 조건에 맞지 않기 때문이다.
    sort(time.begin(), time.end(), compare);

    int temp = time[0].second;
    int count = 1;

    for (int i = 1; i < N; i++)
    {
        if (temp <= time[i].first) // 회의가 끝나는 시간이 회의가 시작하는 시간보다 작을 경우에 해당 회의는 진행이 가능하므로 count 변수를 증가시켜준다.
        {
            temp = time[i].second;
            count++;
        }
    }

    cout << count << "\n";

    return 0;
}