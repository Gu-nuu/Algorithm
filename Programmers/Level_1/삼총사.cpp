#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> number)
{
    int answer = 0;

    vector<int> box(number.size() - 3, 0);

    for (int i = 0; i < 3; i++)
    {
        box.push_back(1);
    }

    do
    {
        int sum = 0;
        for (int i = 0; i < box.size(); i++)
        {
            if (box[i] == 1)
            {
                sum += number[i];
            }
        }

        if (sum == 0)
        {
            answer++;
        }

    } while (next_permutation(box.begin(), box.end()));

    return answer;
}