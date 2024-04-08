#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<deque<int>> gear;

    for (int i = 0; i < 4; i++)
    {
        deque<int> temp;
        string input;
        cin >> input;

        for (int j = 0; j < input.size(); j++)
        {
            temp.push_back(input[j] - '0');
        }

        gear.push_back(temp);
    }

    int K;

    cin >> K;

    for (int i = 0; i < K; i++)
    {
        int rotateGearNum, direction;

        cin >> rotateGearNum >> direction;

        bool isRotate[4] = {false, false, false, false};
        int rotateDir[4] = {0, 0, 0, 0};

        if (rotateGearNum == 1)
        {
            isRotate[0] = true; // 1번 기어 돌림

            if (direction == 1)
            {
                rotateDir[0] = 1;
            }
            else
            {
                rotateDir[0] = -1;
            }

            if (gear[0][2] != gear[1][6]) // 1번 기어와 2번 기어 비교
            {
                isRotate[1] = true;

                if (rotateDir[0] == 1)
                {
                    rotateDir[1] = -1;
                }
                else
                {
                    rotateDir[1] = 1;
                }
            }

            if (gear[1][2] != gear[2][6] && isRotate[1] == true) // 2번 기어와 3번 기어 비교
            {
                isRotate[2] = true;

                if (rotateDir[1] == 1)
                {
                    rotateDir[2] = -1;
                }
                else
                {
                    rotateDir[2] = 1;
                }
            }

            if (gear[2][2] != gear[3][6] && isRotate[2] == true) // 3번 기어와 4번 기어 비교
            {
                isRotate[3] = true;

                if (rotateDir[2] == 1)
                {
                    rotateDir[3] = -1;
                }
                else
                {
                    rotateDir[3] = 1;
                }
            }
        }
        else if (rotateGearNum == 2)
        {
            isRotate[1] = true; // 2번 기어 돌림

            if (direction == 1)
            {
                rotateDir[1] = 1;
            }
            else
            {
                rotateDir[1] = -1;
            }

            if (gear[1][6] != gear[0][2]) // 1번 기어와 2번 기어 비교
            {
                isRotate[0] = true;

                if (rotateDir[1] == 1)
                {
                    rotateDir[0] = -1;
                }
                else
                {
                    rotateDir[0] = 1;
                }
            }

            if (gear[1][2] != gear[2][6]) // 2번 기어와 3번 기어 비교
            {
                isRotate[2] = true;

                if (rotateDir[1] == 1)
                {
                    rotateDir[2] = -1;
                }
                else
                {
                    rotateDir[2] = 1;
                }
            }

            if (gear[2][2] != gear[3][6] && isRotate[2] == true) // 3번 기어와 4번 기어 비교
            {
                isRotate[3] = true;

                if (rotateDir[2] == 1)
                {
                    rotateDir[3] = -1;
                }
                else
                {
                    rotateDir[3] = 1;
                }
            }
        }
        else if (rotateGearNum == 3)
        {
            isRotate[2] = true; // 3번 기어 돌림

            if (direction == 1)
            {
                rotateDir[2] = 1;
            }
            else
            {
                rotateDir[2] = -1;
            }

            if (gear[2][2] != gear[3][6]) // 3번 기어와 4번 기어 비교
            {
                isRotate[3] = true;

                if (rotateDir[2] == 1)
                {
                    rotateDir[3] = -1;
                }
                else
                {
                    rotateDir[3] = 1;
                }
            }

            if (gear[1][2] != gear[2][6]) // 2번 기어와 3번 기어 비교
            {
                isRotate[1] = true;

                if (rotateDir[2] == 1)
                {
                    rotateDir[1] = -1;
                }
                else
                {
                    rotateDir[1] = 1;
                }
            }

            if (gear[0][2] != gear[1][6] && isRotate[1] == true) // 1번 기어와 2번 기어 비교
            {
                isRotate[0] = true;

                if (rotateDir[1] == 1)
                {
                    rotateDir[0] = -1;
                }
                else
                {
                    rotateDir[0] = 1;
                }
            }
        }
        else if (rotateGearNum == 4)
        {
            isRotate[3] = true; // 4번 기어 돌림

            if (direction == 1)
            {
                rotateDir[3] = 1;
            }
            else
            {
                rotateDir[3] = -1;
            }

            if (gear[2][2] != gear[3][6]) // 3번 기어와 4번 기어 비교
            {
                isRotate[2] = true;

                if (rotateDir[3] == 1)
                {
                    rotateDir[2] = -1;
                }
                else
                {
                    rotateDir[2] = 1;
                }
            }

            if (gear[1][2] != gear[2][6] && isRotate[2] == true) // 2번 기어와 3번 기어 비교
            {
                isRotate[1] = true;

                if (rotateDir[2] == 1)
                {
                    rotateDir[1] = -1;
                }
                else
                {
                    rotateDir[1] = 1;
                }
            }

            if (gear[0][2] != gear[1][6] && isRotate[1] == true) // 1번 기어와 2번 기어 비교
            {
                isRotate[0] = true;

                if (rotateDir[1] == 1)
                {
                    rotateDir[0] = -1;
                }
                else
                {
                    rotateDir[0] = 1;
                }
            }
        }

        for (int j = 0; j < 4; j++)
        {
            if (isRotate[j])
            {
                if (rotateDir[j] == 1)
                {
                    gear[j].push_front(gear[j].back());
                    gear[j].pop_back();
                }
                else if (rotateDir[j] == -1)
                {
                    gear[j].push_back(gear[j].front());
                    gear[j].pop_front();
                }
            }
        }
    }

    int sum = 0;

    for (int i = 0; i < gear.size(); i++)
    {
        if (gear[i].front() == 1)
        {
            sum += pow(2, i);
        }
    }

    cout << sum << "\n";

    return 0;
}