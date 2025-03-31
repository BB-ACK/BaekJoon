#include <iostream>
#include <string>

using namespace std;

int main() {
    string subject, grade;
    float credit, sum;
    float result;
    
    for(int i = 0; i < 20; i++) {
        cin >> subject >> credit >> grade;

        if(grade == "P")
            continue;
        sum += credit;
        
        // 등급에 따른 전공 점수 계산
        if(grade == "A+") {
            result += credit * 4.5;
        }
        else if(grade == "A0") {
            result += credit * 4.0; 
        }
        else if(grade == "B+") {
            result += credit * 3.5; 
        }
        else if(grade == "B0") {
            result += credit * 3.0; 
        }
        else if(grade == "C+") {
            result += credit * 2.5; 
        }
        else if(grade == "C0") {
            result += credit * 2.0; 
        }
        else if(grade == "D+") {
            result += credit * 1.5; 
        }
        else if(grade == "D0") {
            result += credit * 1.0; 
        }
        else if(grade == "F") {
            result += credit * 0.0; 
        }
        
    }

    cout << result / sum;
}
