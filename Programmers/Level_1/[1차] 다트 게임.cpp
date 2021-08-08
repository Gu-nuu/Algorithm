#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cmath>

using namespace std;

int solution(string dartResult)
{
    int answer = 0;

    int cursor = -1;
    vector<int> score(dartResult.size(), 0); // 들어온 다트 결과의 갯수에 맞게 점수를 저장할 벡터를 생성(점수가 아닌 부분은 0으로 저장됨)
                                             // ex) 1S2D*3T => 1020030
    int x = 1;

    for (int i = 0; i < dartResult.size(); i++)
    {
        if (isdigit(dartResult[i]) != 0)
        {
            cursor = i;

            if (dartResult[i] == '1' && dartResult[i + 1] == '0') // 10점의 경우
            {
                if (cursor != 0) // 10점의 경우 점수를 벡터에 저장할 때 index 값으로 저장하는 경우 다른 숫자보다 문자가 하나 더 많아서 밀림이 발생하므로 밀림이 발생하는 만큼 커서 값을 줄여줘야 함
                    cursor -= (x++);
                score[cursor] = 10;
                score.erase(score.begin() + cursor + 1); // 점수를 저장할 때, 10은 처음에 score 벡터 2개의 공간을 차지하면서 생기므로 점수를 저장 후 바로 뒤에 공간은 제거
                i++;                                     // 10을 확인하고 나면 다음 인덱스는 10 중에서 0을 가리키기 때문에 이를 무시하고 넘어가야 함
            }
            else
                score[cursor] = dartResult[cursor] - '0';
        }
        else if (isalpha(dartResult[i]) != 0) // 각각의 문자에 맞게 점수를 제곱하여 계산
        {
            if (dartResult[i] == 'S')
                score[cursor] = pow(score[cursor], 1);
            else if (dartResult[i] == 'D')
                score[cursor] = pow(score[cursor], 2);
            else if (dartResult[i] == 'T')
                score[cursor] = pow(score[cursor], 3);
        }
        else if (dartResult[i] == '*')
        {
            if (cursor == 0) // *이 처음에만 나타나면 해당 점수만 2배가 됨
                score[cursor] *= 2;
            else
            {
                int temp = cursor - 1;
                while (score[temp] == 0) // *이 중간에 나타나면 바로 앞 점수도 2배가 되어야 하므로 while문을 통해 바로 앞 점수를 찾음. score 벡터에서 점수가 아닌 공간은 0으로 저장되어 있으므로 이를 이용
                    temp--;
                score[cursor] *= 2;
                score[temp] *= 2;
            }
        }
        else if (dartResult[i] == '#') // #은 점수가 -1가 됨
            score[cursor] *= (-1);
    }

    for (int i = 0; i < score.size(); i++)
        answer += score[i];

    return answer;
}

int main()
{
    string result = "10S10S10S";

    cout << solution(result) << endl;

    return 0;
}