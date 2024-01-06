#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string minkyeom;
    cin >> minkyeom;

    // 십진수 변환시에 정수로 계산 후 string으로 이어붙이게 될 경우 민겸 수의 길이가 최대 30까지 나올 수 있기 때문에 아무리 큰 자료형을 사용해도
    // 오버플로우에 걸리게 된다. 따라서 십진수로 변환할 때 정수 계산을 하지 않고 문자열로 하나씩 이어 붙여주었다.
    string largest = "";
    string smallest = "";
    string temp = "";

    // 민겸 수의 최댓값은 M을 가능한 많이 이어붙인 뒤 K와 묶어 잘라줄 때 만들 수 있다. 이때 유의해야 할 점은 M으로만 이루어진 민겸 수의 경우
    // M을 하나씩 잘라서 1로 계속 이어주는 것이 숫자를 더 크게 만들 수 있다는 점이다. 예를 들어 MM은 10보다 11로 만드는게 더 큰 숫자를 만들 수 있다.
    for (int i = 0; i < minkyeom.size(); i++)
    {
        temp += minkyeom[i];

        // 민겸 수를 하나씩 탐색하다가 K 또는 맨 마지막 차례의 민겸 수에 도달했을 경우 그동안 묶은 M과 K를 십진수로 변환한다.
        if (minkyeom[i] == 'K' || i == minkyeom.size() - 1)
        {
            int count_M = 0;
            bool count_K = false;

            for (int j = 0; j < temp.size(); j++) // 이어붙인 민겸 수에서 M의 갯수와 K의 유무를 확인한다.
            {
                if (temp[j] == 'M')
                {
                    count_M++;
                }
                else if (temp[j] == 'K')
                {
                    count_K = true;
                }
            }

            if (count_K) // K가 존재할 경우 5 * 10^n 꼴로 십진수를 변환한다.
            {
                largest += "5";

                for (int k = 0; k < count_M; k++)
                {
                    largest += "0";
                }
            }
            else // M으로만 이루어진 민겸 수의 경우 M의 갯수만큼 1을 추가하여 십진수로 변환한다.
            {
                for (int k = 0; k < count_M; k++)
                {
                    largest += "1";
                }
            }

            temp.clear();
        }
    }

    // 민겸 수의 최솟값을 구하기 위해서는 각각의 민겸 수를 무조건 하나씩만 계산해야한다. 이때 유의해야 할 점은 M이 연속해서 등장하는 경우에는
    // 이를 가능한 많이 묶어서 하나의 민겸 수로 처리해야 한다는 점이다. 예를 들어 MM은 10 또는 11로 변환될 수 있으며 MM을 하나의 민겸 수로 봤을 때
    // 10으로 더 작은 숫자를 얻을 수 있다.
    for (int i = 0; i < minkyeom.size(); i++)
    {
        temp += minkyeom[i];

        // 민겸 수가 M으로 이어지는 경우를 제외하고는 무조건 하나로만 계산해 1로 변환한다.
        // 만약 M이 이어지는 경우 가능한 많이 이어붙인 뒤 하나의 민겸 수로 계산할 수 있도록 했다.
        if (minkyeom[i] == 'M' && (minkyeom[i + 1] != 'M' || i == minkyeom.size() - 1))
        {
            smallest += "1";

            for (int j = 0; j < temp.size() - 1; j++)
            {
                smallest += "0";
            }

            temp.clear();
        }
        else if (minkyeom[i] == 'K') // 민겸 수 K의 경우 무조건 하나로만 계산해 5로 변환한다.
        {
            smallest += "5";
            temp.clear();
        }
    }

    cout << largest << "\n"
         << smallest << "\n";

    return 0;
}