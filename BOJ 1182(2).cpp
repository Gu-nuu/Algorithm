#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

//이 파일에서는 백트래킹 알고리즘의 유형으로 접근하였다. 중첩되지 않도록 뽑는 것이므로 반복문 내의 재귀함수의 형태는
//index 값을 인자로 가지는 조합을 뽑는 사용자 정의 함수의 형태를 띄게 된다.

int n,s;
int cnt=0;

vector<int> arr(20);

void backtracking(int index,int sum)        //백트래킹 알고리즘의 틀에 더 가깝게 풀어낸 풀이이다.
{
    //카운팅 하는 조건에서 조금 달라지는데, 만약 index!=0의 조건이 없다면 공집합일 경우에 카운팅을 한번 더 더하게 되기 때문에
    //문제가 발생한다.(이 부분은 조금 더 공부 필요)
    if(sum==s && index!=0)      
        cnt++;

    if(index==n)        //수열의 끝에 도달한 경우 return 하는 base case는 동일하다.
        return;

    for(int i=index; i<n; i++)      
        backtracking(i + 1, sum + arr[i]);
    //이 부분에서 차이가 나는데 기존의 브루트 포스 알고리즘 같은 경우는 수열이 들어갈지와 안 들어갈지를 두 개의 재귀호출로 구분했다면
    //이 for문은 index 값을 증가시켜주고 이를 재귀호출의 인자값으로 가져가며 이는 숫자 중복의 발생을 방지할 수 있다. 그리고 반복문 속에서의
    //재귀 호출을 통해 부분 수열 1개를 뽑는 경우부터 2개, 3개, 4개, 5개의 순서로 뽑아 이들의 합을 구할 수 있도록 한다.
}

int main()
{
    ios::ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);

    cin>>n>>s;

    for(int i=0; i<n; i++)
        cin>>arr[i];

    backtracking(0,0);

    cout<<cnt<<"\n";

    return 0;
}