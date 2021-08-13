#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 행렬의 곱셈은 arr1의 행과 arr2의 열을 각각 곱해서 더해지는 값으로 계산이 이루어지게 됨
vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
    vector<vector<int>> answer;

    int arr2_col = arr2[0].size(); // arr2에 대해서 열에 대한 계산이 필요하므로 arr2 행렬의 열의 크기를 구함

    for (int i = 0; i < arr1.size(); i++)
    {
        vector<int> temp; // 곱셈이 끝난 후 한 행에 대한 계산 결과를 담을 벡터
        for (int j = 0; j < arr2_col; j++)
        {
            int sum = 0;
            for (int k = 0; k < arr1[i].size(); k++)   // arr1에서는 행의 숫자들을, arr2에서는 열의 숫자들을 뽑아 곱한 후 더하는 방식으로 이루어짐
                sum = sum + (arr1[i][k] * arr2[k][j]); // i는 arr1의 행, j는 arr2의 열, k는 arr1의 i행의 열이자 arr2의 j열의 행
            temp.push_back(sum);
        }
        answer.push_back(temp);
    }

    return answer;
}

int main()
{
    vector<vector<int>> arr1 = {{1, 4}, {3, 2}, {4, 1}};
    vector<vector<int>> arr2 = {{3, 3}, {3, 3}};

    vector<vector<int>> ans = solution(arr1, arr2);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }

    return 0;
}