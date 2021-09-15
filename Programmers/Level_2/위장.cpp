#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int solution(vector<vector<string>> clothes)
{
    int answer = 1;

    map<string, int> closet; // STL map을 사용하여 해시를 구현하였다.

    for (int i = 0; i < clothes.size(); i++) // 의상의 종류를 key 값으로 하여 의상의 종류의 갯수를 카운트하여 저장한다.
    {
        closet[clothes[i][1]]++;
    }

    // 의상의 종류의 갯수를 모두 곱해주면 모든 종류의 조합이 나오지만 이때 해당 의상 종류를 아예 안 입는 경우도 있으므로 +1을 하여 곱해준다.
    // ex) 안경 2개, 상의 2벌, 하의 2벌 => (2 + 1) * (2 + 1) * (2 + 1) => 이때 + 1은 안 입는 경우를 포함한 경우
    for (map<string, int>::iterator it = closet.begin(); it != closet.end(); it++)
    {
        answer *= (it->second + 1);
    }

    return answer - 1; // 스파이는 하루에 최소 한 개의 의상은 입는다. 즉 아예 안 입는 경우는 빼줘야 한다.
}

int main()
{
    vector<vector<string>> clothes = {{"yellowhat", "headgear"}, {"bluesunglasses", "eyewear"}, {"green_turban", "headgear"}};

    cout << solution(clothes) << endl;

    return 0;
}