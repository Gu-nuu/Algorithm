#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers)
{
    int answer = -1;
    int sum = 0;
    int findSize = 10 - numbers.size();
    sort(numbers.begin(), numbers.end());

    for (int i = 0; i <= 9; i++)
    {
        if (binary_search(numbers.begin(), numbers.end(), i) == false)
        {
            findSize--;
            sum += i;
        }

        if (findSize <= 0)
        {
            break;
        }
    }

    answer = sum;

    return answer;
}