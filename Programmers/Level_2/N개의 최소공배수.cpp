#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int gcd(int x, int y) // 유클리드 호제법을 이용하여 두 수의 최대공약수를 구하는 함수. 최대공배수를 구하는 공식에 사용하기 위함
{
    int z;
    while (y != 0)
    {
        z = x % y;
        x = y;
        y = z;
    }

    return x;
}

int lcm(int x, int y) // 두 수의 최소공배수를 구하는 함수
{
    return (x * y) / (gcd(x, y));
}

int solution(vector<int> arr)
{
    int answer = 0;

    stack<int> box; // 여러 개의 수의 최소공배수를 구해야 하므로 수를 2개씩 계속 뽑아서 최소공배수를 구하기 위해 스택을 사용

    for (int i = 0; i < arr.size(); i++)
        box.push(arr[i]);

    while (true)
    {
        if (box.size() == 1) // 2개씩 수를 뽑아서 최소공배수를 계산한 후 최종적으로 계산이 마무리되면 수는 최종적인 최소공배수가 남음
        {
            answer = box.top();
            break;
        }

        int tmp1 = box.top();
        box.pop();
        int tmp2 = box.top();
        box.pop();

        box.push(lcm(tmp1, tmp2)); // 스택의 2개의 수를 pop한 후 최소 공배수를 계산하고 다시 push해줌
    }

    return answer;
}

int main()
{
    vector<int> arr = {1, 2, 3};

    cout << solution(arr) << endl;

    return 0;
}