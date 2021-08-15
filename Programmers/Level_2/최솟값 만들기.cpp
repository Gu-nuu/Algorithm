#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    priority_queue<int, vector<int>, less<int>> descend;   // 내림차순의 순서대로 가장 큰 수부터 pop되는 우선순위 큐
    priority_queue<int, vector<int>, greater<int>> ascend; // 오름차순의 순서대로 가장 작은 수부터 pop되는 우선순위 큐

    for (int i = 0; i < A.size(); i++)
    {
        descend.push(A[i]);
        ascend.push(B[i]);
    }

    while (!descend.empty()) // 각 우선순위 큐에 두 개의 벡터를 각각 저장 후 pop을 하게 되면 하나의 큐에서는 큰 수부터 하나의 큐에서는 작은 수부터 나오게 된다
    {
        answer += (descend.top() * ascend.top());
        descend.pop();
        ascend.pop();
    }

    return answer;
}

/* 정답은 맞지만 시간초과가 발생하는 solution
int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    int length = A.size();

    // C++ 알고리즘 헤더의 min_element(), max_element() 함수를 이용하여 가장 큰 원소와 가장 작은 원소를 각각 찾아 계산해준 뒤 해당 원소들을 벡터에서 지워가면서 반복 수행
    for (int i = 0; i <length; i++)
    {
        int temp_a = *min_element(A.begin(), A.end());
        int index_a = min_element(A.begin(), A.end()) - A.begin();

        int temp_b = *max_element(B.begin(), B.end());
        int index_b = max_element(B.begin(), B.end()) - B.begin();

        answer += (temp_a * temp_b);

        A.erase(A.begin() + index_a);
        B.erase(B.begin() + index_b);
    }

    return answer;
}
*/

int main()
{
    vector<int> a = {1, 4, 2};
    vector<int> b = {5, 4, 4};

    cout << solution(a, b) << endl;

    return 0;
}