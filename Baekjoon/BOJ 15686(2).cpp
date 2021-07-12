#include <iostream>
#include <stdio.h>
#include <vector>
#define MAX 987654321
using namespace std;

//치킨 거리 = 한 집에 대해 가장 가까운 치킨집과의 거리
//도시의 치킨 거리 = 치킨 거리 값들을 모두 합친 거리

int N, M;
int** map;      //도시를 입력받을 이중 포인터
vector<pair<int, int>> house;       //집의 위치 좌표를 저장할 벡터(위치 좌표를 저장해야 하므로 pair 사용)
vector<pair<int, int>> chicken;     //치킨 집의 위치 좌표를 저장할 벡터(위치 좌표를 저장해야 하므로 pair 사용)
vector<bool> isVisited(13);     //여러 개의 치킨 집 중 M개를 골라 확인할 벡터(true일 경우 내가 고르고자 하는 치킨집, false라면 내가 고르지 않을 치킨집)
int ans;        //도시의 치킨 거리의 합을 저장할 변수

int calDist(int r1, int c1, int r2, int c2)     //거리를 계산하는 수식을 함수화 하였다.
{
    return (abs(r1 - r2) + abs(c1 - c2));
}

void solve(int index, int count)        //브루트포스 알고리즘을 사용하기 때문에 index 값을 파라미터로 설정한다.
{
    if (count == M)     //M개에 해당하는 치킨집을 고른 경우
    {
        int closeDist = 0;      //도시의 치킨 거리를 저장할 변수
        for (int i = 0; i < house.size(); i++)
        {
            int dist = MAX;     //치킨 거리는 한 집에서 가장 가까운 치킨집과의 거리이므로 처음엔 가장 큰 값으로 설정 후 가장 작은 치킨 거리를 구한다.
            for (int j = 0; j < chicken.size(); j++)
            {
                if (isVisited[j] == true)       //여러 개의 치킨집 중 true 값인것만, 즉 내가 고르고자 하는 치킨집과의 거리만 계산한다.
                    dist = min(dist, calDist(house[i].first, house[i].second, chicken[j].first, chicken[j].second));
                //이때 치킨 거리는 한 집에서 가장 가까운 치킨집이므로 고른 치킨집(M)이 1개보다 많다면 그 중 가장 작은 값을 치킨거리로 설정한다.
            }
            closeDist += dist;
        }
        ans = min(ans, closeDist);      //임의로 고른 치킨집에 대해 도시의 치킨 거리를 구했다면 이전에 작업했던 도시의 치킨 거리와 비교하여 더 작은 값을 출력한다.
    }

    //치킨집을 고를 경우와 안 고를 경우를 두 개의 재귀함수 호출로 나눈 부분과 다르게 for문과 한번의 재귀 호출을 이용한 코드이다.
    //이때 index 값의 범위를 chicken 벡터의 사이즈로 두어 index값이 증가해도 치킨집의 갯수를 넘어서서 탐색하는 경우를 방지한다.
    for (int i = index; i < chicken.size(); i++)
    {
        isVisited[i] = true;
        solve(i + 1, count + 1);
        isVisited[i] = false;
    }

}

int main()
{
    ios::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    ans = MAX;      //가장 작은 값을 알아내야 하므로 초기 값을 매우 큰 값으로 설정하여 비교한다.

    cin >> N >> M;

    map = new int* [N];
    for (int i = 0; i < N; i++)
        map[i] = new int[N];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];

            if (map[i][j] == 1)     //만약 지도의 값 중 1이라면 집이므로 집 벡터에 해당하는 좌표를 넣어준다.
                house.push_back({ i,j });

            if (map[i][j] == 2)     //만약 지도의 값 중 2라면 치킨집이므로 치킨집 벡터에 해당하는 좌표를 넣어준다.
                chicken.push_back({ i,j });

        }
    }

    solve(0, 0);

    cout << ans << "\n";

    return 0;

}