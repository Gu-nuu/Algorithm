#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<double, int> a, pair<double, int> b) // 실패율 값을 기준으로 내림차순 정렬
{
    return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages)
{
    vector<int> answer;

    // 각 스테이지에 머물러 있는 사람들의 수를 담을 벡터
    // 스테이지는 1단계부터 존재하며 N + 1은 모두 마지막 스테이지까지 모두 클리어한 사람이므로 N + 2만큼 벡터의 크기를 잡는다.
    // ex) N = 5 ==> 0(무시) 1 2 3 4 5(각 스테이지) 6(모두 클리어한 사람)
    vector<int> stage_people(N + 2, 0);

    // 실패율과 각 스테이지 단계를 저장할 벡터. 실패율에 따라 내림차순으로 정렬하며 이에 따라 스테이지도 정렬되야 하므로 pair로 묶음
    vector<pair<double, int>> failure_rate;

    for (int i = 0; i < stages.size(); i++) // 각 단계에 머물러있는 사람들의 index의 수를 증가시켜 사람의 수를 저장
        stage_people[stages[i]]++;

    for (int i = 1; i < stage_people.size() - 1; i++) // 각 스테이지에 따라 실패율을 계산하므로 모두 클리어한 사람은 빼고 계산
    {
        double sum = 0;
        for (int j = i; j < stage_people.size(); j++) // 각 스테이지에 도전한 사람들의 수를 계산. 특정 스테이지 이전 단계의 사람들은 도전한 사람들이 아님.
            sum += stage_people[j];

        failure_rate.push_back({(double)stage_people[i] / sum, i}); // 계산한 실패율과 함께 스테이지의 번호를 벡터에 저장
    }

    stable_sort(failure_rate.begin(), failure_rate.end(), compare); // 내림차순으로 정렬하되 같은 값이 있으면 들어온 순서를 유지해야 하므로 stable sort 사용

    for (int i = 0; i < failure_rate.size(); i++) // 정렬 후 스테이지 번호를 저장
        answer.push_back(failure_rate[i].second);

    return answer;
}

int main()
{
    int N = 5;
    vector<int> stages = {2, 1, 2, 6, 2, 4, 3, 3};
    vector<int> ans = solution(N, stages);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}