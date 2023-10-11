#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N; // 단어의 갯수

    int count = 0; // 그룹 단어의 갯수

    for (int i = 0; i < N; i++)
    {
        vector<char> v; // 이전에 나왔던 알파벳들을 저장할 vector
        string word = "";
        bool flag = true; // 그룹 단어인지 아닌지를 판별한 변수
        cin >> word;

        v.push_back(word[0]); // 처음으로 알파벳이 등장한 알파벳을 vector에 미리 저장
        for (int j = 1; j < word.length(); j++)
        {
            if (word[j - 1] == word[j]) // 현재 알파벳이 이전 알파벳과 동일하면 연속한 상태이기 때문에 넘어간다.
            {
                continue;
            }
            // 현재 알파벳이 이전 알파벳과 동일하지 않으면서 vector에 저장된 알파벳에 이미 존재하는 경우 연속하지 않게 발생한 경우이므로 그룹 단어가 아니다.
            else if (word[j - 1] != word[j] && find(v.begin(), v.end(), word[j]) != v.end())
            {
                flag = false;
                break;
            }
            else // 현재 알파벳이 이전 알파벳과 동일하지 않지만 vector에 존재하지 않는 경우 처음으로 등장한 알파벳이므로 vector에 저장한다.
            {
                v.push_back(word[j]);
            }
        }

        if (flag) // 그룹 단어의 조건을 만족하면 갯수를 증가
        {
            count++;
        }
    }

    cout << count << "\n";
}