#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int money;
    cin >> money;

    vector<int> price;

    for (int i = 0; i < 14; i++)
    {
        int num;
        cin >> num;

        price.push_back(num);
    }

    //////////////////////////////////////////////////////////////////////

    int BNF_total = 0;
    int BNF_money = money;
    int BNF_stock = 0;

    for (int i = 0; i < price.size(); i++)
    {
        if (BNF_money >= price[i])
        {
            BNF_stock += (BNF_money / price[i]);
            BNF_money -= (price[i] * (BNF_money / price[i]));
        }
    }

    BNF_total = BNF_money + (price[price.size() - 1] * BNF_stock);

    //////////////////////////////////////////////////////////////////////

    int TIMING_total = 0;
    int TIMING_money = money;
    int TIMING_stock = 0;
    int increase = 0;
    int decrease = 0;

    for (int i = 1; i < price.size(); i++)
    {
        if (price[i - 1] < price[i])
        {
            increase++;
            decrease = 0;
        }
        else if (price[i - 1] > price[i])
        {
            increase = 0;
            decrease++;
        }

        if (increase == 3)
        {
            increase--;
            TIMING_money += (price[i] * TIMING_stock);
            TIMING_stock = 0;
        }
        else if (decrease == 3 && TIMING_money >= price[i])
        {
            decrease--;
            TIMING_stock += (TIMING_money / price[i]);
            TIMING_money -= (price[i] * (TIMING_money / price[i]));
        }
    }

    TIMING_total = TIMING_money + (price[price.size() - 1] * TIMING_stock);

    //////////////////////////////////////////////////////////////////////

    if (BNF_total > TIMING_total)
        cout << "BNP\n";
    else if (BNF_total < TIMING_total)
        cout << "TIMING\n";
    else
        cout << "SAMESAME\n";

    return 0;
}