#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

//기존의 N과 M 시리즈와 다를게 없는 문제였다. 여기서는 순서를 상관하지 않는 조합을 뽑는 것이 문제이기 때문에 기존의 15650번과 문제의 틀이 거의
//같다고 해도 무방하다. 따라서 i의 인덱스 값을 재귀 호출의 인자 값으로 가져가는데 이때 유의해야 할 점은 i+1이 아니라 바로 i를 넣어주는 것이다.
//i+1을 사용하는 이유는 앞에서 사용한 값을 다시 사용하지 않고 다음 인덱스의 값을 배열에 넣어 사용함으로써 (1,1) (2,2)와 같은 중첩된 수열을 만드는 것을
//방지 하는데 이 문제에서는 그 중첩된 수열을 출력해야 하므로 i+1이 아닌 ㅑ를 인자 값으로 넣어준다.

int n,m;

vector<int> arr(9);     //수열을 담을 벡터

void backtracking(int num, int count)
{
    if(count==m)
    {
        for(int i=0; i<m; i++)
            cout<<arr[i]<<" ";
        cout<<"\n";
        return;
    }

    for(int i=num; i<=n; i++)
    {
        arr[count]=i;
        backtracking(i,count+1);        //기존 조합 뽑기 문제와 비슷하지만 중복 조합을 뽑을 땐 i+1이 아닌 i를 인자 값으로 가져간다.
    }
}

int main()
{
    ios::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n>>m;

    backtracking(1,0);

    return 0;
}