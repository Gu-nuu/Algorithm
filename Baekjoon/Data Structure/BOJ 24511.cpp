#include <iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<int> dataStructure; // 큐인지 벡터인지를 결정하는 수열을 저장
    for (int i = 0; i < N; i++)
    {
        int A;
        cin >> A;

        dataStructure.push_back(A);
    }

    deque<int> queueStack;
    for (int i = 0; i < N; i++)
    {
        int B;
        cin >> B;

        if (dataStructure[i] == 0)    // 만약 스택의 경우라면 연산을 해줄 필요가 없다. 숫자를 넣고 pop 하게 되면 그 숫자가 그대로 나오기 때문이다.
            queueStack.push_front(B); // 숫자를 push_front로 거꾸로 넣어주는 이유는 queuestack이 동작하게 되면 맨 뒤에서 가장 가까운 queue에 있는 숫자가 우선적으로 나오기 때문이다.
    }

    int M;
    cin >> M;

    queue<int> seqC; // queuestack에 넣게될 수열을 저장
    for (int i = 0; i < M; i++)
    {
        int C;
        cin >> C;

        seqC.push(C);
    }

    int cnt = 0;

    while (1)
    {
        if (cnt == M)
            break;

        if (queueStack.empty()) // 만약 queueStack 덱이 비어있다면 현재 queuestack 자료구조는 queue가 존재하지 않고 stack만 있는 것이기 때문에 입력받은 수열 C가 그대로 결과로 나오게 된다.
        {
            while (!seqC.empty()) // 입력받은 수열 C를 그대로 출력하고 반복문을 종료한다.
            {
                cout << seqC.front() << " ";
                seqC.pop();
            }
            break;
        }
        // 만약 queueStack 덱이 비어있지 않다면 현재 queuestack 자료구조는 queue가 존재하기 때문에 연산할 때마다 가장 맨 뒤에 있는 queue의 숫자부터 결과로 나오게 된다.
        // 따라서 덱 맨 앞에 있는 숫자를 먼저 출력해주고 수열 C의 숫자를 하나씩 덱 뒤에다가 push 해준다. 수열 C의 크기만큼 이 과정을 반복하게 되면
        // queuestack 자료구조의 연산 결과를 얻을 수 있다.
        else
        {
            cout << queueStack.front() << " ";
            queueStack.pop_front();
            queueStack.push_back(seqC.front());
            seqC.pop();
            cnt++;
        }
    }

    return 0;
}