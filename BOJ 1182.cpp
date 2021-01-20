#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

//이 파일에서는 브루트포스 알고리즘의 유형으로 접근하였다. 이 문제에서 재귀 호출을 호출하는 경우는 2가지인데
//하나는 현재 가리키고 있는 수를 사용하는 경우이고 다른 하나는 현재 가리키고 있는 숫자를 사용하지 않는 경우이다.

int n,s;
int cnt=0;

vector<int> arr(20);

void solve(int index,int sum)
{
    if(index==n)        //재귀 호출의 base case. 입력 받은 N개의 수열을 모두 재귀 호출을 이용해 모두 탐색한 후 끝까지 탐색했으면 return한다.
        return;

    if(sum+arr[index]==s)       //만약 수열들의 합이 만족하는 값을 찾았다면 cnt 변수를 증가시켜준다.
        cnt++;

    solve(index+1,sum); //숫자를 사용하지 않는 경우. 즉 arr[index]의 값을 사용하지 않고 index+1을 하여 다음 index로 넘어가겠다라는 것을 의미한다.

    solve(index+1,sum+arr[index]);  //숫자를 사용하는 경우. 재귀가 반복될수록 하나의 부분 수열을 뽑던 조합에서 2개를 뽑는 조합으로, 
                                    //2개에서 3개로 뽑는 조합처럼 다음 뽑을 조합의 개수를 늘어나게 된다.
}


int main()
{
    ios::ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);

    cin>>n>>s;

    for(int i=0; i<n; i++)
        cin>>arr[i];

    solve(0,0);

    cout<<cnt<<"\n";

    return 0;
}