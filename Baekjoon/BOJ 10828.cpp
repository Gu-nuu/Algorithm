#include <iostream>
#include <stdio.h>
#include <string>
#include <stack>
using namespace std;

stack <int> s;      //stl 스택 사용

int main()
{
    ios::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int cnt;
    cin>>cnt;

    string cmd;
    for(int i=0; i<cnt; i++)
    {
        cin>>cmd;
        
        if(cmd.compare("push")==0)
        {
            int num;
            cin>>num;
            s.push(num);        //명령어가 push라면 그 값을 입력받고 push
        }
        else if(cmd.compare("pop")==0)
        {
            if(s.empty())       //명령어가 pop일 때 스택이 비어있다면 -1 출력
                cout<<"-1\n";
            else
            {
                cout<<s.top()<<"\n";        //top에서부터 pop되므로 top 출력 후 pop
                s.pop();
            }   
        }
        else if(cmd.compare("size")==0)
        {
            cout<<s.size()<<"\n";       
        }
        else if(cmd.compare("empty")==0)
        {
            if(s.empty())
                cout<<"1\n";
            else
                cout<<"0\n";
        }
        else if(cmd.compare("top")==0)
        {
            if(s.empty())
                cout<<"-1\n";
            else
                cout<<s.top()<<"\n";
        }
    }

    return 0;
}