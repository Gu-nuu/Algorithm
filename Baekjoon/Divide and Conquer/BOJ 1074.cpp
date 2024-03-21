#include <iostream>
#include <cmath>
using namespace std;

int N, r, c;
int ans = 0;

void Z(int size, int y, int x)
{
    if (r == y && c == x)
    {
        cout << ans << "\n";
        return;
    }

    if (y <= r && r < y + size && x <= c && c < x + size)
    {
        Z(size / 2, y, x);
        Z(size / 2, y, x + size / 2);
        Z(size / 2, y + size / 2, x);
        Z(size / 2, y + size / 2, x + size / 2);
    }
    else
    {
        ans += pow(size, 2);
    }
}

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> r >> c;

    Z(pow(2, N), 0, 0);

    return 0;
}