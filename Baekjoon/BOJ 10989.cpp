#include <iostream>
#include <stdio.h>
using namespace std;

//이 문제를 처음 봤을 땐 그냥 입력받은 수를 모두 저장한 후 정렬했는데 저장하는 과정에서 입력받는 수가 너무 커질 경우
//메모리 초과의 문제가 발생했다. 따라서 최대 정수의 수만큼의 0으로 초기화된 배열을 생성해준 뒤,
//해당 숫자의 배열로 가서 그 숫자의 갯수를 저장해주었다. 그리고 그 배열을 탐색하면서 0이 아닐 경우 var로 배열을 건너온 카운트를 세어
//그 자리가 의미하는 입력받은 수를 box에 저장된 갯수만큼 출력해주었다.

int main()
{
    ios::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int cnt;
    cin>>cnt;

    int box[10001]={0,};        //최대 범위 정수만큼의 배열 생성

    for(int i=0; i<cnt; i++)
    {
        int num;
        cin>>num;
        box[num]++;     //정수를 입력받고 그 정수번째의 배열에 갯수를 증가시켜 준다.
    }

    int index=1;      //인덱스가 곧 입력받은 정수이므로 이를 확인하기 위한 변수
    for(int i=1; i<10001; i++)
    {
        if(box[i]!=0)
        {
            for(int j=0; j<box[i]; j++)
                cout<<index<<"\n";        //만약 0이 아니면 입력받은 정수이므로, 개수만큼 반복문을 돌려 인덱스를 출력한다.
        }
        index++;
    }
    return 0;
}

