#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;

    cin >> N;

    // 에너지 음료를 따를 때 반이 버려지는 과정에서 소수점이 나올 수 있으므로 double형을 선택했다.
    vector<double> energyDrink;

    for (int i = 0; i < N; i++)
    {
        double amount;
        cin >> amount;

        energyDrink.push_back(amount);
    }

    // 그리디 알고리즘의 관점에서 봤을 때 가장 큰 양의 에너지 음료에 나머지 에너지 음료들을 반을 흘리면서 합치는 것이 합쳐진 에너지 드링크의 양을 최대로 만들 수 있다.
    // 따라서 에너지 음료의 양을 오름차순으로 정렬 후 가장 마지막에 있는 에너지 음료의 양, 즉 가장 큰 양의 에너지 음료를 변수에 저장한 뒤
    // 가장 큰 에너지 음료들을 제외한 나머지 음료들을 2로 나눠주면서 가장 큰 에너지 음료에 더해주면 합쳐진 에너지 드링크의 최대 양을 알 수 있다.
    sort(energyDrink.begin(), energyDrink.end());

    double cup = energyDrink[energyDrink.size() - 1];

    for (int i = 0; i < energyDrink.size() - 1; i++)
    {
        cup += (energyDrink[i] / 2);
    }

    cout << cup << "\n";

    return 0;
}