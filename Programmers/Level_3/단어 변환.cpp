#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

queue<pair<string, int>> q;
vector<int> visited;
int answer = 0;

bool isTransform(string a, string b) {
    int diff = 0;
    for(int i=0; i<a.size(); i++) {
        if(a[i] != b[i]) {
            diff++;
        }
    }
    
    if(diff == 1) {
        return true;
    }
    else {
        return false;
    }
}

void BFS(string begin, string target, vector<string>& words) {
    q.push({begin, 0});
    
    while(!q.empty()) {
        string cur = q.front().first;
        int level = q.front().second;
        q.pop();
        
        if(cur == target) {
            answer = level;
            break;
        }
        
        for(int i=0; i<words.size(); i++) {
            if(visited[i] == 0 && isTransform(words[i], cur)) {
                visited[i] = 1;
                q.push({words[i], level + 1});
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    
    if(find(words.begin(), words.end(), target) == words.end()) {
        answer = 0;
    }
    else {
        visited.assign(words.size(), 0);
        BFS(begin, target, words);
    }
    
    
    return answer;
}