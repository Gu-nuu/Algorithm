#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string sound;
    cin >> sound;

    vector<int> check_word(sound.size(), 0);
    vector<char> check_sound{'q', 'u', 'a', 'c', 'k'};
    vector<int> memory_index;

    int duck = 0;

    for (int i = 0; i < sound.size(); i++)
    {
        int word_count = 0;
        string temp = "";
        bool duck_flag = false;

        for (int j = i; j < sound.size(); j++)
        {
            if (check_word[j] == 0)
            {
                if (check_sound[word_count] == sound[j])
                {
                    word_count++;
                    temp += sound[j];
                    memory_index.push_back(j);
                }
            }

            if (temp == "quack")
            {
                temp = "";
                duck_flag = true;
                word_count = 0;

                for (int k = 0; k < memory_index.size(); k++)
                {
                    check_word[memory_index[k]] = 1;
                }

                memory_index.clear();
            }
        }

        if (duck_flag)
            duck++;
    }

    for (int i = 0; i < check_word.size(); i++)
    {
        if (check_word[i] == 0)
        {
            duck = -1;
            break;
        }
    }
    if (duck == 0 || duck == -1 || sound.size() % 5 != 0)
        cout << "-1\n";
    else
        cout << duck << "\n";

    return 0;
}