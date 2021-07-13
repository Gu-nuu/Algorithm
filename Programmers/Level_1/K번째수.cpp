#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
    vector<int> answer;

    for (int i = 0; i < commands.size(); i++)
    {
        vector<int> cm;
        for (int j = 0; j < commands[i].size(); j++)        // 커맨드가 2차원 벡터의 형태이므로 각각 1차원 벡터로 분리하여 구분
            cm.push_back(commands[i][j]);

        vector<int> divide;
        for (int k = cm[0] - 1; k < cm[1]; k++)     // 분리한 커맨드의 시작 숫자와 끝 숫자를 기반으로 나눠지는 수를 구함
            divide.push_back(array[k]);

        sort(divide.begin(), divide.end());     // 나눠진 수를 정렬

        answer.push_back(divide[cm[2] - 1]);        // 정답을 저장할 벡터에 K번째 수를 push
    }

    return answer;
}

int main()
{

    vector<int> array = {1, 5, 2, 6, 3, 7, 4};
    vector<vector<int>> commands = {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}};

    vector<int> output = solution(array, commands);

    for (int i = 0; i < output.size(); i++)
        cout << output[i] << " ";

    return 0;
}