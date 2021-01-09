#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> v1;
vector <int> v2;

int main()
{
    ios::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int cnt;
    cin>>cnt;

    for(int i=0; i<cnt; i++)
    {
        int num1;
        cin>>num1;
        v1.push_back(num1);
    }
    
    for(int i=0; i<cnt; i++)
    {
        int num2;
        cin>>num2;
        v2.push_back(num2);
    }

    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end(),greater<>());      //이 부분이 제일 중요했다. 어차피 가장 큰 수를 가장 작은 수와 곱하기만 해준다면 수는 필연적으로
                                                //작게 나올 것이기 때문에 한 벡터는 오름차순으로 다른 하나의 벡터는 내림차순으로 정렬해주었다.

    int result=0;
    for(int i=0; i<cnt; i++)
    {
        result+=v1[i]*v2[i];
    }

    cout<<result<<"\n";

    return 0;
}