#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
	vector<int> answer;

	vector<int> days;

	for (int i = 0; i < progresses.size(); i++)
	{
		int left = 100 - progresses[i];

		if (left % speeds[i] != 0 && left % speeds[i] < speeds[i])
			days.push_back((left / speeds[i]) + 1);
		else
			days.push_back(left / speeds[i]);
	}

	int j;

	for (int i = 0; i < days.size(); i++)
	{
		int cnt = 1;

		for (j = i + 1; j < days.size(); j++)
		{
			if (days[i] < days[j])
			{
				i = j - 1;
				break;
			}
			else
				cnt++;
		}

		answer.push_back(cnt);

		if (j == days.size())
			break;
	}

	return answer;
}

int main()
{
	vector<int> progresses = { 95, 90, 99, 99, 80, 99 };
	vector<int> speeds = { 1, 1, 1, 1, 1, 1 };

	vector<int> ans = solution(progresses, speeds);

	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	cout << endl;

	return 0;
}