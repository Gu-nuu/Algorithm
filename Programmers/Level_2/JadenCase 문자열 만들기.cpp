#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>

using namespace std;

string solution(string s)
{
    string answer = "";

    istringstream ss(s); // 문자열을 공백을 기준으로 자르기 위해 sstream 헤더에 있는 istringstream을 사용

    vector<string> box; // 공백으로 자른 문자를 저장하기 위한 벡터
    string temp;
    while (getline(ss, temp, ' ')) // 문자열을 공백을 기준으로 자른 후 벡터에 저장
    {
        box.push_back(temp);
    }

    for (int i = 0; i < box.size(); i++)
    {
        if (islower(box[i][0])) // 단어의 첫 문자가 소문자라면 대문자로 변환
            box[i][0] = toupper(box[i][0]);

        for (int j = 1; j < box[i].size(); j++) // 첫 문자를 제외한 나머지 문자 중 대문자가 존재한다면 모두 소문자로 변환
        {
            if (isupper(box[i][j]))
                box[i][j] = tolower(box[i][j]);
        }
    }

    for (int i = 0; i < box.size(); i++)
    {
        answer += box[i];

        if (i == box.size() - 1 && s[s.size() - 1] == ' ') // 문자열의 끝에 공백이 존재할 경우를 따로 처리
            answer += " ";
        else if (i < box.size() - 1) // 기존의 문자열과 공백을 똑같이 처리해줘야 함. 해당 조건만으로는 문자열 끝에 존재하는 공백일 경우에는 처리 불가
            answer += " ";
    }

    return answer;
}

int main()
{
    string s = "3people unFollowed me ";

    cout << solution(s) << endl;

    return 0;
}