#include <iostream>
#include <string>
using namespace std;

int main() {
    // 입력
    while(1) {
        string line;
        getline(cin, line);

        if(cin.eof()) // 미입력 또는 종료
            break;
            
        cout << line << '\n'; 
    }

    return 0;
}