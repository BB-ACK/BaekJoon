#include <iostream>
#include <queue>
using namespace std;

struct roomTime {
    int start;
    int end;
};

struct cmp {
    bool operator() (roomTime a, roomTime b) {
        if(a.start == b.start)
            return a.end > b.end;
        else
            return a.start > b.start;
    }
};

int main() {
    priority_queue<roomTime, vector<roomTime>, cmp> classes;
    priority_queue<roomTime, vector<roomTime>, cmp> tempo;
    priority_queue<roomTime, vector<roomTime>, cmp> zero;
    int num; cin >> num;
    int count = 0;

    while(num--) {
        roomTime tmp;
        cin >> tmp.start >> tmp.end;
        classes.push(tmp);
    }

    while(1) {
        if(classes.empty())
            break;
        int newStart = classes.top().end;
        classes.pop();
        
        while(1) {
            // 수업이 끝나기 전에 다른 수업이 시작하는 경우
            if(!classes.empty() && newStart > classes.top().start) {
                tempo.push(classes.top());
                classes.pop();
            }
            else if(!classes.empty()){
                newStart = classes.top().end;
                classes.pop();
            }

            if(classes.empty() && !tempo.empty()) {
                classes = tempo;
                tempo = zero;
                count++;
                break;
            }

            if (classes.empty() && tempo.empty()) {
                count++;
                break;
            }
        }
        
    }
    cout << count;
    return 0;
}