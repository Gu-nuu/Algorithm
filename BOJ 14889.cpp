#include <stdio.h>
#include <iostream>
#include <vector>
#define MAX 987654321
using namespace std;

int N;
int **box;      //사람들의 능력치를 입력받을 이중 포인터
vector<bool> check(N+1);        //N명의 사람들 중에서 두 팀으로 나눈 것을 true와 false 값을 구분하기 위한 벡터
int ans;

void solve(int index, int count)        //두 팀을 순서에 상관없이 뽑는 "조합"이므로 index값을 파라미터로 가져간다.
{
    if(count==N/2)      //Base Case.두 팀을 뽑았을 경우 각 팀의 능력치의 합을 구하고 둘 중 차이가 더 작은 값을 선정한다.
    {
        int start_sum=0;
        int link_sum=0;

        for(int i=1; i<=N; i++)
        {
            for(int j=1; j<=N; j++)
            {
                //check 값이 true인 경우엔 스타트 팀을 뽑은 것으로 판단한다. 이때 능력치를 더할 땐 만약 1번과 3번이 스타트 팀일 경우 이차원 배열에서
                //1행 3열의 값과 3행 1열의 값을 더하는 것이다. N이 4일 때 만약 start 팀이 1번과 2번이라면 check[1]과 check[2]에는 true값이 저장되어 있을
                //것이다. 따라서 check[i], check[j]를 통해 모든 선수들의 능력치 이차원 배열 안에서 스타트팀에 해당하는 행과 열 값을 가져올 수 있게 된다.
                if(check[i]==true && check[j]==true)        
                    start_sum+=box[i][j];
                
                //스타트팀의 능력치를 더하는 것과 마찬가지로 링크 팀도 같은 방법으로 진행된다. check 벡터의 모든 기본 값을 false 일때 스타트팀을 뽑았다면
                //스타트팀 번호를 제외한 나머지는 false이므로 이는 링크 팀이라고 봐도 무방하다.
                if(check[i]==false && check[j]==false)
                    link_sum+=box[i][j];
            }
        }

        ans=min(ans,abs(start_sum-link_sum));       //스타트팀과 링크팀의 능력치의 합을 모두 구했다면 능력치의 차를 ans 변수에 저장한다. 이때
                                                    //최솟값을 정하는 min 함수를 쓰는 이유는 재귀 호출을 하면서 스타트팀과 링크팀으로 나뉠 수 있는
                                                    //모든 경우의 수에 대한 능력치의 합을 구하므로 여기서 가장 작은 값을 뽑아줘야 하기 때문이다.

        return;
    }

    for(int i=index; i<=N; i++)     //조합을 뽑는 경우로 반복문에서 재귀 호출을 한다.
    {
        check[i]=true;
        solve(i+1, count+1);
        check[i]=false;
    }
}

int main()
{
    ios::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    ans=MAX;        //능력치 합의 최솟값을 저장하는 변수이므로 처음에는 가장 큰 값을 넣어준다.

    cin>>N;

    box=new int*[N+1];
    for(int i=0; i<N+1; i++)
        box[i]=new int[N+1];        //이차원 동적 배열을 만들어주는데 1부터 인덱스 값을 사용하기 위해 N+1개의 배열을 만들어준다.

    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
            cin>>box[i][j];
    }

    solve(1,0);

    cout<<ans<<"\n";


    return 0;
}