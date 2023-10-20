#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 유클리드 호제법을 이용해 최대공약수를 구하는 함수
// 이미 심어져 있는 가로수 사이의 거리의 최대공약수를 통해 더 심어야 하는 가로수의 개수를 구해야 한다.
int getGCD(int a, int b)
{
    int c;

    if (a > b)
    {
        while (b != 0)
        {
            c = a % b;
            a = b;
            b = c;
        }

        return a;
    }
    else
    {
        while (a != 0)
        {
            c = b % a;
            b = a;
            a = c;
        }

        return b;
    }
}

int main()
{
    int N;

    cin >> N;

    vector<int> tree; // 이미 심어져있는 가로수의 위치를 저장
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;

        tree.push_back(num);
    }

    vector<int> distance; // 각 가로수들 사이의 거리를 계산해 저장
    for (int i = 1; i < N; i++)
    {
        distance.push_back(tree[i] - tree[i - 1]);
    }

    // 처음에는 가로수 사이의 거리 값을 서로 인접한 값들끼리만(distance[i], distance[i-1]로 두고 반복문을 돌림) 최대공약수를 구한 뒤 그 중 최솟값을 최대공약수로 지정했는데 계속 틀렸다...
    // 맨 처음 두 값으로 최대공약수를 구한 뒤 나머지 가로수들 간의 모든 거리에 대해 최대공약수를 구해야 한다.
    int distGCD = getGCD(distance[0], distance[1]);
    for (int i = 2; i < distance.size(); i++)
    {
        distGCD = getGCD(distGCD, distance[i]);
        // *** 오타가 나서 distance[2]로 제출했는데 정답처리가 됐다... 뭐지...? ***
    }

    int newTree = 0;
    for (int i = 0; i < distance.size(); i++)
    {
        newTree = newTree + ((distance[i] / distGCD) - 1);
        // 이미 심어진 가로수 간의 거리를 최대공약수로 나눈 뒤 1을 빼주면 그 거리 사이에 몇 개의 가로수를 심어야 하는지 알 수 있다.
        // 이 때 1을 빼주는 이유는 가로수는 양 끝에 모두 심어져 있기 때문이다.
    }

    cout << newTree << "\n";

    return 0;
}