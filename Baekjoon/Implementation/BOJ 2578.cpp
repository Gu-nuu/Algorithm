#include <iostream>
#include <vector>
using namespace std;

// 빙고판에서 사회자가 부른 수가 어디에 위치하는지 좌표 값을 찾는 함수
pair<int, int> find_coordinate(vector<vector<int>> &v, int num)
{
    pair<int, int> ans = {-1, -1};

    bool stop = false;

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            if (v[i][j] == num)
            {
                ans = {i, j};
                stop = true;
                break;
            }
        }

        if (stop)
            break;
    }

    return ans;
}

// 빙고가 총 몇 개인지 찾는 함수. find_coordinate 함수로 숫자의 좌표를 찾으면
// 0으로 이루어진 check라는 2차원 벡터 내에서 해당 좌표의 위치를 1로 바꾼다.
// 그 후 count_bingo 함수를 통해 check 벡터 내에서 값 1을 가지는지의 여부를 따져 빙고를 확인한다.
int count_bingo(vector<vector<int>> &v)
{
    int bingoCount = 0;

    // 가로, 세로 빙고 여부 확인
    for (int i = 0; i < v.size(); i++)
    {
        bool rowBingo = true;
        bool colBingo = true;
        for (int j = 0; j < v[i].size(); j++)
        {
            if (v[i][j] != 1)
                rowBingo = false;
            if (v[j][i] != 1)
                colBingo = false;
        }
        if (rowBingo)
            bingoCount++;
        if (colBingo)
            bingoCount++;
    }

    // X 모양에 해당하는 대각선 빙고 여부 확인
    bool diag1Bingo = true;
    bool diag2Bingo = true;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i][i] != 1)
            diag1Bingo = false;
        if (v[i][v.size() - 1 - i] != 1)
            diag2Bingo = false;
    }
    if (diag1Bingo)
        bingoCount++;
    if (diag2Bingo)
        bingoCount++;

    return bingoCount;
}

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<vector<int>> board;
    vector<vector<int>> check(5, vector<int>(5, 0));

    for (int i = 0; i < 5; i++)
    {
        vector<int> temp;

        for (int j = 0; j < 5; j++)
        {
            int num;
            cin >> num;
            temp.push_back(num);
        }

        board.push_back(temp);
    }

    int counter = 0;

    for (int i = 0; i < 25; i++)
    {
        int call;
        cin >> call;

        counter++;

        pair<int, int> coordinate = find_coordinate(board, call);

        if (coordinate.first != -1 && coordinate.second != -1)
        {
            check[coordinate.first][coordinate.second] = 1;
        }

        if (count_bingo(check) >= 3)
        {
            break;
        }
    }

    cout << counter << "\n";

    return 0;
}