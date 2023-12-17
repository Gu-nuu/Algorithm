#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    // 가격이 높은 유제품을 3개씩 우선적으로 묶으면서 가격이 가장 낮은 유제품을 3개 묶음이 아닌 단일로 남겨놨을 때 가장 최소 비용으로 유제품을 구매할 수 있다.
    // 따라서 multiset을 이용해 유제품의 가격을 입력받을 때 정렬해서 저장할 수 있도록 하였고, 이때 정렬은 내림차순이 될 수 있도록 했다.
    multiset<int, greater<int>> prices;

    for (int i = 0; i < N; i++)
    {
        int C;
        cin >> C;

        prices.insert(C);
    }

    int counter = 0;
    int sum = 0;

    // sum 변수에 유제품의 가격을 더해주면서 counter 변수를 이용해 유제품을 3개씩 묶는지 확인한다.
    // 만약 3개 묶음이 되었다면 현재 it가 가리키는 유제품의 가격을 빼준다.
    // 내림차순으로 정렬되어있기 때문에 3개 묶음이 되었을 때 it가 가리키는 유제품의 가격은 자동적으로 3개 묶음 중 가장 싼 유제품이 된다.
    for (auto it = prices.begin(); it != prices.end(); it++)
    {
        sum += *it;

        counter++;

        if (counter == 3)
        {
            sum -= *it;
            counter = 0;
        }
    }

    cout << sum << "\n";

    return 0;
}