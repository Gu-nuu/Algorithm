#include <iostream>
#include <stdio.h>
#include <string>
#include <list>
using namespace std;

list <char> l;      //처음에 덱을 사용했었는데 중간에 데이터가 삽입될 수 있다는 사실을 까먹고 있었다.
                    //그래서 결과 1과 결과 2가 각각 다르게 나오고 런타임 에러가 발생해서 중간에 데이터 삽입이 용이한
                    //리스트로 방법을 바꾸었다.

int main()
{
    ios::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string line;
    cin>>line;

    for(int i=0; i<line.size(); i++)
        l.push_back(line[i]);       //문자열은 string으로 입력받지만 중간에서 수정이 일어나야 하므로 char형으로 저장해준다.

    list <char>::iterator cursor=l.end();       //cursor 역할을 해줄 iterator를 생성하고 문자열의 끝에 위치시킨다.
                                                //이때 end는 맨 마지막 문자의 뒤를 말한다.

    int cnt;
    cin>>cnt;
    for(int i=0; i<cnt; i++)
    {
        char cmd;
        cin>>cmd;

        if(cmd=='L')
        {
            if(cursor!=l.begin())
                cursor--;
        }
        else if (cmd=='D')
        {
            if(cursor!=l.end())
                cursor++;
        }
        else if (cmd=='B')
        {
            if(cursor!=l.begin())
            {
                cursor--;       //커서의 왼쪽 문자를 지워야 하므로 cursor--를 해준다.
                cursor = l.erase(cursor);       //erase를 한 후에는 인자값을 사용할 수 없기 때문에 반환값을 사용해야 함
                      
            }
        }
        else if(cmd=='P')
        {
            char newWord;
            cin>>newWord;
            l.insert(cursor,newWord);
        }        
        
        
    }

    for(cursor=l.begin(); cursor!=l.end(); cursor++)
        cout<<*cursor;

    return 0;

}