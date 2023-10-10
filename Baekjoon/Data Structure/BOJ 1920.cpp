#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    ios::ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int cnt;
    cin>>cnt;
    int *box=new int[cnt];      //정수 갯수를 입력 받고 동적할당으로 배열 생성
    
    int x;
    for(int i=0; i<cnt; i++)
    {
        cin>>x;
        box[i]=x;
    }
    sort(box,box+cnt);      //동적할당된 배열에 정수를 넣고 정렬 

    int size;
    cin>>size;      //존재하는지 확인할 숫자 갯수 입력

    int num;
    for(int i=0; i<size; i++)
    {
        cin>>num;       //숫자 입력
        if(binary_search(box,box+cnt,num))
            printf("1\n");      //이진 탐색으로 찾았다면 1 출력
        else
            printf("0\n");      //이진 탐색으로 못 찾으면 0 출력
    }
    
    return 0;
}