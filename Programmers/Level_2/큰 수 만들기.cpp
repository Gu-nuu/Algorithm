#include <iostream>
#include <vector>

using namespace std;

string solution(string number, int k)
{
	string answer = "";

	int cursor = -1;

	for (int i = 0; i < number.size() - k; i++) // 만들어야 하는 큰 수의 길이만큼 반복문을 사용
	{
		char max = ' ';

		for (int j = cursor + 1; j <= i + k; j++) // cursor의 다음 값부터 탐색하면서 가장 큰 수를 찾고 이를 answer에 저장하며, cursor는 해당 반복문에서 찾은 가장 큰 수의 index로 변경
		{
			if (max < number[j])
			{
				max = number[j];
				cursor = j;
			}
		}

		answer += max;
	}

	return answer;
}

int main()
{
	string number = "4177252841";
	int k = 4;

	cout << solution(number, k) << endl;

	return 0;
}