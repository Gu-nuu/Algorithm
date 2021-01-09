#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector <pair<int,int>> v;       //좌표 값을 저장하기 위한 pair 벡터

int main()
{
    ios::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int cnt;
    cin>>cnt;

    for(int i=0; i<cnt; i++)
    {
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }

    sort(v.begin(),v.end());        //sort가 first 값을 비교하고 만약 first 값이 같다면 second 값으로 스스로 오름차순으로 정렬한다....!

    for(int i=0; i<cnt; i++)
        cout<<v[i].first<<" "<<v[i].second<<"\n";

    return 0;
}