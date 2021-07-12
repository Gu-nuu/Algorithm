#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

vector <int> v1;        //상근이의 숫자 카드
vector <int> v2;        //숫자 카드에 적힌 정수


int main()
{
    ios::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int cnt1;
    cin>>cnt1;
    for(int i=0; i<cnt1; i++)
    {
        int num1;
        cin>>num1;
        v1.push_back(num1);
    }

    int cnt2;
    cin>>cnt2;
    for(int i=0; i<cnt2; i++)
    {
        int num2;
        cin>>num2;
        v2.push_back(num2);
        
    }

    vector <int> v3(cnt2);      //상근이가 해당하는 카드를 몇 장 가지고 있는지 카운트할 벡터

    sort(v1.begin(), v1.end());     //lower_bound와 upper_bound를 위한 정렬
    for(int i=0; i<v2.size(); i++)
    {
        if(v2[i]==v1[lower_bound(v1.begin(),v1.end(),v2[i])-v1.begin()])        //만약 상근이의 카드에서 주어진 정수를 발견했다면
            v3[i]=upper_bound(v1.begin(),v1.end(),v2[i])-lower_bound(v1.begin(),v1.end(),v2[i]);

            //여기가 매우 중요! upper_bound는 찾고자 하는 값 초과의 iterator를 반환하고 lower_bound는 찾고자 하는 값 이상의 iterator를
            //반환한다. 예를 들어 {1,2,2,2,3,3,4} 일 때 2를 찾으면 upper_bound() iterator는 5번째인 3에 있고 lower_bound() iterator는 2번째인
            //2에 있다. 즉 upper-lower을 해준다면 찾고자 하는 값의 개수가 나온다! 이때 ~_bound()-~.begin()을 하면 해당 인덱스 값을 알 수 있다.
    }

    /*
    //처음엔 그냥 탐색하고 같은 값을 찾으면 그 순서의 배열을 카운트 해주었다.
    //틀린 구현은 아니었지만 단순 무식 탐색이기 때문에 시간 초과에서 문제가 되었다.
    
    for(int i=0; i<v2.size(); i++)
    {
        for(int j=0; j<v1.size(); j++)
        {
            if(v1[j]==v2[i])
                v3[i]++;
        }
    }
    */

    for(int i=0; i<v3.size(); i++)
        cout<<v3[i]<<" ";

    return 0;
}