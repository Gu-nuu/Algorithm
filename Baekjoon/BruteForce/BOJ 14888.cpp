#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <limits.h>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<long long> A;
    for (int i = 0; i < N; i++)
    {
        long long num_A;
        cin >> num_A;

        A.push_back(num_A);
    }

    reverse(A.begin(), A.end());

    stack<long long> operand;

    for (int i = 0; i < N; i++)
    {
        operand.push(A[i]);
    }

    int plus, minus, multiple, divide;
    cin >> plus >> minus >> multiple >> divide;

    vector<int> box;

    for (int i = 0; i < plus; i++)
    {
        box.push_back(1);
    }
    for (int i = 0; i < minus; i++)
    {
        box.push_back(2);
    }
    for (int i = 0; i < multiple; i++)
    {
        box.push_back(3);
    }
    for (int i = 0; i < divide; i++)
    {
        box.push_back(4);
    }

    long long biggest = LLONG_MIN;
    long long smallest = LLONG_MAX;

    do
    {
        if (operand.empty())
        {
            for (int i = 0; i < N; i++)
            {
                operand.push(A[i]);
            }
        }

        for (int i = 0; i < box.size(); i++)
        {
            long long opr1 = operand.top();
            operand.pop();
            long long opr2 = operand.top();
            operand.pop();

            if (box[i] == 1)
            {
                operand.push(opr1 + opr2);
            }
            else if (box[i] == 2)
            {
                operand.push(opr1 - opr2);
            }
            else if (box[i] == 3)
            {
                operand.push(opr1 * opr2);
            }
            else if (box[i] == 4)
            {
                operand.push(opr1 / opr2);
            }
        }

        if (operand.top() > biggest)
        {
            biggest = operand.top();
        }
        
        if (operand.top() < smallest)
        {
            smallest = operand.top();
        }

        while (!operand.empty())
        {
            operand.pop();
        }

    } while (next_permutation(box.begin(), box.end()));

    cout << biggest << "\n"
         << smallest << "\n";

    return 0;
}
