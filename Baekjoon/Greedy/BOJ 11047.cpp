#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;

    vector<int> prices; // 동전의 가치를 저장할 벡터

    for (int i = 0; i < N; i++)
    {
        int coin;
        cin >> coin;

        prices.push_back(coin);
    }

    int count = 0; // 동전의 갯수를 저장할 변수

    // 그리디 알고리즘의 관점에서 결국 가치가 높은 동전을 많이 사용할수록 동전의 사용 갯수는 줄어들게 된다.
    // 따라서 동전을 내림차순으로 탐색하면서 사용 가능한 동전을 찾아 가능한 많이 사용할 수 있도록 했다.
    for (int i = prices.size() - 1; i >= 0; i--)
    {
        if (K / prices[i] > 0) // 만약 사용 가능한 동전이라면
        {
            count += (K / prices[i]);           // 해당 동전을 가능한 많이 사용한다.
            K -= (prices[i] * (K / prices[i])); // 사용한 만큼 금액에서 차감한다.
        }

        if (K == 0) // 동전을 모두 사용하여 금액을 맞췄다면 동전의 갯수를 출력 후 반복문을 종료한다.
        {
            cout << count << "\n";
            break;
        }
    }

    return 0;
}