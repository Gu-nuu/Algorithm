#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int n,m;        //백트래킹 함수 안에서도 사용하는 값이므로 전역으로 설정하였다.
vector<int> arr(8);     //수열을 담는 벡터
vector<bool> check(8);      //수열 벡터에 담긴 그 숫자가 사용되었는지 아닌지를 판단하는 벡터

//이 함수가 백트래킹의 가장 기본이 되는 틀 함수이기 때문에 잘 알아둘 필요가 있었다. 직접 그려보고 코드로 옮기는 것을 잊지 말자
void backtracking(int x)
{
    if(x==m)        //Base Case. 재귀의 종료 조건으로 수열이 완성되면 그 수열을 출력한다.
    {
        for(int i=0; i<m; i++)
            cout<<arr[i]<<" ";
        cout<<"\n";
        return;
    }

    for(int i=1; i<=n; i++)
    {
        if(!check[i-1])     //중목을 확인하는 부분.
        {
            arr[x]=i;       //수열을 채움
            check[i-1]=true;        //사용한 숫자임을 표시
            backtracking(x+1);      //재귀를 이용하여 수열에 다음 수를 넣기 위해 넘어감
            check[i-1]=false;
            arr[x]=0;       //재귀가 끝난 후 다시 값을 돌려놓음
        }
    }
}

int main()
{
    ios::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n>>m;

    backtracking(0);

    return 0;
}