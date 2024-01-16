#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool compare(int a, int b)
{
    return a > b;
}

// 그리디 알고리즘의 관점에서 상자를 옮기는 시간을 최소화 하기 위해서는 가장 무게가 무거운 상자를 무게 제한이 높은 크레인 순서로, 즉 내림차순으로 상자를 옮겨야 한다.
// 따라서 크레인의 무게 제한과 상자의 무게를 각각 입력받은 후 내림차순으로 정렬한 뒤, 무게 제한이 높은 크레인이 가능한 무거운 상자를 나를 수 있도록 했다.
int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<int> crain;

    for (int i = 0; i < N; i++)
    {
        int crain_weight;
        cin >> crain_weight;

        crain.push_back(crain_weight);
    }

    sort(crain.begin(), crain.end(), compare); // 크레인의 무게 제한을 내림차순으로 정렬

    int M;
    cin >> M;

    vector<int> box;

    for (int i = 0; i < M; i++)
    {
        int box_weight;
        cin >> box_weight;

        box.push_back(box_weight);
    }

    sort(box.begin(), box.end(), compare); // 상자의 무게를 내림차순으로 정렬

    if (box[0] > crain[0]) // 만약 가장 무거운 상자를 크레인이 들 수 없다면 해당 상자들은 아예 옮길 수 없기 때문에 -1을 출력해준다.
    {
        cout << "-1\n";
    }
    else
    {
        int time = 0;

        while (!box.empty())
        {
            for (int i = 0; i < crain.size(); i++)
            {
                for (int j = 0; j < box.size(); j++)
                {
                    // 만약 해당 상자를 크레인이 들 수 있다면 해당 상자를 옮겨주고 상자의 무게를 저장한 벡터에서 해당 상자를 제거해주고
                    // 다음 크레인이 상자를 옮길 수 있도록 break 해준다.
                    if (crain[i] >= box[j])
                    {
                        box.erase(box.begin() + j);
                        break;
                    }
                }
            }

            time++; // 크레인은 동시에 움직이기 때문에 주어진 개수의 크레인이 상자를 옮기고 나면 시간을 더해준다.
        }

        cout << time << "\n";
    }

    return 0;
}