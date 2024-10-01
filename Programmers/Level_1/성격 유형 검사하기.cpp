#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

string solution(vector<string> survey, vector<int> choices)
{
    string answer = "";

    unordered_map<char, int> score;

    score.insert({'R', 0});
    score.insert({'T', 0});
    score.insert({'C', 0});
    score.insert({'F', 0});
    score.insert({'J', 0});
    score.insert({'M', 0});
    score.insert({'A', 0});
    score.insert({'N', 0});

    int size = survey.size();

    for (int i = 0; i < size; i++)
    {
        if (choices[i] == 1)
        {
            score[survey[i][0]] += 3;
        }
        else if (choices[i] == 2)
        {
            score[survey[i][0]] += 2;
        }
        else if (choices[i] == 3)
        {
            score[survey[i][0]] += 1;
        }
        else if (choices[i] == 5)
        {
            score[survey[i][1]] += 1;
        }
        else if (choices[i] == 6)
        {
            score[survey[i][1]] += 2;
        }
        else if (choices[i] == 7)
        {
            score[survey[i][1]] += 3;
        }
    }

    if (score['R'] >= score['T'])
    {
        answer += "R";
    }
    else
    {
        answer += "T";
    }

    if (score['C'] >= score['F'])
    {
        answer += "C";
    }
    else
    {
        answer += "F";
    }

    if (score['J'] >= score['M'])
    {
        answer += "J";
    }
    else
    {
        answer += "M";
    }

    if (score['A'] >= score['N'])
    {
        answer += "A";
    }
    else
    {
        answer += "N";
    }

    return answer;
}