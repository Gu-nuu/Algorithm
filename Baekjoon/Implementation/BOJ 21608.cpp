#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool compare(pair<pair<int, int>, pair<int, int>> a, pair<pair<int, int>, pair<int, int>> b)
{
    if (a.first.first == b.first.first)
        return a.first.second > b.first.second;
    else
        return a.first.first > b.first.first;
}

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<vector<int>> seat(N + 1, vector<int>(N + 1, -1));

    for (int i = 1; i < seat.size(); i++)
    {
        for (int j = 1; j < seat[i].size(); j++)
        {
            seat[i][j] = 0;
        }
    }

    vector<int> student;
    vector<vector<int>> student_like(20, vector<int>(20));

    for (int i = 0; i < N * N; i++)
    {
        int std;
        cin >> std;

        student.push_back(std);

        vector<int> temp;

        for (int j = 0; j < 4; j++)
        {
            int like;
            cin >> like;

            temp.push_back(like);
        }

        student_like.push_back(temp);
    }

    if (N == 3)
    {
        seat[N / 2 + 1][N / 2 + 1] = student[0];
    }
    else
    {
        seat[2][2] = student[0];
    }

    for (int i = 1; i < student.size(); i++)
    {
        vector<pair<int, int>> find_likes;

        for (int j = 0; j < student_like[i].size(); j++)
        {
            for (int k = 1; k < seat.size(); k++)
            {
                for (int l = 1; l < seat[k].size(); l++)
                {
                    if (student_like[i][j] == seat[k][l])
                    {
                        find_likes.push_back({k, l});
                    }
                }
            }
        }

        vector<pair<int, int>> coordinate_adj;

        if (!find_likes.empty())
        {
            for (int j = 0; j < find_likes.size(); j++)
            {
                for (int k = 1; k < seat.size(); k++)
                {
                    for (int l = 1; l < seat[k].size(); l++)
                    {
                        if (abs(find_likes[j].first - k) + abs(find_likes[j].second - l) == 1 && seat[k][l] == 0)
                        {
                            coordinate_adj.push_back({k, l});
                        }
                    }
                }
            }
        }
        else
        {
            for (int j = 1; j < seat.size(); j++)
            {
                for (int k = 1; k < seat[j].size(); k++)
                {
                    if (seat[j][k] == 0)
                    {
                        coordinate_adj.push_back({j, k});
                    }
                }
            }
        }

        vector<pair<pair<int, int>, pair<int, int>>> adj_decision;

        for (int j = 0; j < coordinate_adj.size(); j++)
        {
            int counter_adj_0 = 0;
            int counter_adj_like = 0;

            for (int k = 1; k < seat.size(); k++)
            {
                for (int l = 1; l < seat[k].size(); l++)
                {
                    if (seat[k][l] == 0 && abs(coordinate_adj[j].first - k) + abs(coordinate_adj[j].second - l) == 1)
                    {
                        counter_adj_0++;
                    }

                    for (int m = 0; m < find_likes.size(); m++)
                    {
                        if (k == find_likes[m].first && l == find_likes[m].second && abs(coordinate_adj[j].first - k) + abs(coordinate_adj[j].second - l) == 1)
                        {
                            counter_adj_like++;
                        }
                    }
                }
            }

            adj_decision.push_back({{counter_adj_like, counter_adj_0}, {coordinate_adj[j].first, coordinate_adj[j].second}});
        }

        sort(adj_decision.begin(), adj_decision.end(), compare);

        seat[adj_decision[0].second.first][adj_decision[0].second.second] = student[i];
    }

    int satisfying = 0;

    for (int i = 1; i < seat.size(); i++)
    {
        for (int j = 1; j < seat[i].size(); j++)
        {
            int student_index = find(student.begin(), student.end(), seat[i][j]) - student.begin();
            int satisfy_person = 0;

            for (int k = 1; k < seat.size(); k++)
            {
                for (int l = 1; l < seat[k].size(); l++)
                {
                    if (abs(i - k) + abs(j - l) == 1)
                    {
                        for (int m = 0; m < student_like[student_index].size(); m++)
                        {
                            if (seat[k][l] == student_like[student_index][m])
                            {
                                satisfy_person++;
                            }
                        }
                    }
                }
            }

            if (satisfy_person == 1)
            {
                satisfying += 1;
            }
            else if (satisfy_person == 2)
            {
                satisfying += 10;
            }
            else if (satisfy_person == 3)
            {
                satisfying += 100;
            }
            else if (satisfy_person == 4)
            {
                satisfying += 1000;
            }
        }
    }

    cout << satisfying << "\n";

    return 0;
}