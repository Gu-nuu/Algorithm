#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements)
{
    int answer = 0;
    set<int> s;
    int length = elements.size();

    for (int i = 1; i <= length; i++)
    {
        for (int j = 0; j < elements.size(); j++)
        {
            int sum = 0;
            for (int k = j; k < j + i; k++)
            {
                sum += elements[k % length];
            }
            s.insert(sum);
        }
    }

    answer = s.size();

    return answer;
}