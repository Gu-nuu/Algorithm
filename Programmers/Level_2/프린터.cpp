#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location)
{
    int answer = 0;

    priority_queue<int> order;     // 중요도가 높은 문서부터 출력하려면 입력한 중요도들 중 가장 큰 값부터 return 되어야 한다.
    queue<pair<int, int>> printer; // 문서 번호의 문서의 중요도를 묶어 저장할 pair 큐

    for (int i = 0; i < priorities.size(); i++) // 우선순위 큐와 프린터기 큐에 각각 중요도와 문서번호를 저장
    {
        order.push(priorities[i]);
        printer.push({i, priorities[i]});
    }

    int cnt = 0;

    while (true)
    {
        int temp_doc = printer.front().first;
        int temp_weight = printer.front().second;

        int temp_order = order.top();

        printer.pop();

        if (temp_weight == temp_order) // 만약 중요도가 가장 높은 문서가 인쇄 대기 목록의 가장 앞인 경우
        {
            order.pop(); // 프린터기 인쇄 대기 목록에서 지워준 후(출력), 인쇄 요청 문서의 순서를 증가
            cnt++;

            if (temp_doc == location) // 만약 이번에 출력될 문서가 내가 인쇄 요청한 문서인 경우 순서를 return 후 반복문 break
            {
                answer = cnt;
                break;
            }
        }
        else
            printer.push({temp_doc, temp_weight}); // 중요도가 가장 높은 순서가 아닌 경우 다시 프린터기 큐 맨 뒤에 push
    }

    return answer;
}

int main()
{
    vector<int> priorities = {2, 1, 3, 2};
    int location = 2;

    cout << solution(priorities, location) << endl;

    return 0;
}