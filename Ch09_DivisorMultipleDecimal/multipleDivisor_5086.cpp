#include <iostream>
#include <string>
using namespace std;

string seperate(int first, int second) {
    if(second % first == 0)
        return "factor";
    else if(first % second == 0)
        return "multiple";
    else
        return "neither";
}


int main() {
    int first, second;

    while(1) {
        cin >> first >> second;
        
        if(first == 0 && second == 0)
            break;

        cout << seperate(first, second) << endl;
    }
    
    return 0;
}