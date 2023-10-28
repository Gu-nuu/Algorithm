#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;

    queue<int> circle; // 원을 이루어 앉은 사람들을 저장할 큐
    vector<int> ans;   // 요세푸스 순열을 저장할 벡터

    for (int i = 0; i < N; i++)
        circle.push(i + 1);

    while (1)
    {
        if (circle.size() == 1) // 큐 안에 사람이 한명만 남게 되면 요세푸스 순열이 완성된 것이기 때문에 벡터에 저장하고 반복문을 종료한다.
        {
            ans.push_back(circle.front());
            break;
        }

        int count = 1; // 요세푸스 순열을 하나씩 구할때마다 count 변수를 1로 초기화해준다.

        while (1)
        {
            if (count == K) // count를 세다가 제거되는 순서에 도달하면 큐에서 해당 순서의 사람을 제거하고 반복문을 종료한다.
            {
                ans.push_back(circle.front());
                circle.pop();
                break;
            }
            else // 아직 순서에 도달하지 못했다면 바로 앞에 있는 사람을 다시 큐에 넣어주고 count를 증가시킨다.
            {
                circle.push(circle.front());
                circle.pop();
                count++;
            }
        }
    }

    cout << "<";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];

        if (i < ans.size() - 1)
            cout << ", ";
    }
    cout << ">\n";

    return 0;
}