#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string new_id)
{
    string answer = "";

    for (int i = 0; i < new_id.size(); i++) // 1단계
    {
        if (isupper(new_id[i]))
            new_id[i] = tolower(new_id[i]);
    }

    for (int i = 33; i < 65; i++) // 2단계
    {
        if (i != 45 && i != 46 && !(i >= 48 && i <= 57)) // 아스키 코드 값을 확인하여 '-', '.', 숫자가 아닌 문자들은 모두 삭제
            new_id.erase(remove(new_id.begin(), new_id.end(), i), new_id.end());
    }

    for (int i = 91; i < 127; i++)
    {
        if (i != 95 && !(i >= 97 && i <= 122)) // 아스키 코드 값을 확인하여 '_', 소문자가 아닌 문자들은 모두 삭제
            new_id.erase(remove(new_id.begin(), new_id.end(), i), new_id.end());
    }

    for (int i = 0; i < new_id.size(); i++) // 3단계
    {
        if (new_id[i] == '.')
        {
            if (new_id[i + 1] == '.') // .을 찾았다면 그 다음도 .인지를 확인
            {
                while (new_id[i + 1] == '.') // .이 아닐 때까지 처음 발견한 .을 제외하고 모두 공백으로 변환
                {
                    new_id[i + 1] = ' ';
                    i++;
                }
            }
        }
    }
    new_id.erase(remove(new_id.begin(), new_id.end(), ' '), new_id.end()); // 변환된 공백을 제거하여 .을 모두 한 개로 변환

    if (new_id[0] == '.') // 4단계
        new_id.erase(new_id.begin());

    if (new_id[new_id.size() - 1] == '.')
        new_id.erase(new_id.begin() + new_id.size() - 1);

    if (new_id == "") // 5단계
        new_id += "a";

    if (new_id.size() >= 16) // 6단계 : 길이가 16 이상이면 임시 변수에 길이를 15까지 자른 문자열을 담고 .에 대한 후처리를 한 후 다시 new_id에 저장
    {
        string temp = "";
        temp = new_id.substr(0, 15);
        new_id = "";
        if (temp[temp.size() - 1] == '.')
            temp.erase(temp.begin() + temp.size() - 1);
        new_id = temp;
    }

    if (new_id.size() <= 2) // 7단계
    {
        while (new_id.size() != 3)
            new_id += new_id[new_id.size() - 1];
    }

    answer = new_id;

    return answer;
}

int main()
{
    string id = "...............().........";
    string ans = solution(id);

    cout << ans << endl;

    return 0;
}