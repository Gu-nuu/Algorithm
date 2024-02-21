#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// 장르별 재생횟수가 많은 순으로 정렬
bool compare1(pair<string, int> a, pair<string, int> b)
{
    return a.second > b.second;
}

// 노래별 재생횟수가 많은 순으로 정렬하되 만약 횟수가 같으면 고유번호가 낮은 노래 순으로 정렬
bool compare2(pair<string, pair<int, int>> a, pair<string, pair<int, int>> b)
{
    if (a.second.second == b.second.second)
        return a.second.first < b.second.first;
    else
        return a.second.second > b.second.second;
}

vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;

    map<string, int> m1;
    // 장르, 장르별 재생횟수

    vector<pair<string, pair<int, int>>> v2;
    // 장르, 고유번호, 노래별 재생횟수

    for (int i = 0; i < genres.size(); i++)
    {
        if (m1.find(genres[i]) != m1.end())
            m1.find(genres[i])->second += plays[i];
        else
            m1.insert({genres[i], plays[i]});

        v2.push_back({genres[i], {i, plays[i]}});
    }

    // map에 저장된 데이터를 vector로 옮겨 정렬
    vector<pair<string, int>> v1(m1.begin(), m1.end());
    sort(v1.begin(), v1.end(), compare1);

    sort(v2.begin(), v2.end(), compare2);

    for (int i = 0; i < v1.size(); i++)
    {
        int count = 0;

        for (int j = 0; j < v2.size(); j++)
        {
            if (count == 2) // 최대 2곡만 수록하는지를 판단
                break;

            // 장르별 재생횟수가 가장 많은 장르인지를 우선 판단 후
            // 노래별 재생횟수와 고유번호로 정렬된 값을 answer에 저장
            if (v1[i].first == v2[j].first)
            {
                answer.push_back(v2[j].second.first);
                count++;
            }
        }
    }

    return answer;
}