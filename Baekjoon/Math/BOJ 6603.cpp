#include <iostream>
#include <stdio.h>
#include <vector>       //배열 대신 벡터를 사용하려 했는데 왜인지 벡터를 사용하면 틀리고 배열을 사용하면 맞았다... 나중에 더 생각해보자!
using namespace std;

//이 문제를 접하기 전에 15649번을 먼저 풀고 오니까 확실히 백트래킹 문제의 기본 틀을 알고 들어갈 수 있어서 더 빠른 구현이 가능했다.
//백트래킹 문제를 풀때는 항상 그림을 그려보고 함수의 틀을 잊지 말자

int k;

//vector<int> arr;        //수열을 담을 벡터
//vector<int> lotto(6);       //로또 번호를 담을 벡터

int arr[12]={0,};       //수열을 담을 배열
int lotto[6]={0,};      //로또 번호를 담을 배열

void pick_lotto(int start, int count)
{
    if(count==6)        //로또 번호 6개를 모두 추출했다면 이를 출력한다.
    {
        for(int i=0; i<6; i++)
            cout<<lotto[i]<<" ";
        cout<<"\n";
        return;
    }

    for(int i=start; i<k; i++)      //모든 수열을 순회한다.
    {
        lotto[count]=arr[i];
        pick_lotto(i+1, count+1);
    }
}

int main()
{
    ios::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    while(1)
    {
        cin>>k;

        if(k==0)
            break;
        else
        {
            for(int i=0; i<k; i++)
            {
                //int num;
                //cin>>num;
                //arr.push_back(num);
                cin>>arr[i];
            }

            pick_lotto(0,0);
            cout<<"\n";
        }
    }


    return 0;
}