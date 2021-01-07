#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
using namespace std;

queue <int> q;

int main()
{
    ios::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int cnt;
    cin>>cnt;

    string cmd;
    for(int i=0; i<cnt; i++)
    {
        cin>>cmd;

        if (cmd.compare("push")==0)
        {
            int num;
            cin>>num;
            q.push(num);
        }
        else if (cmd.compare("pop")==0)
        {
            if(q.empty())
                cout<<"-1\n";
            else
            {
                cout<<q.front()<<"\n";
                q.pop();
            }
                
        }
        else if (cmd.compare("size")==0)
        {
            cout<<q.size()<<"\n";
        }
        else if (cmd.compare("empty")==0)
        {
            if(q.empty())
                cout<<"1\n";
            else
                cout<<"0\n";
        }
        else if (cmd.compare("front")==0)
        {
            if(q.empty())
                cout<<"-1\n";
            else
                cout<<q.front()<<"\n";
        }
        else if (cmd.compare("back")==0)
        {
            if(q.empty())
                cout<<"-1\n";
            else
                cout<<q.back()<<"\n";
        }
    
    }

    return 0;
}