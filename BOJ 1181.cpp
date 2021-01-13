#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector <string> v;
vector <string>::iterator it;

bool compare(string a, string b)        //sort 함수에서 정렬의 방식을 임의로 정하기 위한 함수
{
    if(a.size()==b.size())      //만약 길이가 같다면 문자열의 문자 자체를 비교해 사전순으로 출력한다.
        return a<b;
    else
        return a.size()<b.size();       //만약 길이가 다르다면 오름차순으로 길이가 짧은 것부터 출력한다.
}
//이 함수의 구동 방식을 생각하지 못해서 조금 헤맸다... 그래서 자꾸 사전 순 정렬 후에 길이 순으로 정렬해서 문제를 틀렸다. 조심하자!

int main()
{
    ios::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int cnt;
    cin>>cnt;

    for(int i=0; i<cnt; i++)
    {
        string word;
        cin>>word;
        v.push_back(word);
    }

    sort(v.begin(),v.end(),compare);
    v.erase(unique(v.begin(),v.end()),v.end());     //compare 함수의 방식에 따라 정렬해준뒤 unique를 이용해 중복 처리를 한다.


    for(it=v.begin(); it!=v.end(); it++)
        cout<<*it<<"\n";
        

    return 0;
}