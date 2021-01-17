#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;


//15649번 문제와 거의 유사했지만 달랐던 부분이다. 15649번은 오름차순 출력이 아니다. 이 말인 즉슨 순서를 신경쓰기 때문에 백트래킹을 이용하여
//순열을 뽑는 문제가 된다. 예를 들어 15649번에서는 (1,2,3)과 (3,1,2)를 모두 구분해서 출력하기 때문에 순열을 뽑는 문제라는 것이다. 하지만
//이 문제에서는 오름차순으로 출력해야 하며 중복되는 수열을 출력하지 말라고 한다. 이 말은 (1,2,3)이든 (3,1,2)든 모두 (1,2,3)으로 보겠다는 것이다
//결국 이 문제가 15649번과 다른 점은 바로 순열이 아닌 조합을 뽑는 문제라는 점이다.


int n,m;

vector<int> arr(9);     //수열을 담을 벡터
vector<bool>check(9);       //수열에서 특정 자리의 숫자가 사용되었는지의 여부를 확인할 벡터

void backtracking(int num, int count)       //15649번과 다르게 num이라는 파라미터를 하나 더 가져간다.
{
    if(m==count)        //출력해야 할 갯수에 도달했다면 수열을 출력
    {
        for(int i=0; i<m; i++)
            cout<<arr[i]<<" ";
        cout<<"\n";
        return;
    }

    for(int i=num; i<=n; i++)       //15649번의 for문과 살짝 다른 점은 바로 for문의 i를 재귀의 인자 값으로 가져간다는 점이다.
    {                               //만약 i를 재귀의 인자로 가져간다면 이미 찾은 조합의 경우는 출력하지 않도록 할 수 있다!
        if(!check[i])
        {
            arr[count]=i;
            check[i]=true;
            backtracking(i+1,count+1);
            check[i]=false;
        }
        
    }
}

int main()
{
    ios::ios_base::sync_with_stdio(false);

    cin>>n>>m;

    backtracking(1,0);

    return 0;
}