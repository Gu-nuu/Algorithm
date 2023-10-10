#include <iostream>
#include <stdio.h>
using namespace std;

//최대공약수를 구하는 함수. 유클리드 호제법을 사용하여 최대공약수를 구하였다. 두 수 a, b가 있을 때 a%b 즉, 나머지를 구하는 연산을 시행해준다.
//나누고 난 후 나머지가 0이 되기 전까지 이 과정을 계속 반복하는데, 나머지가 0이 아니라면 나누는 수가 나눠지는 수로, 계산 후 나머지를 나누는 수로
//다시 설정하여 계산한다. 예를 들어 x%y를 하고 나온 나머지가 z일 때, z가 0이 나오지 않았다면 y%z를 해주어 다시 연산을 하는 것이라고 볼 수 있다.
//일련의 과정을 반복 후 나머지가 0이 나오는 순간의 나눠지는 수가 바로 최대 공약수이다.
int gcd(int x,int y)
{
    int temp;
    while(true)
    {
        temp=x%y;

        if(temp==0)
            break;
        else
        {
            x=y;
            y=temp;
        }

    }
    return y;
}

//최소공배수를 구하는 함수. 두 수 a*b=gcd(a,b)*lcm(a,b)일 때 lcm(a,b)=(a*b)/gcd(a,b)를 이용하여 최소공배수를 구하였다.
int lcm(int x,int y)
{
    return ((x*y)/gcd(x,y));
}

int main()
{
    ios::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int num1,num2;      //두 수를 입력받을 변수

    cin>>num1>>num2;

    cout<<gcd(num1,num2)<<"\n"<<lcm(num1,num2)<<"\n";


    return 0;
}