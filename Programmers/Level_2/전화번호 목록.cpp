#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 처음에는 문자열을 길이로 정렬하여 2중 for문 안에서 find 함수를 이용하였고, 그 뒤엔 접두어 조건을 이용하기 위해 substr로 앞 문자의 길이만큼만 잘라서
// 접두 관계를 확인하려 했지만 효율성 테스트에서 계속 걸렸다. 접근 자체를 길이순 정렬이 아닌 사전순 정렬로 접근했다면 쉽게 해결할 수 있는 문제였다.
bool solution(vector<string> phone_book)
{
    bool answer = true;

    sort(phone_book.begin(), phone_book.end());     // 문자열들을 사전순으로 정렬

    for (int i = 0; i < phone_book.size() - 1; i++)
    {
        // 문자열들이 사전순으로 정렬되어 있기 때문에 앞의 문자열이 바로 뒤에 있는 문자열의 접두사가 되지 않는다면 그 뒤는 확인할 필요가 없다.
        if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].size()))
        {
            answer = false;
            break;
        }
    }

    return answer;
}

int main()
{
    vector<string> phone_book = {"1234", "1235", "567"};

    cout << solution(phone_book) << endl;

    return 0;
}