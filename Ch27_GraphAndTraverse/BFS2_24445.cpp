#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

// 내림차순 정렬
bool cmp(int a, int b) { 
    return a > b;
}

void BFS(int s, deque<bool> &visited, deque<deque<int>> &adjList, deque<int> &result) {
    deque<int> dq; // 현재 노드들 정보
    int count = 0; // 순서 기록
    
    dq.push_back(s);
    visited[s] = true;
    result[s] = ++count;

    while(!dq.empty()) {
        int node = dq.front();
        dq.pop_front();

        for(int e : adjList[node]) {
            if(visited[e] == false) {
                dq.push_back(e);
                visited[e] = true; // 방문처리
                result[e] = ++count; // 결과에 순서 반영
            }
        }
    }
}

int main() {
    // 입출력 최적화
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int node, edge, start;
    cin >> node >> edge >> start;

    deque<bool> visited(node+1); // 방문정보
    deque<deque<int>> adjList(node+1); // 인접리스트
    deque<int> result(node+1, 0); // 결과

    // 간선정보 입력
    for(int i = 0; i < edge; i++) {
        int u, v;
        cin >> u >> v;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // 정렬
    for(int i = 1; i <= node; i++)
        sort(adjList[i].begin(), adjList[i].end(), cmp);

    BFS(start, visited, adjList, result);

    // 출력문
    for(int i = 1; i <= node; i++) 
        cout << result[i] << '\n';
    
    return 0;
}