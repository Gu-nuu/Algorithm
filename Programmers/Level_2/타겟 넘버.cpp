#include <string>
#include <vector>

using namespace std;

int answer = 0;

void DFS(vector<int> &n, int cur, int index, int target)
{
    if (index == n.size())
    {
        if (cur == target)
        {
            answer++;
        }
        return;
    }

    DFS(n, cur + n[index], index + 1, target);
    DFS(n, cur - n[index], index + 1, target);
}

int solution(vector<int> numbers, int target)
{

    answer = 0;
    DFS(numbers, 0, 0, target);

    return answer;
}