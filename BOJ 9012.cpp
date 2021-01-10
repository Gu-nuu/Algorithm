#include <iostream>
#include <stdio.h>
#include <string>
#include <stack>
using namespace std;

stack <int> s;      //괄호의 모양에 따라 push 혹은 pop을 할 스택

int main()      //NO가 나올 조건을 잘 생각해야 했다. NO일 조건은 2가지인데 우선 스택이 비어있는 상황에서 pop을 하는 괄호를 만날 경우와
                //모든 push와 pop이 끝났는데 스택이 비어있지 않을 경우이다.
{
    ios::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int cnt;
    cin>>cnt;

    for(int i=0; i<cnt; i++)
    {
        bool flag=true;     //괄호가 올바른지 판단할 bool 변수
        string line;
        cin>>line;

        for(int j=0; j<line.size(); j++)
        {
            if(line[j]=='(')
                s.push(1);
            else if(line[j]==')')
            {
                if(!s.empty())
                    s.pop();
                else        //만약 스택이 비어있는데도 pop을 해야하는 경우 괄호가 성립하지 않는 조건이므로 false 후 반복문 탈출
                {
                    flag=false;
                    break;
                }       
            }
        }

        if(!s.empty() || flag==false)     //push와 pop이 모두 끝났는데도 스택이 비어있지 않거나 이미 false 후 break한 경우
            cout<<"NO\n";
        else
            cout<<"YES\n";
        
        while(!s.empty())       //다음 괄호를 판단하기 위해 스택을 모두 비워준다.
            s.pop();
    }

    return 0;
}