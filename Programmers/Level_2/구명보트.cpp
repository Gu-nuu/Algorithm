#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> people, int limit)
{
    int answer = 0;

    sort(people.begin(), people.end()); // 사람들의 몸무게를 오름차순으로 정렬한다.

    int left = 0;
    int right = people.size() - 1;

    // 가장 작은 사람과 가장 무거운 사람과의 몸무게의 합을 계산하여 무게 제한 아래면 2명을 한번에 태울 수 있으므로 left는 증가시키고 right는 감소시켜
    // 두 사람 모두 태운 것으로 간주하며, 무게 제한을 초과하면 right를 감소시켜 무거운 사람 한 명만 태운 것으로 간주한다.
    // => 가장 가벼운 사람과 같이 보트에 태웠을 때 무게 제한을 초과했다면 그 사람은 무조건 혼자 타야한다!
    while (left <= right)
    {
        if (people[left] + people[right] <= limit)
        {
            left++;
            right--;
        }
        else
            right--;

        answer++;
    }

    return answer;
}

int main()
{
    vector<int> people = {70, 50, 80, 50};

    int limit = 100;

    cout << solution(people, limit) << endl;

    return 0;
}