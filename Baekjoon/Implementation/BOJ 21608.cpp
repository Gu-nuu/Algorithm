#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits.h>
using namespace std;

bool is_adj(int r1, int c1, int r2, int c2)
{
    if (abs(r1 - r2) + abs(c1 - c2) == 1)
        return true;
    else
        return false;
}

// 상, 하, 좌, 우
int dir[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<vector<int>> seat(N, vector<int>(N, 0));
    vector<int> student;
    vector<vector<int>> student_like;

    for (int i = 0; i < N * N; i++)
    {
        int temp_student;
        cin >> temp_student;
        student.push_back(temp_student);

        vector<int> temp_student_like;
        for (int j = 0; j < 4; j++)
        {
            int temp_num;
            cin >> temp_num;
            temp_student_like.push_back(temp_num);
        }
        student_like.push_back(temp_student_like);
    }

    if (N == 3)
    {
        seat[N / 2][N / 2] = student[0];
    }
    else
    {
        seat[1][1] = student[0];
    }

    int satisfy = 0;

    for (int i = 1; i < student.size(); i++)
    {
        vector<vector<pair<int, int>>> info(N, vector<pair<int, int>>(N, {-1, -1})); // {인접한 좋아하는 학생 수, 인접한 빈칸 수}를 저장하는 자리 벡터

        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                if (seat[j][k] == 0)
                {
                    int like_cnt = 0;
                    int empty_cnt = 0;

                    for (int d = 0; d < 4; d++)
                    {
                        int dx = j + dir[d][0];
                        int dy = k + dir[d][1];

                        if (dx >= 0 && dx < N && dy >= 0 && dy < N)
                        {
                            for (int l = 0; l < student_like[i].size(); l++) // 각 자리에 현재 학생이 좋아하는 학생이 인접한 자리의 갯수 세기
                            {
                                if (seat[dx][dy] == student_like[i][l] && is_adj(j, k, dx, dy))
                                {
                                    like_cnt++;
                                }
                            }

                            if (seat[dx][dy] == 0 && is_adj(j, k, dx, dy))      // 각 자리에 인접한 빈 자리의 갯수 세기
                            {
                                empty_cnt++;
                            }
                        }
                    }

                    info[j][k] = {like_cnt, empty_cnt};
                }
            }
        }

        pair<int, int> sit = {-1, -1};      // 학생이 앉을 자리의 좌표

        int max_like = INT_MIN;
        int max_empty = INT_MIN;

        // 인접한 좋아하는 학생이 많은 자리로 우선 앉게 하고(1번 조건), 만약 그 수가 같다면 인접한 빈 자리가 많은 자리로 앉게 한다.(2번 조건)
        // 행렬 값이 작은 자리부터 순차적으로 탐색하므로 자동적으로 3번 조건을 만족한다.
        for (int r = 0; r < info.size(); r++)
        {
            for (int c = 0; c < info[r].size(); c++)
            {
                if (max_like < info[r][c].first)
                {
                    max_like = info[r][c].first;
                    max_empty = info[r][c].second;

                    sit = {r, c};
                }
                else if (max_like == info[r][c].first)
                {
                    if (max_empty < info[r][c].second)
                    {
                        max_like = info[r][c].first;
                        max_empty = info[r][c].second;
                        sit = {r, c};
                    }
                }
            }
        }

        seat[sit.first][sit.second] = student[i];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int index = find(student.begin(), student.end(), seat[i][j]) - student.begin();
            int satisfy_count = 0;

            for (int d = 0; d < 4; d++)
            {
                int dx = i + dir[d][0];
                int dy = j + dir[d][1];

                for (int k = 0; k < student_like[index].size(); k++)
                {
                    if (dx >= 0 && dx < N && dy >= 0 && dy < N)
                    {
                        if (is_adj(i, j, dx, dy) && seat[dx][dy] == student_like[index][k])
                        {
                            satisfy_count++;
                        }
                    }
                }
            }

            if (satisfy_count == 1)
            {
                satisfy += 1;
            }
            else if (satisfy_count == 2)
            {
                satisfy += 10;
            }
            else if (satisfy_count == 3)
            {
                satisfy += 100;
            }
            else if (satisfy_count == 4)
            {
                satisfy += 1000;
            }
        }
    }

    cout << satisfy << "\n";

    return 0;
}