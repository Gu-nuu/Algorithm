#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int cnt;
    cin>>cnt;

    vector <int> v;

    for(int i=0; i<cnt; i++)
    {
        int num;
        cin>>num;
        v.push_back(num);
    }
    sort(v.begin(),v.end());

    for(int i=0; i<cnt; i++)
        cout<<v[i]<<"\n";


    return 0;
}