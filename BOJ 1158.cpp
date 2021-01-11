#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

vector <int> v;     //요세푸스 순열을 계산하기 위한 벡터

int main()
{
    ios::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n,k;
    cin>>n>>k;

    for(int i=1; i<=n; i++)
        v.push_back(i);     //1부터 순차적으로 벡터에 넣어준다.

    int cnt=0;
    
    bool check=true;
    cout<<"<";
    while(check)
    {
        //이 부분이 생각하기 힘들었다. 원형이 아니기 때문에 끝에 도달한다면 다시 앞으로 돌아와야 하는데 이 코드에서는 우선 
        //가장 앞부터 순차적으로 탐색을 하다가 끝을 만나면 for문을 빠져나간다. 하지만 요세푸스 순열이 완성되지 않았기 때문에 
        //check는 여전히 true이다. 따라서 끝에 도달해도 다시 for문을 시작하면서 카운트를 세면서 맨 앞으로 돌아오게 된다.
        for(vector<int>::iterator iter=v.begin(); iter!=v.end(); iter++)
        {
            if(v.size()==1)
            {
                cout<<*iter<<">";
                check=false;
                break;
            }

            cnt++;      //카운트의 위치가 중요하다. cnt=0이기 때문에 카운트를 먼저 증가시킨후 k와 비교해야 한다.

            if(cnt==k)
            {
                cnt=0;
                cout<<*iter<<", ";
                iter=v.erase(iter);
                iter--;     //만약 카운트에 도달하면 그 수를 출력하고 벡터에서 지워준다. 이때 cnt=0부터 시작했으므로 이터레이터 또한
                            //한 칸 앞당겨 줘야 하기 때문에 iter--를 한다.
            }
        }
    }


    return 0;
}