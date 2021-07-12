#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int cnt;
    cin>>cnt;       //개수 입력

    vector <int> v(cnt);        //벡터 사용
    //int *box=new int[cnt];        //동적 배열 사용

    for(int i=0; i<cnt; i++)
    {
        int num;
        cin>>num;
        //box[i]=num;
        v[i]=num;      
    }
    //sort(box,box+cnt);
    sort(v.begin(),v.end());        //알고리즘 헤더의 sort 사용

    for(int i=0; i<cnt; i++)
        cout<<v[i]<<endl;        //출력


    return 0;
}