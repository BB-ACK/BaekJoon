#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct coordinate {
    int x;
    int y;
};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int bfs(vector<vector<int>> &graph,vector<vector<bool>> &visited, int y, int x) {
    coordinate coord;
    coord.x = x; coord.y = y;
    visited[coord.y][coord.x] = true; 

    vector<coordinate> vec;
    vec.push_back(coord);

    int cnt = 1;
    while(!vec.empty()) {
        coord.x = vec.back().x;
        coord.y = vec.back().y;
        vec.pop_back();

        // 4방향 확인
        for(int i = 0; i < 4; i++) {
            coordinate next;
            next.x = coord.x + dx[i];
            next.y = coord.y + dy[i];
            if(next.x >= 0 && next.x < graph.size() && next.y >= 0 && next.y < graph.size()) {
                if(graph[next.y][next.x] == 1 && visited[next.y][next.x] == false) {
                    cnt++;
                    visited[next.y][next.x] = true;
                    vec.push_back(next);
                }
            }
        }

    }

    return cnt;
    
}

int main() {
    // 입출력 최적화
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int size; cin >> size;
    vector<vector<int>> graph(size);
    vector<vector<bool>> visited(size, vector<bool>(size, false));

    // 그래프 입력
    for(int i = 0; i < size; i++) {
        string num; cin >> num;
        
        // 정수로 변환해서 대입
        for(char digit : num) {
            graph[i].push_back(digit - '0');
        }
    }

    vector<int> result;
    // 순회
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if(graph[i][j] == 1 && visited[i][j] == false) {
                int cnt = bfs(graph, visited, i, j);
                result.push_back(cnt);
            }
        }
    }

    sort(result.begin(), result.end());
    
    // 결과 출력
    cout << result.size() << '\n'; // 총 단지 수 출력
    for(int cnt : result) {
        cout << cnt << '\n'; // 단지내의 집의 수 출력
    }

    return 0;
}