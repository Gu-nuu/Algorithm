#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>
using namespace std;

vector <int> v1;     //만들고자 할 수열을 담을 벡터
vector <char> v2;    //push인지 pop인지에 따라 기호를 저장할 벡터
stack <int> s;    //연산에 필요한 스택

int main()
{
   ios::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
   
   int cnt;
   cin>>cnt;
   for(int i=0; i<cnt; i++)      //만들고자 하는 수열을 입력받은 뒤 벡터에 저장해준다.
   {
      int num;
      cin>>num;
      v1.push_back(num);
   }
   
   vector<int>::iterator it;
   it=v1.begin();    //수열 벡터를 탐색할 iterator을 생성하고 가장 처음으로 it를 옮겨준다.
   
   for(int i=1; i<=cnt; i++)     //수열은 1부터 cnt까지 차례로 push 되므로 for문은 1부터 시작
   {
      s.push(i);
      v2.push_back('+');      //1부터 숫자를 차례로 스택에 push하고 기호 벡터에 + 추가
      
      while(!s.empty())    //이 부분을 생각하는게 조금 힘들었다!
      {
         if(s.top()==*it)     //만약 스택의 top과 it가 가리키는 수가 같다면 우리가 찾는 수열이므로 pop해주고 기호를 추가한다.
         {                    //그러면 그 수열은 만들어진 것이므로 it을 다음으로 옮겨 다음 수열을 확인한다.
            s.pop();
            v2.push_back('-');
            it++;
         }
         else     //이 점 또한 생각하기 힘들었는데 만약 스택의 top과 수열이 일치하지 않는다면 수열 자체가 성립하지 않는다.
            break;
      }  
   }
   
   if(s.empty())     //반복문을 빠져나왔을 때 스택이 정상적으로 비워져있다면 성공이므로 기호 벡터를 출력해준다.
   {
      for(int i=0; i<v2.size(); i++)
         cout<<v2[i]<<"\n";
   }
   else     //스택이 비워져있지 않다는 것은 중간에 조건이 성립하지 않아 break한 것이므로 NO를 출력한다.
      cout<<"NO\n";
   

   
   return 0;
}