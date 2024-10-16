#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, long long left, long long right)
{
    vector<int> answer;

    for (long long i = left; i <= right; i++)
    {
        pair<int, int> coordinate = {i / n, i % n};

        answer.push_back(max(coordinate.first, coordinate.second) + 1);
    }

    //     시간 초과 코드
    //     vector<vector<int>> board;
    //     board.assign(n, vector<int>(n, -1));
    //     vector<set<pair<int, int>>> coordinate;

    //     set<pair<int, int>> prev;
    //     prev.insert({0, 0});

    //     for(int i=0; i<n; i++) {
    //         set<pair<int, int>> temp;

    //         if(coordinate.size() == 0) {
    //             coordinate.push_back(prev);
    //         }
    //         else {
    //             for(auto it=prev.begin(); it!=prev.end(); it++) {
    //                 if(it->first == it->second) {
    //                     temp.insert({it->first + 1, it->second + 1});
    //                     temp.insert({it->first, it->second + 1});
    //                     temp.insert({it->first + 1, it->second});
    //                 }
    //                 else {
    //                     if(it->first < it->second) {
    //                         temp.insert({it->first, it->second + 1});
    //                     }
    //                     else {
    //                         temp.insert({it->first + 1, it->second});
    //                     }
    //                 }
    //             }

    //             coordinate.push_back(temp);
    //             prev = temp;
    //         }

    //     }

    //     for(int i=0; i<coordinate.size(); i++) {
    //         for(auto it=coordinate[i].begin(); it!= coordinate[i].end(); it++) {
    //             board[it->first][it->second] = i + 1;
    //         }
    //     }

    //     vector<int> line;

    //     for(int i=0; i<board.size(); i++) {
    //         for(int j=0; j<board[i].size(); j++) {
    //             line.push_back(board[i][j]);
    //         }
    //     }

    //     for(long long i=left; i<=right; i++) {
    //         answer.push_back(line[i]);
    //     }

    return answer;
}