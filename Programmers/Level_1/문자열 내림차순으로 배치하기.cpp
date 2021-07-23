#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(char a, char b)
{
    return a > b;
}

string solution(string s)
{
    string answer = "";

    vector<char> box;

    for (int i = 0; i < s.size(); i++)
        box.push_back(s[i]);

    sort(box.begin(), box.end(), compare);

    for (int i = 0; i < box.size(); i++)
        answer += box[i];

    return answer;
}

int main()
{
    string s = "Zbcdefg";

    cout << solution(s) << endl;

    return 0;
}