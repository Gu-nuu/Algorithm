#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    int maxWidth = -1;
    int maxHeight = -1;
    
    for(int i=0; i<sizes.size(); i++)
    {
        if(sizes[i][0] < sizes[i][1])
        {
            int bigLength = sizes[i][0];
            sizes[i][0] = sizes[i][1];
            sizes[i][1] = bigLength;
        }
        
        if(maxWidth < sizes[i][0])
            maxWidth = sizes[i][0];
        
        if(maxHeight < sizes[i][1])
            maxHeight = sizes[i][1];
    }
    
    answer = maxWidth * maxHeight;
    
    return answer;
}