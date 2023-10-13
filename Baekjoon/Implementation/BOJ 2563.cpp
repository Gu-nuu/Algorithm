#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int paper[100][100];

    memset(paper, 0, sizeof(paper)); // 가로, 세로의 길이가 100인 도화지를 2차원 배열로 구현 후 모든 값을 0으로 초기화 한다.

    int N;
    int area = 0; // 영역의 넓이를 저장할 변수

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int X, Y;
        cin >> X >> Y;

        for (int j = X; j < X + 10; j++) // 입력 받은 색종이의 좌표를 통해 색종이의 넓이만큼 도화지를 색칠하며 이를 1이라는 값으로 나타낸다.
        {
            for (int k = Y; k < Y + 10; k++)
            {
                if (paper[j][k] == 1) // 만약 이미 색칠되어 있는 영역(겹치는 영역)이라면 무시하고 넘어간다.
                    continue;
                else
                    paper[j][k] = 1;
            }
        }
    }

    for (int i = 0; i < 100; i++) // 값이 1인 부분은 색종이가 부착된 부분이므로 영역의 넓이로 간주하고 계산한다.
    {
        for (int j = 0; j < 100; j++)
        {
            if (paper[i][j] == 1)
                area++;
        }
    }

    cout << area << "\n";

    return 0;
}