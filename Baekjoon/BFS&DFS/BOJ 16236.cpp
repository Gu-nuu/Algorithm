#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
int baby_shark = 2;
int eat_count = 0;
int eating_time = 0;
bool updated = true;

// 상 좌 하 우
int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

vector<vector<int>> space;
vector<vector<int>> visited;

void clear_visited()
{
    for (int i = 0; i < N; ++i)
    {
        fill(visited[i].begin(), visited[i].end(), -1);
    }
}

pair<int, int> find_prey(int r, int c)
{
    queue<pair<int, int>> q;
    clear_visited();
    q.push({r, c});
    visited[r][c] = 0;

    vector<pair<int, int>> prey;
    while (!q.empty())
    {
        auto [r, c] = q.front();
        q.pop();

        for (int d = 0; d < 4; d++)
        {
            int dr = r + dir[d][0];
            int dc = c + dir[d][1];

            if (dr >= 0 && dr < N && dc >= 0 && dc < N && space[dr][dc] <= baby_shark && visited[dr][dc] == -1)
            {
                visited[dr][dc] = visited[r][c] + 1;
                q.push({dr, dc});

                if (space[dr][dc] < baby_shark && space[dr][dc] > 0)
                {
                    prey.push_back({dr, dc});
                }
            }
        }
    }

    if (prey.empty())
        return {-1, -1};

    sort(prey.begin(), prey.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         {
        if (visited[a.first][a.second] == visited[b.first][b.second]) {
            if (a.first == b.first) return a.second < b.second;
            return a.first < b.first;
        }
        return visited[a.first][a.second] < visited[b.first][b.second]; });

    return prey.front();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    space.resize(N, vector<int>(N));
    visited.resize(N, vector<int>(N, -1));

    pair<int, int> shark_pos;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> space[i][j];
            if (space[i][j] == 9)
            {
                shark_pos = {i, j};
                space[i][j] = 0;
            }
        }
    }

    while (true)
    {
        auto [r, c] = find_prey(shark_pos.first, shark_pos.second);
        if (r == -1 && c == -1)
            break;

        eating_time += visited[r][c];
        eat_count++;
        if (eat_count == baby_shark)
        {
            baby_shark++;
            eat_count = 0;
        }

        space[r][c] = 0;    // 먹이를 먹음
        shark_pos = {r, c}; // 상어의 새로운 위치 업데이트
    }

    cout << eating_time << "\n";
    return 0;
}