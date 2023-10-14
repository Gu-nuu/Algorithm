#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;

    cin >> N;

    // 입력받은 숫자의 개수 범위 내에서 3kg(열)과 5kg(행)으로 만들어질 수 있는 모든 총무게의 합을 2차원 배열로 만들어 구현하였다.
    // 0 | 3 | 6 | 9 | 12 | ...
    // 5 | 8 | 11 | 14 | 17 |
    // 10 | 13 | 16 | 19 | 22 |
    // 15 | 18 | 21 | 24 | 27 |
    // 20 | 23 | 26 | 29 | 32 |
    // ..
    vector<vector<int>> box;
    for (int i = 0; i < N + 1; i++)
    {
        vector<int> temp(N + 1);
        box.push_back(temp);
    }

    vector<int> count;
    for (int i = 0; i < N + 1; i++)
    {
        for (int j = 0; j < N + 1; j++)
        {
            box[i][j] = 5 * i + 3 * j;

            if (box[i][j] == N) // 만약 총무게 합을 계산하면서 입력받은 총무게와 같은 값이 나오면 해당 무게를 이루는데 쓰인 설탕 포대의 개수의 합을 vector에 저장한다.
            {
                count.push_back(i + j);
            }
        }
    }

    if (!count.empty()) // 만약 vector가 비어있다면 입력받은 무게를 만들 수 없기 때문에 -1을 출력하고, 아니면 제일 작은 값을 출력해 최소 개수를 구한다.
        cout << *min_element(count.begin(), count.end()) << "\n";
    else
        cout << "-1\n";

    for (int i = 0; i < N + 1; i++)
    {
        box[i].clear();
    }
    box.clear();

    return 0;
}