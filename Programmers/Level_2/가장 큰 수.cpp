#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 기존의 비교함수를 custom. 비교하고자 할 두 숫자를 단순히 사전순으로 정렬하면 {3, 30}이 있을 때, 큰 숫자를 만들기 위해서는 {3, 30}이 되어야 하지만
// {30, 3}의 순서가 되어버린다. 따라서 비교하고자 하는 두 숫자 a와 b를 a + b, b + a의 순서로 이어붙여보고 사전 순으로 더 큰 값을 반환하도록 하였다.
// ex) {3, 30} => "330" VS "303" ==> "330"이 더 크다고 판단!
bool compare(string a, string b)
{
    return a + b > b + a;
}

string solution(vector<int> numbers)
{
    string answer = "";

    bool except = false; // 주어지는 정수들이 모두 0으로 이루어진 경우를 확인하기 위한 변수

    vector<string> numbers_str;

    for (int i = 0; i < numbers.size(); i++)
        numbers_str.push_back(to_string(numbers[i])); // 정수를 string으로 변환하여 벡터에 저장

    sort(numbers_str.begin(), numbers_str.end(), compare);

    if (numbers_str[0] == "0") // 만약 징렬된 후 가장 앞 숫자가 0이라면 0으로 이루어진 정수 배열이며 예외 처리 사항이다.
    {
        except = true;
        answer += "0";
    }

    if (!except)
    {
        for (int i = 0; i < numbers_str.size(); i++)
            answer += numbers_str[i];
    }

    return answer;
}

int main()
{

    vector<int> numbers = {0, 0, 0, 0};

    cout << solution(numbers) << endl;

    return 0;
}