#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int n)
{
    string answer = "";

    while (n != 0)
    {
        int temp = n % 3;
        n /= 3;

        if (temp == 0)
        {
            n -= 1;
            answer = "4" + answer;
        }
        else
            answer = to_string(temp) + answer;
    }
    
    return answer;
}

int main()
{
    int n = 9;

    cout << solution(n) << endl;

    return 0;
}