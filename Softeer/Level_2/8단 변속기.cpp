#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
    vector<int> nums;
    int N;

    for (int i = 0; i < 8; i++)
    {
        cin >> N;
        nums.push_back(N);
    }

    bool asc = true;
    bool desc = true;

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] - nums[i - 1] == 1 && asc)
        {
            asc = true;
            desc = false;
            continue;
        }
        else if (nums[i] - nums[i - 1] == -1 && desc)
        {
            asc = false;
            desc = true;
            continue;
        }
        else
        {
            asc = false;
            desc = false;
            break;
        }
    }

    if (asc && !desc)
    {
        cout << "ascending" << "\n";
    }
    else if (!asc && desc)
    {
        cout << "descending" << "\n";
    }
    else
    {
        cout << "mixed" << "\n";
    }

    return 0;
}