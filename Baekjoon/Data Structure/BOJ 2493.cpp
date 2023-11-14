#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    stack<pair<int, int>> s; // 탑의 높이와 인덱스를 값이 저장해야 하므로 pair를 사용하였다.
    vector<int> ans;         // 정답을 저장할 벡터

    // 현재 탑의 높이와 스택에 들어있는 탑의 높이(현재 탑보다 왼쪽에 위치한 탑들)들을 비교했을 때 현재 탑의 높이보다 큰 탑의 인덱스를 저장하고
    // 현재 탑보다 높은 탑이 없을 경우 0을 ans에 저장하고 현재 탑의 높이를 스택에 넣는 방식으로 진행했다.
    // 즉 스택에 들어있는 탑들 중 가장 높이가 큰 탑과 현재 탑의 높이 사이에 존재하는 값들을 지워나갈 수 있도록 했다.
    // ex) 6 9 5 7 4
    // 6이 들어왔을 때 스택은 비어있기 때문에 0을 ans에 저장하고, {6, 1}을 스택에 넣는다
    // 9가 들어왔을 때 스택의 top은 {6, 1}이므로 현재 탑의 높이 9보다 작기 때문에 pop하고 다음 pop을 확인한다. pop한 뒤 스택은 비어있기 때문에 0을 ans에 저장하고 {9, 2}를 스택에 넣는다.
    // 5가 들어왔을 때 스택의 top은 {9, 2}이므로 현재 탑의 높이 5보다 크기 때문에 높이 9인 탑의 인덱스인 2를 ans에 저장하고 {5, 3}을 스택에 넣는다.
    // 7이 들어왔을 때 스택의 top은 {5, 3}이므로 현재 탑의 높이 7보다 작기 때문에 pop하고 다음 top을 확인한다. 다음 top은 {9, 2}이므로 높이 7보다 크기 때문에 높이 9인 탑의 인덱스인 2를 ans에 저장하고 {7, 4}을 스택에 넣는다.
    // 4가 들어왔을 때 스택의 top은 {7, 4}이므로 현재 탑의 높이 4보다 크기 때문에 높이 7인 탑의 인덱스인 4를 ans에 저장한다.
    for (int i = 0; i < N; i++)
    {
        int tower;
        cin >> tower;

        while (!s.empty())
        {
            if (s.top().first > tower)
            {
                ans.push_back(s.top().second);
                break;
            }

            s.pop();
        }

        if (s.empty())
            ans.push_back(0);

        s.push({tower, i + 1});
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}