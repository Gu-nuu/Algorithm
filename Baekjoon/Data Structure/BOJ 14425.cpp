#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;

    cin >> N >> M;

    vector<string> S; // 집합 S에 포함되어 있는 문자열을 저장

    for (int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;

        S.push_back(temp);
    }

    vector<string> test; // 검사해야 하는 문자열을 저장
    for (int i = 0; i < M; i++)
    {
        string temp;
        cin >> temp;

        test.push_back(temp);
    }

    sort(test.begin(), test.end()); // 시간 복잡도를 줄이기 위해 이진 탐색을 사용하기 위한 정렬

    int count = 0;
    for (int i = 0; i < N; i++)
    {
        // 이진 탐색으로 찾고자 하는 문자열이 존재할 경우, 그냥 count를 증가시키지 않고 lower_bound와 upper_bound의 차를 이용해 개수를 구한다.
        // 만약 그냥 count를 하게 되면 검사해야 하는 문자열들에서 중복되는 문자열들이 있을 때 이를 count하지 않기 때문이다.
        if (binary_search(test.begin(), test.end(), S[i]))
        {
            count = count + (upper_bound(test.begin(), test.end(), S[i]) - lower_bound(test.begin(), test.end(), S[i]));
        }
    }

    cout << count << "\n";

    return 0;
}