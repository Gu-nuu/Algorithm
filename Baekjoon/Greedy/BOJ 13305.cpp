#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    // 도로의 길이와 도시에 있는 주유소의 리터당 가격을 저장하기 위한 vector
    // 이때 제일 왼쪽 도시부터 제일 오른쪽 도시까지의 거리와 리터당 가격은 1 이상 1,000,000,000 이하의 자연수이므로 이 둘을 곱해 계산할 때
    // int형으로 계산하게 되면 오버플로우가 발생할 수도 있다. 따라서 자료형을 long long으로 선택했다
    vector<long long> roadLength;
    vector<long long> oilPrice;

    for (long long i = 0; i < N - 1; i++)
    {
        long long lengthNum;
        cin >> lengthNum;

        roadLength.push_back(lengthNum);
    }

    for (long long i = 0; i < N; i++)
    {
        long long priceNum;
        cin >> priceNum;

        oilPrice.push_back(priceNum);
    }

    // 처음에는 무조건 기름을 넣고 다음 도시로 넘어가야 하므로 min 값을 가장 첫 도시의 리터당 가격으로 선택한다.
    // 다음 도시를 갈 때마다 이전 도시의 리터당 가격과 비교하면서 더 작은 값은 min에 저장하여 리터당 가격이 가장 싼 값을 저장한다.
    // 리터당 가격이 가장 쌀 때 남은 거리를 모두 갈 수 있도록 기름을 넣어야 하므로 min 값이 다음 도시의 리터당 가격보다 작다면 해당 min 값을 유지하면서 비용을 계산하도록 했다.
    long long min = oilPrice[0];
    long long cost = 0;

    for (int i = 0; i < N - 1; i++)
    {
        if (min > oilPrice[i])
        {
            min = oilPrice[i];
        }

        cost += (min * roadLength[i]);
    }

    cout << cost << "\n";

    return 0;
}