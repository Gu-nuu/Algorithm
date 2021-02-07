#include <iostream>
#include <stdio.h>
#include <vector>
#define MAX 1000001
using namespace std;

int arr[MAX]={0,};      //소수가 아닌 수는 1, 소수는 0으로 표시할 에라토스테네스의 체
vector<int> prime;      //테스트 케이스 값 이하의 소수들을 저장할 벡터

int main()
{
    ios::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    arr[1]=1;

    int test_case;

    while(true)
    {
        cin>>test_case;

        if(test_case==0)        //0이면 프로그램을 종료한다.
            break;

        for(int i=2; i<=test_case; i++)     //에라토스테네스의 체의 원리를 이용하여 테스트 케이스 값 이하의 숫자들에 대해 소수를 판별한다.
        {
            if(arr[i]==1)
                continue;

            for(int j=2; i*j<=test_case; j++)
                arr[i*j]=1;
        }

        for(int i=3; i<=test_case; i++)     //소수 판별이 완료되면 테스트 케이스 이하의 소수들을 벡터에 저장한다.
        {
            if(!arr[i])
                prime.push_back(i);
        }

        bool conjectue=false;       //골드바흐의 추측에 대해 예외를 확인할 변수
        bool flag=false;        //반복문의 탈출을 위한 변수

        for(int i=0; i<prime.size(); i++)       //소수들을 조합의 경우로 순회하면서 만약 테스트 케이스가 소수의 합으로 나올 경우 이를 출력해준 뒤 반복문을 종료시킨다.
        {
            if(flag)
                break;

            for(int j=i+1; j<prime.size(); j++)
            {
                if(prime[i]+prime[j]==test_case)
                {
                    cout<<test_case<<" = "<<prime[i]<<" + "<<prime[j]<<"\n";
                    conjectue=true;
                    flag=true;
                    break;
                }
            }
        }

        if(conjectue==false)        //처음에 false였던 conjecture 값은 두 홀수 소수의 값으로 출력하는 데 성공하면 true로 바뀌는 데 이 값이 안 바뀌었다면 골드바흐의 추측은 틀린 것이 된다.
            cout<<"Goldbach's conjecture is wrong\n";
    }

    return 0;
}