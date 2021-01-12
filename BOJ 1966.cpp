#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

vector<int> rs;      //결과 값을 담을 벡터

int main()
{
   ios::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
   
   int test_case;
   cin>>test_case;
   
   for(int i=0; i<test_case; i++)
   {
      vector<int> pp;      //문서의 순서를 담을 벡터
      vector<int> ip;      //각 문서의 중요도를 담을 벡터
      queue<pair<int,int>> q;    //각 문서와 그 문서의 중요도를 담을 벡터(사실상 이게 프린터기)
      priority_queue<int,vector<int>,less<int>> pq;
      //중요도에 따라 작동시키기 위한 우선 순위 큐. less와 greater를 반대로 알고 있어서 많이 헤맸다...
      //less는 큰 것부터, greater은 작은 것부터!
      int cnt=0;     //몇번째에 출력되는 문서인지 알아내기 위한 카운팅 변수
      int N,M;
      cin>>N>>M;
      for(int i=0; i<N; i++)
      {
         int ipt;
         cin>>ipt;
         
         pp.push_back(i);
         ip.push_back(ipt);
         
         q.push({pp[i],ip[i]});
         pq.push(ip[i]);      //중요도를 입력받고 문서의 순서는 0번째부터 시작이므로 문서 번호와 중요도를 벡터와 큐에 각각 담아준다.
      }
      
      while(!q.empty())
      {
         int doc=q.front().first;    
         int order=q.front().second;      //순서상 출력되어야 하는 문서와 중요도를 가져온다.
         q.pop();    //출력하는 것인지 맞는지룰 위해 프린터기에서 pop
            
         if(pq.top()==order)     //우선 순위 큐는 가장 높은 숫자를 top으로 가지므로 줄력되어야 하는 문서가 가장 높은 중요도를 가졌는지 확인한다.
         {
            pq.pop();
            cnt++;      //만약 출력해야 한다면 우선순위 큐의 중요도 또한 pop 해주고 cnt를 증가시킨다.
            if(pp[M]==doc)    //만약 우선 순위에 맞게 출력하는 문서가 찾고자 하는 문서였다면 지금까지 센 cnt를 결과 벡터에 담고 반복문을 탈출한다.
            {
               rs.push_back(cnt);
               break;
            }
         }
         else
            q.push({doc,order});    //먼약 우선순위가 낮은 문서라면 다시 뒷 숫서로 push 한다.
      }
   }
   
   for(int i=0; i<test_case; i++)
      cout<<rs[i]<<"\n";
   
   return 0;
}