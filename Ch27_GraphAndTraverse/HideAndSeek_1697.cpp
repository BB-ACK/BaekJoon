// BFS를 이용한 최단거리 탐색
#include <iostream>
#include <deque>
using namespace std;

int INF = 100000; // 최대 좌표값
deque<bool> visited(INF, false); // 방문정보

int seek(int start, int end) {
    deque<pair<int, int>> dq; // 현재 위치와, 현재 이동 시간을 저장

    dq.push_back({start, 0});

    while(!dq.empty()) {
        int coord = dq.front().first;
        int time = dq.front().second;
        dq.pop_front();

        visited[coord] = true;

        // 종료 조건문
        if(coord == end)
            return time;

        if(coord-1 >= 0 && visited[coord-1] == false) {
            dq.push_back({coord-1, time+1}); // 걷기 X-1
            visited[coord-1] = true;
        }

        if(coord+1 <= INF && visited[coord+1] == false && coord < end) {
            dq.push_back({coord+1, time+1}); // 걷기 X+1
            visited[coord+1] = true;
        }
        if(coord*2 <= INF && visited[coord*2] == false && coord < end) {
            dq.push_back({coord*2, time+1}); // 순간이동 2*X
            visited[coord*2] = true;
        }
    }

}

int main() {
    int start, end;
    cin >> start >> end;

    cout << seek(start, end);

    return 0;
}