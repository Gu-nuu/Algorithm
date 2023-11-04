#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

// 빈도수가 가장 높은 순으로 우선 내림차순 정렬한다.
// 만약 최빈값이 여러 개일 경우, 즉 빈도수가 같은 경우에는 최빈값 중 두번째로 작은 숫자를 출력해야 하므로 숫자 값을 기준으로 오름차순 정렬한다.
bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
        return a.first < b.first;
    else
        return a.second > b.second;
}

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<double> numbers; // 최빈값을 제외한 나머지 값을 구하기 위한 벡터

    // 최빈값을 구하기 위한 벡터. 숫자는 -4000부터 4000까지 나오기 때문에 숫자 값에 해당하는 index 위치에 숫자와 빈도수를 저장하기 위해 크기를 8001개로 만들었다.
    vector<pair<int, int>> counter(8001, {0, 0});

    double sum = 0;

    for (int i = 0; i < N; i++)
    {
        double num;
        cin >> num;

        sum += num;             // 산술평균을 구하기 위해 숫자들의 합을 구해준다.
        numbers.push_back(num); // 나머지 중앙값과 범위를 구하기 위해 벡터에 숫자들을 저장

        counter[num + 4000].first = num; // 숫자에 4000을 더한 값의 index 위치에 해당 숫자 값을 저장한다.
        counter[num + 4000].second++;    // 같은 index 위치의 second 값에 빈도수를 늘려준다.
    }

    sort(numbers.begin(), numbers.end());          // 중앙값과 범위를 구하기 위해 오름차순으로 정렬해준다.
    sort(counter.begin(), counter.end(), compare); // 비교함수를 통해 counter 벡터를 정렬해준다.

    cout << (int)round(sum / numbers.size()) << "\n"; // 산술평균 : 첫째자리에서 반올림 후 정수값으로 출력해야 하므로 round 함수 사용 후 int형으로 캐스팅한다.

    cout << numbers[numbers.size() / 2] << "\n"; // 중앙값 : 숫자의 갯수는 항상 홀수 개로 주어지므로 벡터의 크기 / 2를 하면 중앙값을 알 수 있다.

    // 최빈값 : 만약 정렬 후 가장 첫 숫자의 빈도수와 바로 그 다음 숫자의 빈도수가 같다면 최빈값이 2개 이상이므로 두번째로 작은 숫자를 출력하고, 그렇지 않으면 바로 최빈값을 출력한다.
    if (counter[0].second == counter[1].second)
        cout << counter[1].first << "\n";
    else
        cout << counter[0].first << "\n";

    cout << *max_element(numbers.begin(), numbers.end()) - *min_element(numbers.begin(), numbers.end()) << "\n"; // 범위 : min_element, max_element 함수를 이용해 최댓값 - 최솟값을 구한다.

    return 0;
}