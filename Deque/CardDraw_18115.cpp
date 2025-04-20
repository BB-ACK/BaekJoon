#include <iostream>
#include <deque>
using namespace std;

void draw(deque<int> &arr) {
    deque<int> result;
    int cur = 1;

    for(int i = arr.size(); i > 0; i--) {
        int draw = arr[i-1];

        if(draw == 1) {
            result.push_front(cur);
        }
        else if(draw == 2){
            result.insert(result.begin() + 1, cur);
        }
        else {
            result.push_back(cur);
        }
        cur++;
    }

    for(int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
}

int main() {
    int num; cin >> num;
    deque<int> arr;

    while(num--) {
        int draw; cin >> draw;
        arr.push_back(draw);
    }

    draw(arr); 
    return 0;
}