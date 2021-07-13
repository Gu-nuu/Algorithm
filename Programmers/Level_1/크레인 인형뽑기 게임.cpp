#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves)
{
    int answer = 0;
    stack<int> bucket; // 인형을 담을 바구니

    for (int i = 0; i < moves.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            if (board[j][moves[i] - 1] != 0) // moves 값으로 board의 열을 찾아간 후 행을 탐색하는데 0이면 비어있으므로 무시한다.
            {
                bucket.push(board[j][moves[i] - 1]); // 인형을 바구니에 넣어준다.
                board[j][moves[i] - 1] = 0;          // 인형을 뽑았으므로 해당 자리는 0이 된다.
                break;                               // 인형을 하나 뽑았으면 반복문을 종료한다.
            }
        }
        if (bucket.size() > 1) // 바구니에 인형이 하나일 떄는 같은 인형끼리 지워지는 경우는 없다.
        {
            int cmp1 = bucket.top();
            bucket.pop();
            int cmp2 = bucket.top();
            bucket.pop();
            if (cmp1 != cmp2) // 방금 바구니에 들어온 인형과 그 바로 아래에 있는 인형이 서로 다른 인형이라면 다시 바구니에 넣어준다.
            {
                bucket.push(cmp2);
                bucket.push(cmp1);
            }
            else
                answer += 2; // 같은 인형이라면 지워진 인형의 갯수만큼 count 한다.
        }
    }

    return answer;
}

int main()
{
    vector<vector<int>> board = {{0, 0, 0, 0, 0}, {0, 0, 1, 0, 3}, {0, 2, 5, 0, 1}, {4, 2, 4, 4, 2}, {3, 5, 1, 3, 1}};
    vector<int> moves = {1, 5, 3, 5, 1, 2, 1, 4};

    int sol = solution(board, moves);

    cout << sol << endl;

    return 0;
}