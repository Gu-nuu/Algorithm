#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    
    vector<int> v;
    
    for(int i=0; i<dungeons.size(); i++)
    {
        v.push_back(i);
    }
    
    do
    {
        int count = 0;
        int temp_k = k;
        
        for(int i=0; i<v.size(); i++)
        {
            if(temp_k >= dungeons[v[i]][0])
            {
                count++;
                temp_k -= dungeons[v[i]][1];
            }
            
        }

        if(answer < count)
            answer = count;

        
    } while(next_permutation(v.begin(), v.end()));
    
    return answer;
}