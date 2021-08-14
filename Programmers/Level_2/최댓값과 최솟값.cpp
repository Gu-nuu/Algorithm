#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s)
{
    string answer = "";

    vector<int> box;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '-') // - 부호가 붙은 경우
        {
            i++; // - 부호 이후의 숫자부터 확인
            string temp;
            while (s[i] != ' ') // 공백이 나오기 전까지 모든 수들을 확인
            {
                if (s[i] >= 48 && s[i] <= 57)
                {
                    temp += s[i]; // 공백 전까지 수들을 문자열로 묶음
                    i++;
                }

                if (i == s.size()) // 주어진 s의 끝에 도달했을 경우
                    break;
            }
            box.push_back(-(stoi(temp))); // 문자열을 int로 변환 후 -를 붙여줌
        }
        else if (s[i] >= 48 && s[i] <= 57) // 부호가 없는 일반적인 경우
        {
            string temp;
            while (s[i] != ' ')
            {
                if (s[i] >= 48 && s[i] <= 57)
                {
                    temp += s[i];
                    i++;
                }

                if (i == s.size())
                    break;
            }
            box.push_back(stoi(temp));
        }
    }

    answer += to_string(*min_element(box.begin(), box.end())); // 최솟값 추출
    answer += " ";
    answer += to_string(*max_element(box.begin(), box.end())); // 최댓값 추출

    return answer;
}

int main()
{
    string s = "1 2 3 4";

    cout << solution(s) << endl;

    return 0;
}