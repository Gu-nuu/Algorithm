#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N;
    cin>>N;
    int *box=new int[N];        //입력받은 개수만큼 상근이의 카드 배열을 동적 할당
    for(int i=0; i<N; i++)
    {
        int var1;
        cin>>var1;
        box[i]=var1;        //상근이의 카드 배열을 만듦
    }
    sort(box,box+N);        //이진 탐색을 위해 정렬

    int M;
    cin>>M;

    for(int i=0; i<M; i++)
    {
        int var2;
        cin>>var2;
        
        if(binary_search(box,box+N,var2))       //알고리즘 헤더의 이진 탐색을 통해 입력받은 값을 찾으면 1, 아니면 0
            cout<<"1 ";
        else
            cout<<"0 ";
    }

    return 0;
}
