#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int a, int b)
{
    string answer = "";

    int month_date[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    string day[7] = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};

    int temp = 0;
    for (int i = 0; i < a - 1; i++)
        temp += month_date[i];
    temp += b;

    if (temp % 7 == 0)      // 7로 나눈 값 - 1을 해주는 경우 목요일의 경우에는 나머지가 0이 되어 -1 값이 나오기 때문에 따로 예외 처리
        answer = day[6];
    else
        answer = day[temp % 7 - 1];

    return answer;
}

int main()
{
    int month = 5;
    int date = 24;

    string ans = solution(month, date);

    cout << ans << endl;

    return 0;
}