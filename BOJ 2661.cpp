#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

//이 문제에서의 핵심은 좋은 수열인지 아닌지를 구분하는 것이다. 이 방법 구현이 어려워서 구글링의 도움을 받았다. 하나의 수열 내에서
//서로 인접한 부분 수열이 서로 동일하면 좋은 수열이 아니다. 여기서 중요한 점은 바로 "인접한" 부분 수열의 동일 여부이다. 예를 들어
//1232123은 123으로 동일한 부분 수열이 있지만 인접하지 않기 때문에 좋은 수열이라고 말할 수 있다. 하지만 12312321에서는 123이 같은 부분 수열이면서
//인접하기 때문에 나쁜 수열이다. 따라서 수열이 좋은지 나쁜지를 검사할 때에는 전체 수열의 절반만을 검사하면 된다. 한 수열에 대해서 count 변수를
//이용하여 임의의 string 변수에 문자를 담고 이를 반으로 쪼개서 반씩 비교할 때 같은 수열이 나오면 나쁜 수열이 된다. 예를 들어 12312313이라는 수열에서
//count 변수로 하나 하나 substring을 비교한다면 (1) (1 vs 2) (12 vs 31) (123 vs 123) 등의 방식으로 수열 비교가 일어나게 된다. 이때 4번째 부분 수열 검사에서
//동일한 부분 수열이 나오므로 이 수열은 나쁜 수열이 되는 것이다.

int N;
vector<int> arr(80);        //수열을 담을 벡터
string str;     //수열을 string으로 변환할 변수
bool flag;      //수열을 판단할 변수

void solve(int count)
{
    if(flag)
        return;     //이 부분도 중요한데, 좋은 수열이 여러 개가 나올 수 있지만 문제에서는 가장 작은 수열을 출력하라 했으므로 가장 처음에 나오는 수열이
                    //가장 작은 좋은 수열이 된다. 따라서 처음으로 좋은 수열을 찾아 출력했다면 출력 후 flag를 true로 바꿔 재귀를 종료시킨다.

    str="";
    for(int i=0; i<count; i++)
        str+=to_string(arr[i]);     //뽑아낸 수열을 string으로 변환하여 합쳐준다. 이때 수열은 count에 따라 하나씩 뽑힌다.

    //좋은 수열인지 아닌지를 판단하는 반복문. 좋은 수열인지 아닌지를 판단 후 count를 올려줘야 하기 때문에 base case나 recursive case보다 먼저 위치한다.  
    for(int i=1; i<=count/2; i++)       
    {                                         
        for(int j=0; j<=count-2*i; j++)
        {
            if(str.substr(j,i)==str.substr(j+i,i))
                return;
        }
    }

    if(count==N)        //위 좋은 수열 판단에서 return 당하지 않고 count가 N까지 도달했다면 좋은 수열이므로 이를 출력해준다.
    {
        for(int i=0; i<N; i++)
            cout<<arr[i];
        flag=true;
        return;
    }

    for(int i=0; i<N; i++)
    {
        arr[count]=i+1;
        solve(count+1);
    }
}

int main()
{
    ios::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>N;

    solve(0);

    return 0;
}