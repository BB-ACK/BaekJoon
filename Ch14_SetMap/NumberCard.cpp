#include <iostream>
#include <vector>
using namespace std;

void isContain(vector<int> &have, vector<int> &find) {
    int haveLen = have.size();
    int findLen = find.size();

    for(int i = 0; i < findLen; i++) {
        for(int j = 0; j < haveLen; j++) {
            if(find[i] == have[j]) {
                cout << 1 << " ";
                break;
            }
            else if(j == haveLen -1) 
                cout << 0 << " ";
        }
    }
}

int main() {
    int haveNum; cin >> haveNum;
    vector<int> have(haveNum);

    for(int i = 0; i < haveNum; i++)
        cin >> have[i];

    int findNum; cin >> findNum;
    vector<int> find(findNum);
    
    for(int i = 0; i < findNum; i++) 
        cin >> find[i];
    
    isContain(have, find);
    
    return 0;
}