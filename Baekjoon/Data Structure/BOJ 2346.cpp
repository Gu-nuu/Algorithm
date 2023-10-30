#include <iostream>
#include <algorithm>
#include <deque>
#include <cmath>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    // 원형을 이룬 풍선에서 종이에 적힌 숫자가 음수인지 양수인지에 따라 왼쪽 또는 오른쪽으로 이동하므로 deque를 선택하고
    // 풍선의 번호와 풍선 안의 종이에 적힌 숫자를 한번에 저장하기 위해 pair 객체를 사용했다.
    deque<pair<int, int>> balloon;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;

        balloon.push_back(make_pair(i + 1, num));
    }

    // 처음에는 무조건 맨 첫번째 풍선을 터뜨리므로 첫번째 풍선의 번호를 출력하고 종이에 적힌 숫자를 변수에 저장해준 뒤 pop 해준다.
    cout << balloon.front().first << " ";
    int judge = balloon.front().second;
    balloon.pop_front();

    while (1)
    {
        if (balloon.size() == 1) // 만약 풍선이 하나만 남으면 해당 풍선의 번호만 출력하고 반복문을 종료한다.
        {
            cout << balloon.front().first << "\n";
            balloon.pop_front();
            break;
        }

        int cnt = 1; // 종이에 적힌 숫자만큼 이동했는지를 판별하는 변수

        // 종이에 적힌 숫자가 음수인지 양수인지에 따라 구분하여 코드를 작성했다.
        // 음수인지 양수인지와 상관없이 이동 횟수가 judge 변수의 절댓값과 동일하다면 해당 풍선의 번호를 출력하고 judge 변수를 해당 풍선 안에 들어있는 종이의 숫자로 설정한 뒤 다음 계산을 진행한다.
        // judge가 양수일 경우 이동 횟수에 도달할 때까지 앞(front)에 있는 풍선을 뒤로 계속 push_back 해주며 진행하고 만약 이동 횟수에 도달하게 되면 front에 있는 풍선이 터뜨려야 할 풍선이 된다.
        // judge가 음수일 경우 이동 횟수에 도달할 때까지 뒤(back)에 있는 풍선을 앞으로 계속 push_front 해주며 진행하고 만약 이동 횟수에 도달하게 되면 back에 있는 풍선이 터뜨려야 할 풍선이 된다.
        if (judge > 0)
        {
            while (1)
            {
                if (cnt == abs(judge))
                {
                    cout << balloon.front().first << " ";
                    judge = balloon.front().second;
                    balloon.pop_front();
                    break;
                }
                else
                {
                    balloon.push_back(balloon.front());
                    balloon.pop_front();
                    cnt++;
                }
            }
        }
        else
        {
            while (1)
            {
                if (cnt == abs(judge))
                {
                    cout << balloon.back().first << " ";
                    judge = balloon.back().second;
                    balloon.pop_back();
                    break;
                }
                else
                {
                    balloon.push_front(balloon.back());
                    balloon.pop_back();
                    cnt++;
                }
            }
        }
    }

    return 0;
}