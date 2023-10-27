#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    stack<int> space; // 줄 옆 빈 공간을 구현한 구조
    queue<int> line;  // 현재 학생들의 번호표 순서를 저장할 구조

    for (int i = 0; i < N; i++)
    {
        int numSheet;
        cin >> numSheet;

        line.push(numSheet);
    }

    int turn = 1; // 번호표가 1번인 학생부터 간식을 받으므로 초기 값을 1로 설정

    while (1)
    {
        if (space.empty() && line.empty()) // 만약 대기줄과 옆 공간이 모두 비어있으면 번호표 순서대로 모든 학생들이 간식을 받아가게 된다.
        {
            cout << "Nice\n";
            break;
        }
        // 빈 공간으로 온 학생들은 다시 줄로 돌아갈 수 없기 때문에
        // 줄을 서있는 학생이 없지만 빈 공간에 학생이 있는 상황에서 만약 바로 다음 순서가 현재 번호표 순서와 일치하지 않는다면 순서대로 간식을 받을 수 없는 경우이다.
        else if (line.empty() && space.top() != turn)
        {
            cout << "Sad\n";
            break;
        }

        if (!line.empty() && line.front() == turn) // 현재 줄 맨 앞에 서있는 학생이 들고 있는 번호표가 현재 간식을 받을 순서와 일치한다면 줄에서 제외시켜 간식을 받는다.
        {
            line.pop();
            turn++;
        }
        else if (!space.empty() && space.top() == turn) // 빈 공간에서 줄 서있는 학생이 들고 있는 번호표가 현재 간식을 받을 순서와 일치한다면 공간에서 제외시켜 간식을 받는다.
        {
            space.pop();
            turn++;
        }
        else // 줄 맨 앞에 서있던 학생이 들고있는 번호표가 현재 간식을 받을 순서와 일치하지 않는다면 빈 공간으로 이동시킨다.
        {
            space.push(line.front());
            line.pop();
        }
    }

    return 0;
}