#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> dictionary;

void repeatedPermutation(vector<char> n, vector<char> r, int depth)
{
    if(r.size() == depth)
    {
        string temp = "";
        
        for(int i=0; i<r.size(); i++)
        {
            temp += r[i];
        }
        
        dictionary.push_back(temp);
        
        return;
    }
    
    for(int i=0; i<n.size(); i++)
    {
        r[depth] = n[i];
        repeatedPermutation(n, r, depth + 1);
    }
    
}

int solution(string word) {
    int answer = 0;
    
    vector<char> n = {'A','E','I','O','U'};
    
    for(int i=0; i<n.size(); i++)
    {
        vector<char> r;
        r.resize(i + 1);
        repeatedPermutation(n, r, 0);
    }
    
    sort(dictionary.begin(), dictionary.end());

    answer = find(dictionary.begin(), dictionary.end(), word) - dictionary.begin() + 1;
    
    return answer;
}