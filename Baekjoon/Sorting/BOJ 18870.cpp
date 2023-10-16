#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<int> Xn; // Xn의 값을 저장할 벡터
    vector<int> v;  // 좌표 압축 후의 값을 계산하기 위한 벡터

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        Xn.push_back(num);
        v.push_back(num);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    // Xn의 값을 벡터 v에 똑같이 저장 후 정렬하고 중복 값을 제거해준다.
    // 좌표의 대소 관계만 중요한 것이기 때문에 이 과정을 통해 벡터 v에 있는 값들의 index 값들이 곧 좌표 압축 후의 좌표 결과가 된다.

    for (int i = 0; i < Xn.size(); i++)
    {
        // cout << find(v.begin(), v.end(), Xn[i]) - v.begin() << " ";       // find 함수를 사용해 index 값을 찾게 되면 find 함수의 시간 복잡도가 O(N)이기 때문에 시간 초과가 나게 된다.
        cout << lower_bound(v.begin(), v.end(), Xn[i]) - v.begin() << " "; // 따라서 배열이 오름차순일 때 사용할 수 있는 lower_bound 함수를 통해 시간 복잡도를 O(logN)으로 줄여 이를 해결했다.
    }

    cout << "\n";

    return 0;
}