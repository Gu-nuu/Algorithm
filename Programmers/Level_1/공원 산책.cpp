#include <string>
#include <vector>

using namespace std;

int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // 동서남북

vector<int> solution(vector<string> park, vector<string> routes)
{
    vector<int> answer;

    pair<int, int> cur_pos = {-1, -1};

    int row = park.size();
    int col = park[0].size();

    bool flag = false;

    for (int i = 0; i < park.size(); i++)
    {
        for (int j = 0; j < park[i].size(); j++)
        {
            if (park[i][j] == 'S')
            {
                cur_pos = {i, j};
                flag = true;
                break;
            }
        }

        if (flag)
        {
            break;
        }
    }

    for (int i = 0; i < routes.size(); i++)
    {
        int dir_idx = -1;
        int move_size = routes[i][2] - '0';

        if (routes[i][0] == 'E')
        {
            dir_idx = 0;
        }
        else if (routes[i][0] == 'W')
        {
            dir_idx = 1;
        }
        else if (routes[i][0] == 'S')
        {
            dir_idx = 2;
        }
        else if (routes[i][0] == 'N')
        {
            dir_idx = 3;
        }

        bool check = true;

        for (int j = 1; j <= move_size; j++)
        {
            int next_row = cur_pos.first + dir[dir_idx][0] * j;
            int next_col = cur_pos.second + dir[dir_idx][1] * j;

            if (next_row >= row || next_col >= col || next_row < 0 || next_col < 0 || park[next_row][next_col] == 'X')
            {
                check = false;
                break;
            }
        }

        if (check)
        {
            cur_pos = {cur_pos.first + dir[dir_idx][0] * move_size, cur_pos.second + dir[dir_idx][1] * move_size};
        }
    }

    answer.push_back(cur_pos.first);
    answer.push_back(cur_pos.second);

    return answer;
}