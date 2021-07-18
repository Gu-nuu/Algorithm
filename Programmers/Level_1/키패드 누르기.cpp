#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 숫자 키패드를 행렬 배열을 이용하여 좌표처럼 적용해서 문제를 해결하였다
// 1  2  3  => {0,0}  {0,1}  {0,2}
// 4  5  6  => {1,0}  {1,1}  {1,2}
// 7  8  9  => {2,0}  {1,1}  {2,2}
// *  0  #  => {3,0}  {1,1}  {2,3}
string solution(vector<int> numbers, string hand)
{
    string answer = "";

    int left_hand[2] = {3, 0};
    int right_hand[2] = {3, 2}; // 처음 왼손 손가락과 오른손 손가락의 위치는 각각 *과 #에 위치하고 있음

    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) // 왼손 손가락에 해당하는 경우
        {
            left_hand[0] = numbers[i] / 3; // 왼쪽에 있는 키패드의 숫자에 맞게 행 값을 설정
            left_hand[1] = 0;              // 열 값 설정
            answer += "L";
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) // 오른손 손가락에 해당하는 경우
        {
            right_hand[0] = numbers[i] / 4; // 오른쪽에 있는 키패드의 숫자에 맞게 행 값을 설정
            right_hand[1] = 2;              // 열 값 설정
            answer += "R";
        }
        else // 가운데 숫자 키패드의 경우
        {
            int cur_loc[2] = {0, 1}; // 2, 5, 8, 0의 경우에 맞게 눌러야 할 키패드의 행렬 값을 설정
            switch (numbers[i])
            {
            case 2:
                cur_loc[0] = 0;
                break;
            case 5:
                cur_loc[0] = 1;
                break;
            case 8:
                cur_loc[0] = 2;
                break;
            case 0:
                cur_loc[0] = 3;
                break;
            }
            // 눌러야 할 키패드와 현재 왼손 손가락의 위치와 오른손 손가락의 위치와의 거리를 각각 계산
            // 이때, 거리는 X 이동량 + Y 이동량
            int left_dist = abs(cur_loc[1] - left_hand[1]) + abs(cur_loc[0] - left_hand[0]);
            int right_dist = abs(right_hand[1] - cur_loc[1]) + abs(right_hand[0] - cur_loc[0]);

            if (left_dist < right_dist) // 왼손 손가락과의 거리가 더 짧을 경우
            {
                left_hand[0] = cur_loc[0];
                left_hand[1] = cur_loc[1]; // 왼손으로 키패드를 누르도록 설정
                answer += "L";
            }
            else if (left_dist > right_dist) // 오른손 손가락과의 거리가 더 짧을 경우
            {
                right_hand[0] = cur_loc[0];
                right_hand[1] = cur_loc[1]; // 오른손으로 키패드를 누르도록 설정
                answer += "R";
            }
            else // 만약 거리가 같을 경우
            {
                if (hand == "left") // 왼손 잡이의 경우 왼손 손가락으로 누르도록 설정
                {
                    left_hand[0] = cur_loc[0];
                    left_hand[1] = cur_loc[1];
                    answer += "L";
                }
                else // 오른손 잡이의 경우 오른손 손가락으로 누르도록 설정
                {
                    right_hand[0] = cur_loc[0];
                    right_hand[1] = cur_loc[1];
                    answer += "R";
                }
            }
        }
    }

    return answer;
}

int main()
{
    string hand = "right";
    vector<int> numbers = {1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5};

    string ans = solution(numbers, hand);

    cout << ans << endl;

    return 0;
}