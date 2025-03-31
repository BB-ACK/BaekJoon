#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

// DFS 탐색 알고리즘
void DFS(vector<int> arr[], bool vis[], int start) {
    vis[start] = true;
    cout << start << " ";
    
    // 재귀적으로 DFS 탐색
    for(auto next : arr[start]) {
        if(vis[next]) continue;
        DFS(arr, vis, next);
    }
}

// BFS 탐색 알고리즘
void BFS(vector<int> arr[], bool vis[], int start) {
    // 인접한 노드들
    queue<int> q;
    
    // 시작 노드를 대입 후 방문했다고 설정
    q.push(start);
    vis[start] = true;

    // 주변 노드들을 다 방문할 때까지 반복
    while(!q.empty()) {
        int cur = q.front();
        q.pop(); // 현재 노드를 꺼내서 cur값에 넣고 값을 뺌
        cout << cur << " ";

        for(auto next : arr[cur]) {
            if(vis[next])
                continue; // 해당 노드가 이미 방문했던 것이라면 넘어감
            q.push(next);
            vis[next] = true; // 방문하지 않았다면 큐에 노드를 넣어주고 방문표시
        }
    }
}

int main() {
    int node, edge, start;
    cin >> node >> edge >> start;
    
    vector<int> arr[1001];
    bool vis[1001] = {false}; // 해당 노드가 방문했는 지 여부를 확인

    for(int i = 0; i < edge; i++) {
        int u, v; cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    // 간선 리스트 초기화화
    for(int i = 1; i <=node; i++) {
        sort(arr[i].begin(), arr[i].end());
    }

    DFS(arr, vis, start);
    cout << endl;
    fill(vis, vis + node + 1, false); // 변경된 vis 배열 초기화
    BFS(arr, vis, start);

    return 0;
}