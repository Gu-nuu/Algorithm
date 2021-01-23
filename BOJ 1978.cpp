#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

vector<int> arr(100)        //수열을 저장할 벡터
;
int main()
{
    ios::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int num;
    cin>>num;

    for (int i = 0; i < num; i++)
        cin>>arr[i];

    int cnt=0;
    for (int i = 0; i < num; i++)       //이중 for문을 이용하여 수열 내에서 한 숫자에 대해 소수인지 아닌지를 판별한다.
    {
        bool check=true;        //소수인지 아닌지를 확인할 bool 변수

        if(arr[i]==1)       //1은 소수가 아니므로 무시한다.
            continue;
        else if(arr[i]==2)      //2는 소수 중 유일하게 짝수인 case이므로 카운팅해준 후 바로 넘어간다.
        {
            cnt++;
            continue;
        }

        //소수의 특징이 매우 중요한데 소수는 1과 자기 자신으로 밖에 나누어지지 않는 숫자이다. 따라서 1과 자기 자신을 제외한 그 사이의 숫자를
        //반복문으로 판별하고자 하는 숫자를 제외 숫자로 나눠준다. 이때 나눠진다면 소수가 아니기 때문에 check를 false로 바꾼 후 반복문을 탈출시킨다.
        //반복문이 종료되었을 때 check 변수가 true라면 소수이기 때문에 카운팅 해준다.
        for(int j=2; j<arr[i]; j++)     
        {
            if(arr[i]%j==0)
            {
                check=false;
                break;
            }
        }

        if(check==true)
            cnt++;
    }

    cout<<cnt<<"\n";
    
    return 0;
}