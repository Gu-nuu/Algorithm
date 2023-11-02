#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    set<string> useEmo; // 다시 ENTER로 재입장하는 경우가 아니라면 중복해서 이모티콘으로 인사하는 경우는 없어야 하므로 set을 사용했다.

    string firstEnter; // 첫번째 입력은 무조건 ENTER이기 때문에 따로 먼저 입력받는다.
    cin >> firstEnter;

    int cnt = 0; // 이모티콘 사용횟수를 저장할 변수

    for (int i = 0; i < N - 1; i++) // 첫번째 ENTER를 제외하고 입력받는다.
    {
        string msg;
        cin >> msg;

        // 만약 첫번째 ENTER 이후 다시 ENTER가 나오면 새로운 사람이 입장할 수도 있지만 기존에 있던 사람이 재입장할 수도 있다.
        // 이때 재입장하더라도 이모티콘을 사용해 인사하는 것이기 때문에 ENTER 이후엔 무조건 이모티콘을 사용해 인사하게 된다.
        // 따라서 기존에 이모티콘으로 인사한 사람들의 수를 먼저 더해주고 set을 초기화시킨 후 다시 이모티콘 사용 횟수를 계산한다.
        if (msg == "ENTER")
        {
            cnt += useEmo.size();
            useEmo.clear();
        }
        else
            useEmo.insert(msg);
    }

    cnt += useEmo.size(); // 모든 사람들의 입장이 끝났다면 set에 남아있는 이모티콘 사용횟수를 더해준다.

    cout << cnt << "\n";

    return 0;
}