#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector <pair<int,int>> v;

int main()
{
    ios::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int cnt;
    cin>>cnt;

    for(int i=0; i<cnt; i++)
    {
        int x,y;
        cin>>x>>y;
        v.push_back({y,x});     //11650 문제와 반대로 y좌표부터 정렬의 기준이 되므로 pair의 first와 second를 뒤집어준다.
    }

    sort(v.begin(), v.end());

    for(int i=0; i<cnt; i++)
        cout<<v[i].second<<" "<<v[i].first<<"\n";

    return 0;
}