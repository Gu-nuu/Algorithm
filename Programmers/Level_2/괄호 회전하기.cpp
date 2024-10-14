#include <string>
#include <vector>
#include <deque>
#include <stack>

using namespace std;

bool check_bracket(deque<char> d)
{
    stack<char> stk;
    bool flag = true;

    for (int i = 0; i < d.size(); i++)
    {
        if (d[i] == '(' || d[i] == '{' || d[i] == '[')
        {
            stk.push(d[i]);
        }
        else
        {
            if (stk.empty())
            {
                flag = false;
                break;
            }
            else if (d[i] == ')')
            {
                if (stk.top() != '(')
                {
                    flag = false;
                    break;
                }
                else
                {
                    stk.pop();
                }
            }
            else if (d[i] == '}')
            {
                if (stk.top() != '{')
                {
                    flag = false;
                    break;
                }
                else
                {
                    stk.pop();
                }
            }
            else if (d[i] == ']')
            {
                if (stk.top() != '[')
                {
                    flag = false;
                    break;
                }
                else
                {
                    stk.pop();
                }
            }
        }
    }

    if (!flag || !stk.empty())
    {
        return false;
    }
    else
    {
        return true;
    }
}

int solution(string s)
{
    int answer = 0;
    int rotate = s.size();

    deque<char> d;

    for (int i = 0; i < s.size(); i++)
    {
        d.push_back(s[i]);
    }

    for (int i = 0; i < rotate; i++)
    {
        if (check_bracket(d))
        {
            answer++;
        }

        char temp = d.front();
        d.pop_front();
        d.push_back(temp);
    }

    return answer;
}