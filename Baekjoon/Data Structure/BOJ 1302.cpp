#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

// first = 책의 이름, second = 책이 팔린 권수
// 기본적으로 책이 가장 많이 팔린 순으로 내림차순으로 정렬해주며 만약 팔린 권수가 같다면 사전 순으로 정렬할 수 있도록 했다.
bool compare(pair<string, int> a, pair<string, int> b)
{
    if (a.second == b.second)
        return a.first < b.first;
    else
        return a.second > b.second;
}

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;

    cin >> N;

    map<string, int> m; // 팔린 책의 제목과 권수를 저장하기 위한 map

    for (int i = 0; i < N; i++)
    {
        string book;
        cin >> book;

        if (m.find(book) == m.end()) // 기존에 없던 새로운 책이면 map에 정보를 추가해준다.
        {
            m.insert({book, 1});
        }
        else // 기존에 있던 책이면 팔린 책의 권수를 증가시켜준다.
        {
            auto temp = m.find(book);
            temp->second++;
        }
    }

    // 가장 많이 팔린 책을 기준으로 정렬하며 많이 팔린 책이 여러 권일 경우 사전 순으로 정렬해야하기 때문에 map을 vector로 옮긴 뒤 정렬 조건을 추가해주었다.
    vector<pair<string, int>> v(m.begin(), m.end());

    sort(v.begin(), v.end(), compare);

    cout << v[0].first << "\n";

    return 0;
}