#include <iostream>
#include <cmath>
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

    vector<double> numbers;

    double sum = 0;

    for (int i = 0; i < N; i++)
    {
        double num;
        cin >> num;

        sum += num;
        numbers.push_back(num);
    }

    sort(numbers.begin(), numbers.end());

    cout << (int)round(sum / numbers.size()) << "\n";
    cout << numbers[numbers.size() / 2] << "\n";

    cout << *max_element(numbers.begin(), numbers.end()) - *min_element(numbers.begin(), numbers.end()) << "\n";

    return 0;
}