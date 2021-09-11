#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

// 트럭이 건널 다리를 큐로 구현하였으며, 트럭이 움직이게 되는 거리를 0을 push함으로써 나타냈다.
int solution(int bridge_length, int weight, vector<int> truck_weights)
{
	int answer = 0;

	queue<int> bridge; // 다리를 큐로 구현

	int sumOfWeight = 0; // 다리 위에 올라가있는 트럭의 무게를 확인
	int index = 0;		 // 트럭 별 무게인 truck_weights를 순환하기 위한 cursor

	while (true)
	{
		answer++;

		if (bridge.size() == bridge_length) // 만약 bridge의 크기가 다리 길이가 된다면 트럭은 빠져나가야 함
		{
			sumOfWeight -= bridge.front();
			bridge.pop();
		}

		int onGoing = truck_weights[index];

		if (sumOfWeight + onGoing <= weight) // 트럭이 다리를 건널 수 있다면 트럭을 bridge에 push
		{
			bridge.push(onGoing);
			sumOfWeight += onGoing;

			if (index == truck_weights.size() - 1) // 만약 다리를 건너게 되는 트럭이 맨 마지막 트럭이라면 그 트럭이 건너는 길이만큼의 시간을 더해준 후 반복문 break
			{
				answer += bridge_length;
				break;
			}

			index++;
		}
		else // 만약 트럭이 추가적으로 건너갈 수 없다면 트럭 대신 빈 공간을 의미하는 0을 push한다. 나중에 pop되더라도 sumOfWeight에는 변화가 없다.
			bridge.push(0);
	}

	return answer;
}

int main()
{
	int bridge_length = 2;
	int weight = 10;
	vector<int> truck_weights = {7, 4, 5, 6};

	cout << solution(bridge_length, weight, truck_weights) << endl;

	return 0;
}