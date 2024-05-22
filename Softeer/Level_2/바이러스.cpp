#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char **argv)
{
    long long K, P, N;

    cin >> K >> P >> N;

    long long mod_num = 1000000007;

    while (N > 0)
    {

        K *= P;
        K %= mod_num;
        N--;
    }

    cout << K << "\n";

    return 0;
}