#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

//문제를 잘못 이해해서 한참을 헤메고 있다가 다른 사람의 질문을 보고 문제를 깨달았다. 이 문제에서의 핵심은 바로 "진짜 약수가 모두 주어질 때"이다.
//진짜 약수가 "모두" 주어진다는 말은 예를 들어 12를 출력해야 하는 문제일 때 입력에는 무조건 2 3 4 6이 들어온다는 것이다. 물론 꼭 오름차순으로 들어오는 것은 아니다. 
//24를 예로 들어도 마찬가지로 입력으로는 무조건 2 3 4 6 8 12가 들어온다. 3 4 8 이런식으로 일부분만 입력으로는 절대 들어올 수가 없다.
//따라서 진짜 약수들을 모두 순서에 상관없이 입력받은 후 이를 정렬을 하고 (정렬된 진짜 약수들의 처음 수 * 정렬된 진짜 약수들의 마지막 수)를 계산한다면 
//구하려는 수를 얻어낼 수 있다. 예를 들어 구해야 할 수가 12라면 입력으로는 4 3 2 6 이런 식으로 들어올 것이고 이를 정렬하면 2 3 4 6, 그리고 첫 숫자인
//2와 마지막 숫자인 6을 곱하면 12를 얻어낼 수 있다.

vector<int> arr;

int main()
{
    ios::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int cnt;
    cin>>cnt;


    for(int i=0; i<cnt; i++)
    {
        int a;
        cin>>a;
        arr.push_back(a);
    }

    sort(arr.begin(),arr.end());        //입력받은 진짜 약수들을 정렬한다.

    cout<<arr[0]*arr[arr.size()-1]<<"\n";       //진짜 약수들의 첫 숫자와 마지막 숫자를 곱해 구하려는 값을 얻어낸다.

    return 0;
}