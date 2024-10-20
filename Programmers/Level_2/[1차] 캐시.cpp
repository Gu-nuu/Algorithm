#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities)
{
    int answer = 0;

    if (cacheSize == 0)
    {
        answer += (cities.size() * 5);
    }
    else
    {
        deque<string> cache;

        for (int i = 0; i < cities.size(); i++)
        {
            transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::toupper);

            auto check = find(cache.begin(), cache.end(), cities[i]);

            if (check != cache.end())
            {
                answer += 1;

                cache.erase(check);
                cache.push_back(cities[i]);
            }
            else
            {
                answer += 5;

                if (cache.size() < cacheSize)
                {
                    cache.push_back(cities[i]);
                }
                else
                {
                    cache.pop_front();
                    cache.push_back(cities[i]);
                }
            }
        }
    }

    return answer;
}