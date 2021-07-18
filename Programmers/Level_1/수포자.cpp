#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers)
{
    // 수포자들이 문제를 찍을 때 번호의 패턴이 각각 존재
    int pattern1[5] = {1, 2, 3, 4, 5};
    int pattern2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int pattern3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

    int score[3] = {0, 0, 0}; // 맞은 문제의 수를 저장할 배열

    vector<int> answer;

    for (int i = 0; i < answers.size(); i++)
    {
        if (answers[i] == pattern1[i % 5]) // 패턴이 5개마다 반복하므로 이를 비교하여 정답인 경우 맞은 문제 수 배열 증가
            score[0]++;
    }

    for (int i = 0; i < answers.size(); i++)
    {
        if (answers[i] == pattern2[i % 8]) // 패턴이 8개마다 반복하므로 이를 비교하여 정답인 경우 맞은 문제 수 배열 증가
            score[1]++;
    }

    for (int i = 0; i < answers.size(); i++)
    {
        if (answers[i] == pattern3[i % 10]) // 패턴이 10개마다 반복하므로 이를 비교하여 정답인 경우 맞은 문제 수 배열 증가
            score[2]++;
    }

    int max = score[0];
    for (int i = 1; i < 3; i++) // 가장 문제를 많이 맞힌 사람을 구함
    {
        if (score[i] > max)
            max = score[i];
    }

    for (int i = 0; i < 3; i++) // 만약 가장 문제를 많이 맞힌 사람이 1명 이상이면 이들도 모두 포함
    {
        if (score[i] == max)
            answer.push_back(i + 1);
    }

    return answer;
}

int main()
{
    vector<int> answers = {1, 2, 3, 4, 5};

    vector<int> sol = solution(answers);

    for (int i = 0; i < sol.size(); i++)
        cout << sol[i] << " ";

    return 0;
}