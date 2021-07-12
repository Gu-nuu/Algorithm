#include <iostream>
#include <stdio.h>
#include <vector>
#define MAX 987654321;
using namespace std;

vector <int> arr;       //심어져 있는 가로수들을 저장할 벡터
vector <int> diff;      //이미 심어져있는 가로수들간의 거리 차이를 저장하는 벡터

int gcd(int x,int y)        //유클리드 호제법을 이용하여 최대공약수를 구하는 함수
{
    int temp;
    while(true)
    {
        temp=x%y;

        if(temp==0)
            return y;
        else
        {
            x=y;
            y=temp;
        }
    }
}

int main()
{
    ios::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int N;      //이미 심어져 있는 가로수의 갯수
    
    cin>>N;

    for(int i=0; i<N; i++)
    {
        int num;
        cin>>num;
        arr.push_back(num);
    }

    for(int i=0; i<arr.size()-1; i++)       //이미 심어져있는 가로수들의 거리를 입력받은 후 이 가로수들의 거리의 차를 구해 새로운 벡터에 저장한다.
        diff.push_back(arr[i+1]-arr[i]);

    //이 부분이 핵심! 가로수들의 거리의 차를 구하고 이 거리의 차들의 최대 공약수 값이 가로수를 심어야 하는 간격의 값이 된다.
    //근데 처음에 구현할 때에는 시간 초과에 걸릴 듯하여 가로수 거리 차의 첫번째 값과 두번째 값으로만 최대 공약수를 구했는데 틀린 답이 나왔다.
    //그 이후에 나올 숫자들에 대해서도 최대 공약수를 고려해줘야 했기 때문이다.
    //따라서 이미 심어져 있는 가로수의 거리 차이의 모든 최대 공약수 값들 중에서도 최소 값을 구해야 한다.
    int min_gcd=MAX;
    for(int i=0; i<diff.size()-1; i++)
    {
        int temp;
        temp=gcd(diff[i],diff[i+1]);        //이미 심어져있는 가로수의 거리 차이의 최대 공약수를 반복문을 이용하여 모두 구한다.
        if(min_gcd > temp)
            min_gcd=temp;       //최대 공약수 값들 중 가장 최소인 값을 구한다.
    }

    int cnt=0;
    for(int i=arr[0]; i<=arr[arr.size()-1]; i+=min_gcd)     //가로수의 최소 간격을 구했다면 이를 가지고 가로수가 총 몇 개가 심어질 수 있는지를 카운트한다.
        cnt++;

    cout<<cnt-N<<"\n";      //총 몇 개가 심어질 수 있는지 카운트를 한 후에 이미 심어져 있는 가로수의 갯수를 빼준다면 새로 심어야 될 가로수의 갯수가 나온다.

    // int ans=((arr[arr.size()-1]-arr[0])/min_gcd)-(N-1);      //이건 구글링을 하다가 알게 된 간단 해결 수식이다...
    // cout<<ans<<"\n";

    return 0;
}