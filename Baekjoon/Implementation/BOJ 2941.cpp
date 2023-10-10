#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

// 입력받은 문자열을 순차적으로 탐색하면서 주어진 8개의 변경된 크로아티아 알파벳인지를 조건문으로 우선 확인한다. 만약 현재 문자를 기준으로 다음이나 이전의 문자를 봤을때
// 변경된 크로아티아 알파벳인 경우에는 문자열을 탐색하는 커서(i)를 변경된 크로아티아 알파벳의 길이만큼 넘겨준 뒤 갯수를 카운트할 수 있도록 하였다.

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string input = ""; // 입력받는 문자열
    cin >> input;

    int count = 0; // 크로아티아 알파벳의 갯수를 셀 변수
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == 'c')
        {
            if (input[i + 1] == '=' || input[i + 1] == '-') // 현재 커서의 문자가 c이면서 다음 문자가 = 또는 - 일 경우 변경된 크로아티아 알파벳이므로 커서를 옮긴다.
            {
                i += 1;
                count++;
            }
            else // 그렇지 않다면 일반적인 하나의 문자이므로 커서를 뒤로 넘기지 않는다.
            {
                count++;
            }
        }
        else if (input[i] == 'd')
        {
            if (input[i + 1] == '-') // 현재 커서의 문자가 d이면서 다음 문자가 - 또는 z= 일 경우 변경된 크로아티아 알파벳이므로 커서를 옮긴다.
            {
                i += 1;
                count++;
            }
            else if (input[i + 1] == 'z' && input[i + 2] == '=')
            {
                i += 2;
                count++;
            }
            else
            {
                count++;
            }
        }
        else if (input[i] == 'l' || input[i] == 'n')
        {
            if (input[i + 1] == 'j') // 현재 커서의 문자가 l 또는 n이면서 다음 문자가 j일 경우 변경된 크로아티아 알파벳이므로 커서를 옮긴다.
            {
                i += 1;
                count++;
            }
            else
            {
                count++;
            }
        }
        else if (input[i] == 's' || input[i] == 'z')
        {
            if (input[i + 1] == '=') // 현재 커서의 문자가 s 또는 z이면서 다음 문자가 =일 경우 변경된 크로아티아 알파벳이므로 커서를 옮긴다.
            {
                i += 1;
                count++;
            }
            else
            {
                count++;
            }
        }
        else
        {
            count++;
        }
    }

    cout << count << "\n";
}