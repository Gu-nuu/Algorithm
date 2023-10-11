#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    string subject; // 과목명
    double credit;  // 학점
    string grade;   // 등급

    map<string, double> m; // 등급에 따른 학점을 계산하기 위한 map
    m.insert({"A+", 4.5});
    m.insert({"A0", 4.0});
    m.insert({"B+", 3.5});
    m.insert({"B0", 3.0});
    m.insert({"C+", 2.5});
    m.insert({"C0", 2.0});
    m.insert({"D+", 1.5});
    m.insert({"D0", 1.0});
    m.insert({"F", 0.0});

    double subjectSum = 0.0; // 전공학점의 합을 저장할 변수
    double creditSum = 0.0;  // 학점의 총합을 저장할 변수
    for (int i = 0; i < 20; i++)
    {
        cin >> subject >> credit >> grade;

        if (grade == "P") // 등급이 P인 경우는 학점 계산에 포함하지 않음
        {
            continue;
        }
        else
        {
            double temp = credit * m.find(grade)->second;

            subjectSum += temp;  // 전공학점(학점 * 등급)을 모두 더해줌
            creditSum += credit; // 학점을 모두 더해줌
        }
    }

    cout << fixed;
    cout.precision(6);
    cout << subjectSum / creditSum << "\n"; // 전공학점의 합과 학점의 합을 나눠 학점을 계산
}