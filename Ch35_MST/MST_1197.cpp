// Prim 알고리즘을 통한 MST
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

const int INF = 2147483647; // 32비트 최댓값 : 2,147,483,647

struct Edge {
    int node;
    int weight;
};

// 최소 가중치의 합을 반환
int prim(int start, vector<vector<Edge>> &adjList, vector<bool> &visited, vector<int> &distance) {
    deque<int> dq;
    int weightSum = 0; // 가중치 초기화

    visited[start] = true;
    distance[start] = 0; // 시작노드의 거리는 0으로 초기화

    dq.push_back(start);

    while(!dq.empty()) {
        // 새롭게 이어진 노드의 주변 노드 탐색
        for(Edge e : adjList[dq.front()]) {
            if(visited[e.node] == false && distance[e.node] >= e.weight) { // 방문하지 않았고 가중치가 더 작다면
                distance[e.node] = e.weight;
            }
        }
        
        // 최소 비용 간선 선택
        Edge min; min.node = INF; min.weight = INF;
        for(int i = 0; i < distance.size(); i++) {
            if(min.weight > distance[i] && visited[i] == false) {
                min.node = i;
                min.weight = distance[i];
            }
        }

        // 최소 비용 방문 노드가 존재한다면 
        if(min.node != INF) {
            dq.push_back(min.node); 
            visited[min.node] = true; // 방문처리
            weightSum += min.weight;
        }
        
        dq.pop_front();
    }

    return weightSum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int node, edge;
    cin >> node >> edge;

    vector<vector<Edge>> adjList(node); // 인접 리스트를 통한 간선 정보
    vector<bool> visited(node, false); // 방문 정보 기록
    vector<int> distance(node, INF); // 무한 거리로 초기화 

    // 간선 정보 입력
    while(edge--) {
        int s, e, w;
        cin >> s >> e >> w;
        
        Edge first, second; 
        first.node = s-1; first.weight = w;
        second.node = e-1; second.weight = w;

        adjList[s-1].push_back(second);
        adjList[e-1].push_back(first);
    }

    cout << prim(0, adjList, visited, distance);

    return 0;
}