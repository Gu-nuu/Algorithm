#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string board;
    cin >> board;

    string ans = "";
    string temp = "";

    // 사전순으로 가장 앞서는 답을 출력해야 하므로 2개의 폴리오미노 중 AAAA를 최대한 먼저 사용해야 함을 알 수 있다.
    // 따라서 XX 이후에 .이 나오거나 보드판의 입력이 종료되는 경우가 아니라면 무조건 AAAA를 우선적으로 사용할 수 있도록 했고 그 외에 빈 공간을 BB로 채울 수 있도록 했다.
    // 만약 X가 홀수 개로 나타나면서 뒤에 . 또는 보드판 입력의 종료인 경우에는 보드판을 모두 덮을 수 없는 것으로 간주하여 -1을 출력하도록 했다.

    for (int i = 0; i < board.size(); i++)
    {
        if (board[i] == '.') // .은 폴리오미노로 덮지 않으므로 정답 string에 .을 추가해주고 아무런 행동을 취하지 않는다.
        {
            ans += '.';
        }
        else
        {
            temp += board[i]; // temp 변수에 현재 보드판의 문자를 저장한다.

            if (temp.size() % 2 == 1 && (board[i + 1] == '.' || i == board.size() - 1)) // 만약 temp에 쌓인 보드판의 문자의 길이가 홀수이면서 다음 나타날 보드판의 문자가 . 또는 보드판의 끝이라면 해당 보드판은 모두 덮을 수 없다.
            {
                ans = "-1";
                break;
            }

            if (temp == "XX" && (board[i + 1] == '.' || i == board.size() - 1)) // temp에 XX 문자가 쌓인 상태에서 다음 나타날 보드판의 문자가 . 또는 보드판의 끝일 경우에만 BB 폴리오미노를 사용한다.
            {
                ans += "BB";
                temp = "";
            }

            if (temp == "XXXX") // 그 외에 경우 XXXX가 나타날 때 무조건 AAAA 폴리오미노를 사용할 수 있도록 한다.
            {
                ans += "AAAA";
                temp = "";
            }
        }
    }

    cout << ans << "\n";

    return 0;
}