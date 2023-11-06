#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// 우선 가장 첫번째 우선순위인 단어의 빈도수가 만약 같다면 바로 다음 우선순위인 단어의 길이를 확인한다.
// 만약 단어의 길이도 같다면 마지막 우선순위인 알파벳 사전 순대로 정렬하게 된다.
// 단어의 빈도수는 같으면서 단어의 길이가 다르다면 단어의 길이가 긴 순으로 정렬한다.
// 단어의 빈도수가 다르다면 단어의 빈도수가 가장 큰 순으로 정렬한다.
bool compare(pair<string, int> a, pair<string, int> b)
{
    if (a.second == b.second)
    {
        if (a.first.size() == b.first.size())
            return a.first < b.first;
        else
            return a.first.size() > b.first.size();
    }
    else
        return a.second > b.second;
}

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    map<string, int> counter; // 입력받은 단어들에 대해 외워야할 단어와 빈도수를 저장할 map

    for (int i = 0; i < N; i++)
    {
        string word;
        cin >> word;

        if (counter.find(word) == counter.end() && word.size() >= M) // 길이가 M보다 길면서 기존에 단어장에 없던 단어인 경우에 map에 단어와 빈도수를 저장한다.
        {
            counter.insert({word, 1});
        }
        else if (counter.find(word) != counter.end()) // 기존에 단어장에 있던 단어의 경우 빈도수를 1 증가시켜준다.
        {
            auto iter = counter.find(word);
            iter->second++;
        }
    }

    vector<pair<string, int>> wordList(counter.begin(), counter.end()); // 단어장에 우선순위를 적용하여 정렬하기 위해 map에 데이터를 그대로 옮긴 vector를 생성

    sort(wordList.begin(), wordList.end(), compare); // 우선 순위 조건에 따라 vector를 정렬

    for (int i = 0; i < wordList.size(); i++)
        cout << wordList[i].first << "\n";

    return 0;
}