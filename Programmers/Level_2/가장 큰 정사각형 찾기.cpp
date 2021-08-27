#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 1234;

    if (board.size() == 1 && board[0].size() == 1 && board[0][0] == 1) // 주어진 표가 1*1 크기이고 그 칸이 1로 이루어진 경우 = 최대 정사각형 넓이는 1
        answer = 1;
    else if (board.size() == 1 && board[0].size() == 1 && board[0][0] == 0) // 주어진 표가 1*1 크기이고 그 칸이 0으로 이루어진 경우 = 최대 정사각형 넓이는 0
        answer = 0;
    else
    {
        int i, j;

        int max = board[0][0];

        for (i = 1; i < board.size(); i++)
        {
            for (j = 1; j < board[i].size(); j++)
            {
                // 검사하는 표 칸이 1일 경우 그 칸을 기준으로 왼쪽, 왼쪽 대각선, 위쪽을 확인하여 정사각형을 이룰 수 있는지 확인하고 가능할 경우 이룰 수 있는 정사각형의 변의 길이를 저장
                if (board[i][j] == 1)
                    board[i][j] = 1 + min({board[i][j - 1], board[i - 1][j - 1], board[i - 1][j]});

                if (max < board[i][j]) // 만들어질 수 있는 가장 큰 정사각형의 변의 길이를 구함
                    max = board[i][j];
            }
        }

        answer = pow(max, 2);
    }

    return answer;
}

int main()
{
    vector<vector<int>> board = {{0, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {0, 0, 1, 0}};

    cout << solution(board) << endl;

    return 0;
}