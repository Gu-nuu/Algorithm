#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> office;
vector<pair<int, int>> cctvs; // CCTV 위치와 타입 저장
vector<int> directions;       // 각 CCTV의 방향 저장
int answer = 1e9;

int dx[4] = {-1, 0, 1, 0}; // 상, 우, 하, 좌
int dy[4] = {0, 1, 0, -1};

void watch(int x, int y, int dir, vector<vector<int>> &map)
{
    int nx = x, ny = y;
    while (true)
    {
        nx += dx[dir];
        ny += dy[dir];
        if (nx < 0 || ny < 0 || nx >= N || ny >= M || map[nx][ny] == 6)
            break;
        if (map[nx][ny] != 0)
            continue;     // 다른 CCTV 무시
        map[nx][ny] = -1; // 감시 표시
    }
}

int simulate(vector<vector<int>> &map)
{
    for (int i = 0; i < cctvs.size(); i++)
    {
        int x = cctvs[i].first;
        int y = cctvs[i].second;
        int type = office[x][y];
        int dir = directions[i];

        switch (type)
        {
        case 1: // 1번 CCTV
            watch(x, y, dir, map);
            break;
        case 2: // 2번 CCTV
            watch(x, y, dir, map);
            watch(x, y, (dir + 2) % 4, map);
            break;
        case 3: // 3번 CCTV
            watch(x, y, dir, map);
            watch(x, y, (dir + 1) % 4, map);
            break;
        case 4: // 4번 CCTV
            watch(x, y, dir, map);
            watch(x, y, (dir + 1) % 4, map);
            watch(x, y, (dir + 2) % 4, map);
            break;
        case 5: // 5번 CCTV
            watch(x, y, dir, map);
            watch(x, y, (dir + 1) % 4, map);
            watch(x, y, (dir + 2) % 4, map);
            watch(x, y, (dir + 3) % 4, map);
            break;
        }
    }

    // 사각 지대 계산
    int count = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (map[i][j] == 0)
                count++;
    return count;
}

void dfs(int idx)
{
    if (idx == cctvs.size())
    {
        vector<vector<int>> tempMap = office;
        answer = min(answer, simulate(tempMap));
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        directions[idx] = i;
        dfs(idx + 1);
    }
}

int main()
{
    cin >> N >> M;
    office.assign(N, vector<int>(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            cin >> office[i][j];
            if (1 <= office[i][j] && office[i][j] <= 5)
                cctvs.push_back({i, j});
        }

    directions.resize(cctvs.size());
    dfs(0);

    cout << answer << endl;
    return 0;
}