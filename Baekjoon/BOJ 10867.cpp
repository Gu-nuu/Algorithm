#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

vector <int> v;

bool compare(int a,int b)
{
    return a<b;
}

int main()
{
    ios::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int cnt;
    cin>>cnt;

    for(int i=0; i<cnt; i++)
    {
        int num;
        cin>>num;
        v.push_back(num);
    }

    sort(v.begin(),v.end(),compare);
    v.erase(unique(v.begin(),v.end()),v.end());     //unique를 이용해 중복 처리를 함

    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";

    return 0;
}