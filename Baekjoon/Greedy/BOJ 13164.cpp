#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;

    vector<int> height; // 원생의 키를 저장할 벡터

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;

        height.push_back(num);
    }

    vector<int> heightGap; // 인접한 원생의 키 차이를 계산해 저장할 벡터

    for (int i = 1; i < N; i++)
    {
        heightGap.push_back(height[i] - height[i - 1]);
    }

    // N명의 원생들을 K개의 조로 나누게 될 때 인접한 원생들의 키 차이의 갯수, 즉 경계의 갯수는 K-1개가 된다.
    // 이때 가장 최소한의 비용을 구하기 위해서는 경계의 값들 중 가장 큰 값부터 K개를 제외시킨 나머지를 더해주면 된다.
    // 이때 정렬 후 K개를 제외 시키는 이유는 키가 큰 원생들은 그룹을 따로 한 명씩만 묶어 비용에서 제외시킬 수 있기 때문이다.
    sort(heightGap.begin(), heightGap.end());

    int cost = 0;

    for (int i = 0; i < N - K; i++)
    {
        cost += heightGap[i];
    }

    cout << cost << "\n";

    return 0;
}