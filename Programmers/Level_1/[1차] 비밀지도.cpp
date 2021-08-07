#include <iostream>
#include <string>
#include <vector>

using namespace std;

string calculator(int num, int n) // 10진수를 2진수로 변환하여 지도를 부호화하는 함수
{
    string line = "";

    while (true) // 10진수를 2진수로 변환
    {
        line = to_string(num % 2) + line;

        if (num / 2 == 0)
            break;
        else
            num /= 2;
    }

    // 변환된 2진수는 지도의 가로 세로 크기에 맞게 나와야 하므로 남은 부분은 0으로 채워준다.
    // ex) n=5, 9 => 1001 => 01001
    if (line.size() != n)
    {
        int temp = line.size();
        for (int i = 0; i < n - temp; i++)
            line = "0" + line;
    }

    return line;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2)
{
    vector<string> answer;

    for (int i = 0; i < n; i++)
    {
        string line1 = calculator(arr1[i], n);
        string line2 = calculator(arr2[i], n);

        string map = "";
        for (int j = 0; j < n; j++)
        {
            if (line1[j] == '1' || line2[j] == '1') // 두 개의 지도를 비교했을 때 한 지도에서라도 벽이 나타나면 그 부분은 벽
                map += "#";
            else if (line1[j] == '0' && line2[j] == '0') // 두 개의 지도를 비교했을 때 둘 다 벽이 없다면 해당 부분은 공백
                map += " ";
        }
        answer.push_back(map);
    }

    return answer;
}

int main()
{
    int n = 5;
    vector<int> arr1 = {9, 20, 28, 18, 11};
    vector<int> arr2 = {30, 1, 21, 17, 28};

    vector<string> ans = solution(n, arr1, arr2);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;

    return 0;
}