#include <iostream>
#include <stdio.h>
#define MAX 1000001
using namespace std;

int arr[MAX] = { 0, };      //소수가 아닌 수는 1, 소수는 0으로 표시할 에라토스테네스의 체

int main()
{
    ios::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //이 부분에서 시간 초과 오류가 났다. 에라토스테네스의 체의 원리를 이용하여 소수를 판별하는 방법에는 문제가 없었으나 처음에는 반복문 내에서 테스트 케이스로 들어오는
    //숫자들마다 계속 소수 판별을 해주었는데 그럴 필요 없이 주어진 범위의 모든 숫자들에 대해서 한번만 소수 판별을 해주면 된다.
    arr[1] = 1;
    for (int i = 2; i <= MAX; i++)     //에라토스테네스의 체의 원리를 이용하여 테스트 케이스 값 이하의 숫자들에 대해 소수를 판별한다.
    {
        if (arr[i] == 1)
            continue;

        for (int j = 2; i * j <= MAX; j++)
            arr[i * j] = 1;
    }

    int test_case;

    while (true)
    {
        cin >> test_case;

        if (test_case == 0)        //0이면 프로그램을 종료한다.
            break;

        int index = 3;      //홀수인 소수의 합으로 이루어져야 하므로 2를 제외한 3부터 판별한다.

        //test_case에서 index 값을 뺀 수가 홀수 소수인지를 판단하는 방법이다. 예를 들어 8이라는 test_case가 주어졌다면 3부터 index값이 대입이 된다. 이때 test_case인 8에서
        //index 값인 3을 뺀 숫자가 홀수 소수라면 이는 골드 바흐의 추측을 만족하는 숫자이다. 8-3을 했을 때 5가 나오고 이는 홀수 소수이므로 8은 골드 바흐의 추측을 만족하는 숫자가 된다.
        while (true)
        {
            if (test_case - index < 0)      //index 값을 증가시키며 값을 대입해보다가 주어진 test_case 값보다 index 값이 커져버리면 이는 골드 바흐의 추측을 만족하지 않는 숫자이다.
            {
                cout << "Goldbach's conjecture is wrong.\n";
                break;
            }

            if (arr[index] == 0 && arr[test_case - index] == 0)
            {
                cout << test_case << " = " << index << " + " << test_case - index << "\n";
                break;
            }
            
            index++;        //index 값을 증가시키면서 홀수 소수의 합으로 이루어질 수 있는지를 판별한다.

        }

    }

    return 0;
}