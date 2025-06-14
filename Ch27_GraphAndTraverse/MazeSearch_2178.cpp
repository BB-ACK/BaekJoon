// BFS를 통한 문제해결
#include <iostream>
#include <string>
#include <deque>
using namespace std;

// 그래프 탐색시 
struct Coordinate {
    int x;
    int y;
    int count;
};

// 그래프의 각 정점 정보
struct Vertex {
    int data;
    bool visited = false; // 방문 정보 false
};

// BFS를 통한 미로탐색
int mazeSearch(deque<deque<Vertex>> &graph) {
    deque<Coordinate> dq;
    Coordinate start = {0, 0, 0}; // 시작위치
    Coordinate end = {graph[0].size()-1, graph.size()-1, 0}; // 도착위치
    
    dq.push_back(start);

    while(!dq.empty()) {
        Coordinate coord = dq.front();
        dq.pop_front();
        
        // 도착위치에 도달시 종료
        if(coord.x == end.x && coord.y == end.y)
            return coord.count + 1;

        Coordinate plus;
        // 방문 좌표계
        if (coord.x + 1 <= end.x && graph[coord.y][coord.x + 1].data == 1 && graph[coord.y][coord.x + 1].visited == false) {
            plus.x = coord.x+1;
            plus.y = coord.y;
            plus.count = coord.count+1;
            graph[plus.y][plus.x].visited = true;
            dq.push_back(plus);
        }
        if (coord.y + 1 <= end.y && graph[coord.y + 1][coord.x].data == 1 && graph[coord.y + 1][coord.x].visited == false) {
            plus.x = coord.x;
            plus.y = coord.y+1;
            plus.count = coord.count + 1;
            graph[plus.y][plus.x].visited = true;
            dq.push_back(plus);
        }
        if (coord.x - 1 >= 0 && graph[coord.y][coord.x - 1].data == 1 && graph[coord.y][coord.x - 1].visited == false) {
            plus.x = coord.x-1;
            plus.y = coord.y;
            plus.count = coord.count + 1;
            graph[plus.y][plus.x].visited = true;
            dq.push_back(plus);
        }
        if (coord.y - 1 >= 0 && graph[coord.y - 1][coord.x].data == 1 && graph[coord.y - 1][coord.x].visited == false) {
            plus.x = coord.x;
            plus.y = coord.y-1;
            plus.count = coord.count + 1;
            graph[plus.y][plus.x].visited = true;
            dq.push_back(plus);
        }
    }

}

int main() {
    // 입출력 최적화 
    ios::sync_with_stdio(false);
    cin.tie(0);

    int row, col;
    cin >> row >> col;

    deque<deque<Vertex>> graph(row);
    for(int i = 0; i < row; i++) {
        string num; cin >> num;

        Vertex ver;
        for(char digit : num) {
            ver.data = digit - '0';
            graph[i].push_back(ver);
        }
    }


    cout << mazeSearch(graph);
    return 0;
}