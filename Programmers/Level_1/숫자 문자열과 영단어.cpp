#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <map>
#include <cmath>

using namespace std;

int solution(string s)
{
    int answer = 0;

    vector<int> numbers; // 변환된 숫자를 저장할 벡터

    map<string, int> box; // 숫자와 해당 숫자의 영단어를 묶어 저장 후 빠르게 찾기 위해 map을 사용

    box.insert({"zero", 0});
    box.insert({"one", 1});
    box.insert({"two", 2});
    box.insert({"three", 3});
    box.insert({"four", 4});
    box.insert({"five", 5});
    box.insert({"six", 6});
    box.insert({"seven", 7});
    box.insert({"eight", 8});
    box.insert({"nine", 9});

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 48 && s[i] <= 57) // 숫자에 해당하는 부분이면 바로 벡터에 저장
            numbers.push_back(s[i] - '0');
        else
        {
            string temp = "";
            while (true) // 숫자가 아니라면 문자열을 하나씩 읽어가면서 map에서 일치하는 단어가 있는지를 확인하고 찾았다면 해당 문자의 숫자를 벡터에 저장
            {
                temp += s[i];

                if (box.find(temp) != box.end())
                {
                    numbers.push_back(box[temp]);
                    break;
                }

                i++;
            }
        }
    }

    for (int i = 0; i < numbers.size(); i++) // 자릿수에 맞게 숫자를 계산
        answer = answer + (numbers[i] * pow(10, numbers.size() - (i + 1)));

    return answer;
}

int main()
{
    string s = "one4seveneight";

    cout << solution(s) << endl;

    return 0;
}