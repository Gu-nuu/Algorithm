#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 처음에 문제를 접근할 때, 각 행에서의 최댓값과 그 최댓값의 index를 저장 후 다음 행을 탐색하면서 이전의 최댓값 index를 무시해가면서
// 최고점을 구하는 방식으로 진행했다. 하지만, 위와 같이 해결할 경우
// 1 | 2 | 3 | 5
// 5 | 6 | 7 | 100
// 4 | 3 | 2 | 1
// 다음과 같은 예시일 때, 최댓값은 107이 나와야하지만 기존의 알고리즘으로는 16이 도출되어 아예 틀린 접근이라는 것을 깨달았다.
// 따라서 각 행에서 자기 자신의 index를 제외한 최댓값을 열에다가 계속 누적시켜 더해간 후 마지막 행에 저장된 각 열들의 최대 점수합 중 제일 큰 값을 채택하는
// DP 알고리즘의 방식으로 문제를 해결하였다.

int solution(vector<vector<int>> land)
{
    int answer = 0;

    for (int i = 0; i < land.size() - 1; i++)
    {
        // 자기 자신의 index를 제외하고 나머지 3개의 점수들 중 가장 큰 숫자를 고를 수 있도록 했다.
        // 문제에서 N행 4열이라고 하였으므로 열은 상수로 고정되어있어 아래와 같이 코드를 작성할 수 있다.
        int max_col_0 = max({land[i][1], land[i][2], land[i][3]});
        int max_col_1 = max({land[i][0], land[i][2], land[i][3]});
        int max_col_2 = max({land[i][0], land[i][1], land[i][3]});
        int max_col_3 = max({land[i][0], land[i][1], land[i][2]});

        // 자기 자신의 index를 제외한 열 값들 중 찾아낸 최대 점수를 다음 행에 누적시켜 더해준다.
        land[i + 1][0] += max_col_0;
        land[i + 1][1] += max_col_1;
        land[i + 1][2] += max_col_2;
        land[i + 1][3] += max_col_3;
    }

    answer = *max_element(land[land.size() - 1].begin(), land[land.size() - 1].end()); // 마지막 행에는 각 열들이 가질 수 있는 최대 점수합들이 저장되어있다.

    return answer;
}

int main()
{
    vector<vector<int>> land = {{4, 3, 2, 1}, {2, 2, 2, 1}, {6, 6, 6, 4}, {8, 7, 6, 5}};

    cout << solution(land) << endl;

    return 0;
}