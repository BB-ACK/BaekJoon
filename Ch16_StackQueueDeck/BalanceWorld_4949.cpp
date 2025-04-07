#include <iostream>
#include <string>
#include <vector>
using namespace std;

string checkingBrackets(string str) {
    vector<char> vec;

    for(int i = 0; i < str.length(); i++) {
        // 여는 괄호는 푸시
        if(str[i] == '(' || str[i] == '{' || str[i] == '[') {
            vec.push_back(str[i]);
        }
        // 닫는 괄호의 경우
        else if(str[i] == ')' || str[i] == '}' || str[i] == ']') {
            if(vec.empty())
                return "no";
            else {
                char tmp = vec.back();
                vec.pop_back();

                if(str[i] == ')' && tmp != '(')
                    return "no";

                else if(str[i] == '}' && tmp != '{')
                    return "no";

                else if(str[i] == ']' && tmp != '[')
                    return "no";
            }
        }
    }
    // 비어있지 않다면 -> 괄호 갯수 안 맞음
    if(!vec.empty())
        return "no";

    // 모든 조건을 통과
    return "yes";

}

int main() {
    string str;

    while(1) {
        getline(cin, str);
        if(str == ".")
            break;
        
        cout << checkingBrackets(str) << endl;
    }


    return 0;
}
