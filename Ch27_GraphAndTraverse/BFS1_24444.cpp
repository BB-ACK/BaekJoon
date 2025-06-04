#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

void BFS(int start, vector<vector<int>> &adjList, vector<bool> &visited, vector<int> &result) {
    deque<int> dq;
    int count = 1;

    visited[start] = true; // 시작노드 방문처리
    result[start] = count++;

    dq.push_back(start);

    while (!dq.empty()) {
        for(int e : adjList[dq.front()]) {
            if(visited[e] != true) {
                dq.push_back(e);
                result[e] = count++;
                visited[e] = true;
            }
        }
        dq.pop_front();
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int node, edge, start;
    cin >> node >> edge >> start;

    vector<vector<int>> adjList(node+1); // 인접리스트
    vector<bool> visited(node+1); // 방문기록
    vector<int> result(node+1); // 첫 번쨰 노드부터 방문순서를 나타내는 결과


    // 인접 리스트 삽입
    while(edge--) {
        int s, e;
        cin >> s >> e;
        adjList[s].push_back(e);
        adjList[e].push_back(s);
    }

    // 오름차순 정렬
    for(int i = 1; i <= node; i++) {
        sort(adjList[i].begin(), adjList[i].end());
    }

    BFS(start, adjList, visited, result);

    // 결과 출력
    for(int i = 1; i < result.size(); i++) {
        cout << result[i] << '\n';
    }

    return 0;
}