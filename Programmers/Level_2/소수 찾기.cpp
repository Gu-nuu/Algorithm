#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isPrime(int num) // 입력받은 정수가 소수인지 아닌지를 판별하는 함수
{
    bool check = true;

    if (num < 2)
        check = false;
    else
    {
        for (int i = 2; i < num; i++)
        {
            if (num % i == 0)
            {
                check = false;
                break;
            }
        }
    }

    return check;
}

int solution(string numbers)
{
    int answer = 0;

    vector<char> number;

    vector<int> box;

    for (int i = 0; i < numbers.size(); i++)
        number.push_back(numbers[i]);

    sort(number.begin(), number.end()); // next_permutation 함수를 사용하기 위해 각 숫자를 분리해 벡터에 저장한 뒤 정렬

    do
    {
        string temp = "";
        for (int i = 0; i < number.size(); i++) // 한 자릿수부터 모든 경우의 수를 구해야 하므로 문자를 하나씩 늘려가면서 저장 후 정수로 변환하여 벡터에 저장한다.
        {
            temp += number[i];
            box.push_back(stoi(temp));
        }
    } while (next_permutation(number.begin(), number.end())); // bool 타입의 함수로써 do-while문을 이용해 만들어질 수 있는 모든 순열의 경우를 찾아준다.

    // stoi 함수를 통해 정수로 변환되면서 앞자리가 0인 경우는 해당 자리가 사라지면서 저장되기 떄문에 중복이 발생하게 되므로 erase와 unique를 사용하여
    // 중복 제거를 해준다. ex) 11과 011은 int형 벡터 안에서 똑같이 11로 저장되므로 중복을 제거해줘야 한다.
    sort(box.begin(), box.end());
    box.erase(unique(box.begin(), box.end()), box.end());

    for (int i = 0; i < box.size(); i++)
    {
        if (isPrime(box[i]))
            answer++;
    }

    return answer;
}

int main()
{
    string numbers = "011";

    cout << solution(numbers) << endl;

    return 0;
}