#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        multiset<int> s; // 따로 정렬을 할 필요 없이 사전에 정렬되어 있는 수열에서 중앙값을 찾는게 빠르며 중복된 값이 있을 수 있으므로 multiset을 사용했다.
        vector<int> v;   // 중앙값을 모아 저장할 vector

        int M;
        cin >> M;

        for (int j = 0; j < M; j++)
        {
            int num;
            cin >> num;

            s.insert(num);

            if (s.size() % 2 == 1) // 홀수번째 숫자가 들어올때마다 해당 숫자를 포함한 오름차순 수열에서 중앙값을 찾도록 했다.
            {
                auto it = s.begin();
                int cnt = 0;

                while (cnt != (s.size() / 2)) // multiset의 iterator를 맨 앞에 두고 cnt를 0부터 현재 multiset의 크기 / 2까지 하나씩 iterator를 증가시키면 iterator는 중앙값에 위치하게 된다.
                {
                    it++;
                    cnt++;
                }

                v.push_back(*it);
            }
        }

        cout << v.size() << "\n";

        for (int j = 0; j < v.size(); j++)
        {
            cout << v[j] << " ";

            if (j + 1 == 10) // 값을 10개씩 출력하고 end line해야하므로 조건을 추가했다.
            {
                cout << "\n";
            }
        }

        cout << "\n";
    }

    return 0;
}