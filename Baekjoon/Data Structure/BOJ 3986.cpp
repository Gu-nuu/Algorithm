#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;

    cin >> N;

    stack<char> s; // 좋은 단어인지 아닌지를 확인하기 위해 stack을 사용

    int ans = 0; // 좋은 단어의 갯수를 셀 변수

    for (int i = 0; i < N; i++)
    {
        string word;
        cin >> word;

        for (int j = 0; j < word.size(); j++)
        {

            // A가 들어온 경우 우선 stack이 비어있는지를 확인하고 비어있다면 글자 A를 stack에 넣는다
            // 만약 stack이 비어있지 않다면 stack의 top을 확인한다. 이때 top이 A일 경우 A끼리 쌍이 지어지는 경우이므로 pop 하여 글자를 빼준다.
            // 만약 stack의 top이 B일 경우 쌍이 지어지는 경우가 아니므로 들어온 글자 A를 stack에 넣는다.
            if (word[j] == 'A')
            {
                if (s.empty())
                {
                    s.push(word[j]);
                }
                else
                {
                    if (s.top() == 'A')
                    {
                        s.pop();
                    }
                    else if (s.top() == 'B')
                    {
                        s.push(word[j]);
                    }
                }
            }
            // 마찬가지로 B가 들어온 경우 우선 stack이 비어있는지를 확인하고 비어있다면 글자 B를 stack에 넣는다
            // 만약 stack이 비어있지 않다면 stack의 top을 확인한다. 이때 top이 B일 경우 B끼리 쌍이 지어지는 경우이므로 pop 하여 글자를 빼준다.
            // 만약 stack의 top이 A일 경우 쌍이 지어지는 경우가 아니므로 들어온 글자 B를 stack에 넣는다.
            else if (word[j] == 'B')
            {
                if (s.empty())
                {
                    s.push(word[j]);
                }
                else
                {
                    if (s.top() == 'B')
                    {
                        s.pop();
                    }
                    else if (s.top() == 'A')
                    {
                        s.push(word[j]);
                    }
                }
            }
        }

        if (s.empty()) // 만약 모든 글자가 올바르게 쌍을 지어 pop된 경우 stack은 비어있게 되고 그럼 해당 단어는 좋은 단어임을 알 수 있다.
            ans++;
        else // stack이 비어있지 않은 경우 좋은 단어가 아니다. 다음 단어 계산을 위해 stack을 한번 초기화시켜준다.
        {
            while (!s.empty())
            {
                s.pop();
            }
        }
    }

    cout << ans << "\n";

    return 0;
}