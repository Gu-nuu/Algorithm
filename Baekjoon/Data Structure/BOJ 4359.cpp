#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    map<string, double> m; // 나무의 종과 해당 종의 갯수를 저장하기 위해 map을 사용했다.

    int cnt = 0; // 전체 나무의 수를 저장할 변수

    // 입력의 갯수가 정해져있지 않기 때문에 입력의 끝을 알 수 없다. 따라서 getline으로 문자를 입력받고 엔터키를 한번 더 눌렀을 때 아무것도 없으면 반복문을 종료하도록 했다.
    while (1)
    {
        string tree;
        getline(cin, tree);

        if (tree == "")
            break;

        cnt++;

        if (m.find(tree) != m.end()) // 만약 map에 이미 저장되어있는 종이라면 갯수를 증가시켜준다.
        {
            m.find(tree)->second++;
        }
        else
        {
            m.insert({tree, 1}); // map에 저장되어 있지 않은 새로운 종이라면 갯수를 1로 설정하고 새로 추가해준다.
        }
    }

    // 공부를 하면서 알게 되었는데 백준은 테스트 케이스의 입력을 파일로 넣기 때문에 EOF(End Of File)를 이용하여 반복문을 탈출하도록 할 수 있다.
    // while (getline(cin, tree)) {} 로 작성하게 되면 자동으로 while 문의 조건에서 EOF를 판별하여 반복문을 종료시킨다.
    // int cnt = 0;
    // string tree;

    // while (getline(cin, tree))
    // {
    //     cnt++;

    //     if (m.find(tree) != m.end())
    //     {
    //         m.find(tree)->second++;
    //     }
    //     else
    //     {
    //         m.insert({tree, 1});
    //     }
    // }

    cout << fixed;
    cout.precision(4); // 소수점 4째자리까지 반올림해야 한다.

    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << it->first << " " << (it->second / cnt) * 100 << "\n"; // map은 default로 key값을 기반으로 정렬되어있으므로 종과 해당 종의 비율을 백분율로 출력한다.
    }

    return 0;
}