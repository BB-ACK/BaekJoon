#include <iostream>
#include <vector>
using namespace std;

void yosepuse(vector<int> arr) {
    vector<int> result;
    int idx, cnt;

    while(!arr.empty()) {
        
    }
}

int main() {
    int num, k;
    cin >> num >> k;
    vector<int> arr;
    
    for(int i = 0; i < num; i++)
        arr.push_back(i+1);
    
    

    return 0;
}

/*
1 2 3 4 5 6 7 -> 3

1 2 (3) 4 5 6 7 -> 6

1 2 (3) 4 5 (6) 7 -> 2 (9)

1 (2) (3) 4 5 (6) 7 -> 7 (12)


*/