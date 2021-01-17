#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int n,m;
vector<int> arr(8);

void backtracking(int count)
{
    if(count==m)
    {
        for(int i=0; i<m; i++)
            cout<<arr[i]<<" ";
        cout<<"\n";
        return;
    }

    for(int i=1; i<=n; i++)     //순서에 관계있는 수열인 순열을 뽑는 것이기 때문에 i 값을 파라미터로 넣어줄 필요가 없다. 기존 15649번과 거의 비슷하며
    {                           //중복된 숫자 사용을 방지하기 위한 check 배열만 없앤다면 중복순열을 뽑아낼 수 있다.
        arr[count]=i;
        backtracking(count+1);
    }
}

int main()
{
    ios::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n>>m;

    backtracking(0);

    return 0;
}