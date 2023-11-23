#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int test_case;
    cin >> test_case;

    map<string, int> m; // 옷의 종류와 갯수를 저장하기 위한 map

    // 같은 종류의 의상은 하나만 입을 수 있기 때문에 종류별로 옷은 딱 하나씩만 입을 수 있게 된다.
    // 만약 첫번째 예제처럼 hat headgear, sunglasses eyewear, turban headgear가 주어졌을 경우 (hat), (turban), (sunglasses), (hat,sunglasses), (turban,sunglasses)으로 총 5가지가 나오게 된다.
    // 옷을 아예 안 입는 경우를 포함하게 되면 총 6가지가 나오게 되므로 옷을 안 입는 경우를 포함한 모든 경우의 수를 구한 뒤 옷을 아예 안 입는 경우인 1을 빼주면 정답을 구할 수 있다.
    for (int i = 0; i < test_case; i++)
    {
        int n;
        cin >> n;

        for (int j = 0; j < n; j++)
        {
            string clothesName, clothesKind;
            cin >> clothesName >> clothesKind;

            // map에 옷의 종류와 갯수를 저장하며 새로운 옷의 종류일 경우 map에 추가하고 이미 있는 옷의 종류일 경우 갯수를 늘려준다.
            if (m.find(clothesKind) == m.end())
            {
                m.insert({clothesKind, 1});
            }
            else
            {
                auto temp = m.find(clothesKind);
                temp->second++;
            }
        }

        int ans = 1;

        for (auto it = m.begin(); it != m.end(); it++)
        {
            ans *= (it->second + 1); // 전체 경우의 수를 구할 때 +1을 해서 곱해주는 이유는 만약 3가지의 한 종류 옷이 있다면 옷을 각각 하나씩 입을 경우 3과 아예 안 입을 경우 1이 있기 때문이다.
        }

        cout << ans - 1 << "\n";

        m.clear();
    }

    return 0;
}