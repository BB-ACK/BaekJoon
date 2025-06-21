// BFS를 통한 문제 풀이
#include <iostream>
#include <deque>
using namespace std;

// BFS로 감염파악
int BFS(deque<deque<int>> &arr, deque<bool> &visited, int start) {
    deque<int> dq; 
    int count = 0; // 감염 컴퓨터의 수
    visited[start] = true; 
    dq.push_back(start);
    
    while(!dq.empty()) {
        int node = dq.front();
        dq.pop_front();
        
        for(int n : arr[node]) {
            // 방문하지 않은 노드만 추가
            if(visited[n] == false) {
                dq.push_back(n);
                visited[n] = true;
                count++;
            }
        }
    }

    return count;
}

int main() {
    int node; cin >> node;
    int edge; cin >> edge;

    deque<deque<int>> arr(node);
    deque<bool> visited(node); // 방문정보 기록

    while(edge--) {
        int u, v;
        cin >> u >> v;

        arr[u-1].push_back(v-1);
        arr[v-1].push_back(u-1);
    }

    cout << BFS(arr, visited, 0);

    return 0;
}