//요세푸스 문제를 풀고나서 저번 스터디 때 못 풀었던 소풍 문제를 다시 풀어보았다. 소풍 문제는 도저히 못 하겠어서
//구글링을 했는데 알 수 없는 공식들 밖에 없어서 찝찝하게 제출했다. 근데 요세푸스 문제를 풀 때는
//공식 그런거 없이 iterator의 유연한 사용으로 문제를 해결할 수 있었고, 조금 더 심화된 소풍 문제도
//간단하게 풀어낼 수 있었다.
//근데 시간초과 걸림.....!
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

vector<int> v;      //요세푸스 순열을 계산하기 위한 벡터
vector<int> va;     //완성된 요세푸스 순열을 담을 벡터

int main()
{
    ios::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n,k,m;
    cin>>n>>k>>m;

    for(int i=1; i<=n; i++)
        v.push_back(i);

    int cnt=0;
    bool check=true;
    while(check)
    {
        for(vector<int>::iterator iter=v.begin(); iter!=v.end(); iter++)
        {
            if(v.size()==1)
            {
                va.push_back(*iter);
                check=false;
                break;
            }

            cnt++;

            if(cnt==k)
            {
                cnt=0;
                va.push_back(*iter);
                iter=v.erase(iter);
                iter--;
            }
        }
    }
    int result=0;
    for(int i=0; i<va.size(); i++)
    {
        result++;
        if(va[i]==m)
        {
            cout<<result<<"\n";     //완성된 요세푸스 순열에서 몇 번째인지 알기 위해 변수를 이용해 카운팅한다.
            break;
        }
    }

    return 0;
}