#include <stdio.h>
#include <iostream>
#include <deque>
#include <string>
using namespace std;

deque <int> d;      //정수 배열을 담을 덱. 배열의 가장 앞과 뒤에서만 삭제가 일어나므로 덱을 채택했다.

int main()
{
    ios::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int test_case;
    cin>>test_case;
    for(int i=0; i<test_case; i++)
    {
        string cmd;
        cin>>cmd;

        int length;
        cin>>length;

        string arr;
        cin>>arr;

        string tmp;
        for(int i=0; i<arr.length(); i++)     //입력받은 정수 배열은 괄호와 콤마를 포함한 문자열이므로 파싱해줘야 한다.
        {
            if(arr[i]=='[')     //만약 배열이 시작하는 괄호면 다음 문자열을 바로 탐색
                continue;
            else if(arr[i]>='0' && arr[i]<='9')     //이 부분이 중요한데 숫자에 해당하는 부분이 나올 경우 바로 덱에 넣는 것이 아니라 두 자리 수에 대한 경우도
                tmp+=arr[i];                        //고려해야한다. 따라서 임시 스트링 변수와 합쳐서 두 자리 정수에 대한 것을 고려한다.
            else if(arr[i]==',' || arr[i]==']')     //정수 배열 중 한 정수가 끝났거나 정수 배열 자체가 끝난 경우
            {
                if(!tmp.empty())        //두 자리든 한 자리든 한 정수는 tmp에 저장되어 있으며 이 변수가 비어있다면 정수 배열이 비어있는 것이므로 확인
                {
                    d.push_back(stoi(tmp));     //정수로 변환 후 덱에 넣는다.
                    tmp.clear();        //,일 경우엔 다음 정수 배열의 숫자를 고려해야 하므로 tmp를 초기화 시켜준다.
                }
            }
        }
        
        bool isReverse=false;       //시간 초과를 막는 핵심. 완전 초기에는 직접 배열을 뒤집었지만 덱이기 때문이 앞 뒤로 삭제가 용이하다. 따라서 뒤집히는지 아닌지
                                    //여부만 확인하면 되기 때문에 bool 변수로 이를 체크만 한다.
        bool isError=false;     //정수 배열이 명령어를 실행할 수 있는지에 대한 판단 변수
        for(int i=0; i<cmd.length(); i++)
        {
            if(cmd[i]=='R')
            {
                isReverse = !isReverse;       //뒤집는 명령어가 나왔을 때는 직접 뒤집지 않고 변수의 값만 바꾸어주어 체크만 해놓는다!
            }
            else if(cmd[i]=='D')
            {
                if(d.empty())
                {
                    isError=true;
                    break;      //삭제 명령어가 나왔는데 배열이 비어있다면 이는 error이므로 에러 플래그를 true로 바꿔준 후 반복문을 탈출
                }
                else
                {
                    if(!isReverse)      //뒤집혔는지 아닌지에 대한 여부에 따라 뒤집혔다면 pop_back을 이용해 삭제하고 반대의 경우라면 pop_front로 삭제
                        d.pop_front();
                    else
                        d.pop_back();
                }
                
            }
        }

        if(!isError)        //배열을 직접 뒤집은게 아니기 때문에 출력 시에도 뒤집혔는지에 대한 여부를 체크하여 각각 경우를 나누어 출력해야 한다.
        {
            if(!isReverse)     //배열이 뒤집히지 않은 경우
            {
                cout<<"[";
                while(!d.empty())
                {
                    cout<<d.front();
                    d.pop_front();

                    if(!d.empty())
                        cout<<",";
                }
                cout<<"]\n";
            }
            else
            {
                cout<<"[";
                while(!d.empty())       //배열이 뒤집힌 경우
                {
                    cout<<d.back();
                    d.pop_back();

                    if(!d.empty())
                        cout<<",";
                }
                cout<<"]\n";
            }
            
        }
        else
            cout<<"error\n";
    }

    return 0;
}