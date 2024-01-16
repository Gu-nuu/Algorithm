#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 백준 13164 문제와 같은 방법으로 해결했다.
// 각 센서들의 좌표 값을 받은 뒤 오름차순으로 정렬하고 인접한 센서들의 좌표 값 차이를 구해 저장한다.
// 센서의 좌표 값 차이는 센서가 K개일 때 k-1개가 나오게 된다. 그리고 해당 좌표 값 차이를 오름차순으로 정렬한다.
// 오름차순으로 정렬한 좌표 값 차이에서 N-K개의 좌표 값 차이를 더하게 되면 각 집중국의 최소 수신 가능 거리를 구할 수 있게 된다.
// 이때 N-K개의 정렬된 좌표 값 차이를 구하는 이유는 만약 집중국의 갯수가 2개이며 센서의 좌표의 갯수가 6개라면 좌표 사이의 거리, 즉 경계의 갯수는 5개가 나오게 되는데
// 집중국의 갯수만큼 센서의 좌표를 묶게 되므로 묶어진 두 그룹 사이의 좌표 차이 값은 필요가 없게 된다. 따라서 N-K개의 좌표 차이를 구하게 되면 원하는 값을 얻을 수 있게 된다.
// ex) 센서 = {1, 3, 6, 6, 7, 9}, 집중국 = 2 => 집중국이 2개이므로 2개의 그룹으로 나눈다 => {1, 3}, {6, 6, 7, 9} => 이때 3과 6 사이의 경계값은 필요없게 된다.
int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N;
    cin >> K;

    vector<int> coordinate;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;

        coordinate.push_back(num);
    }

    sort(coordinate.begin(), coordinate.end());

    vector<int> gap;

    for (int i = 1; i < coordinate.size(); i++)
    {
        gap.push_back(coordinate[i] - coordinate[i - 1]);
    }

    sort(gap.begin(), gap.end());

    int ans = 0;

    for (int i = 0; i < N - K; i++)
    {
        ans += gap[i];
    }

    cout << ans << "\n";

    return 0;
}