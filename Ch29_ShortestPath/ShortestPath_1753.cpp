// 다익스트라 알고리즘을 통한 문제해결
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

long long INF = 6000000000;

// 간선 구조
struct Edge {
    int node;
    int weight;
};

struct Node {
    int node;
    long long dist;

    bool operator<(const Node& other) const {
        return dist > other.dist;
    }
};

// 다익스트라 알고리즘
void dijkstra(int sNode, int nNum, vector<long long> &distance, vector<vector<Edge>> &adjList) {
    distance[sNode] = 0; // 시작정점은 0

    priority_queue<Node> pq;
    Node node; node.dist = 0; node.node = sNode;
    pq.push(node);

    while(!pq.empty()) {
        Node cur = pq.top();
        pq.pop();

        // 이미 더 짧은 경로로 방문했다면 무시 
        if(distance[cur.node] < cur.dist) 
            continue;

        for(Edge e : adjList[cur.node]) {
            long long cost = distance[cur.node] + e.weight;

            // 경유 비용이 더 적다면
            if(cost < distance[e.node]) {
                distance[e.node] = cost;
                pq.push({e.node, cost});
            }
        }
    }
    

}

int main() {
    // 입출력 최적화
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int nNum, eNum, sNode;
    cin >> nNum >> eNum;
    cin >> sNode;

    vector<long long> distance(nNum+1, INF); // 최단경로를 나타낼 배열 
    vector<vector<Edge>> adjList(nNum+1); // 인접리스트를 활용한 간선정보

    // 간선 정보 입력
    Edge e;
    for(int i = 0; i < eNum; i++) { 
        // 방향성이 존재!!
        int u, v, w;
        cin >> u >> v >> w; // ex) 5 1 1

        e.node = v; e.weight = w;
        adjList[u].push_back(e); // 5에 (1, 1) 삽입
    }

    dijkstra(sNode, nNum, distance, adjList);

    // 출력문
    for(int i = 1; i < distance.size(); i++) {
        long long dist = distance[i];
        if(dist == INF)
            cout << "INF" << '\n';
        else
            cout << dist << '\n';

    }

    return 0;
}