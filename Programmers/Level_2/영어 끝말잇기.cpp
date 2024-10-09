#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words)
{
    vector<int> answer;

    int turn = 2;
    int count = 1;
    string prev_word = words[0];
    set<string> s;
    bool flag = true;

    s.insert(words[0]);

    for (int i = 1; i < words.size(); i++)
    {

        if (s.find(words[i]) != s.end() || prev_word[prev_word.size() - 1] != words[i][0])
        {
            flag = false;
            break;
        }
        else
        {
            s.insert(words[i]);
            prev_word = words[i];
        }

        if (turn == n)
        {
            turn = 1;
            count++;
        }
        else
        {
            turn++;
        }
    }

    if (flag)
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        answer.push_back(turn);
        answer.push_back(count);
    }

    return answer;
}