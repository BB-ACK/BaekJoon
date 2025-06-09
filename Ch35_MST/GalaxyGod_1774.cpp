// 크루스칼 알고리즘을 통한 구현
#include <iostream>
#include <vector>
#include <cmath> // 거리 계산을 위한
#include <algorithm>
using namespace std;

vector<int> parent; // 각 노드의 부모 노드
int edgeCnt = 0; // 연결된 간선 갯수

struct Coordinate {
    int x;
    int y;
};

struct Edge {
    int u;
    int v;
    double weight; 
};

// 가중치 내림차순 정렬
bool cmp(Edge a, Edge b) {
    return a.weight < b.weight; 
}   

// 부모 노드를 찾는 함수
int find(int x) {
    if(parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

// 두 노드를 하나의 집합으로 합치는 함수수
void unionSet(int a, int b) {
    a = find(a);
    b = find(b);

    if(a != b) 
        parent[b] = a;
}

// 크루스칼 알고리즘 -> 사이클이 없도록 최소 간선을 선택
double kruskal(vector<Edge> &edges, int nNum) {
    double result = 0;
    
    sort(edges.begin(), edges.end(), cmp); // 내림차순 정렬 -> pop을 위해

    // 종료 조건 -> 간선의 갯수가 정점 갯수 -1개
    for(Edge e : edges) {
        if(edgeCnt == nNum - 1)
            break;

        int uParent = find(e.u);
        int vParent = find(e.v);

        if(uParent != vParent) {
            unionSet(e.u, e.v);
            edgeCnt++;
            result += e.weight;
        }
    }

    return result;
    
}

int main() {
    int nNum, connected;
    cin >> nNum >> connected;

    parent.resize(nNum);
    for(int i = 0; i < parent.size(); i++) {
        parent[i] = i;
    }
    
    vector<Coordinate> coordArr; // 좌표들 배영
    vector<Edge> edges; // 간선 정보들 배열

    Coordinate coord;
    for(int i = 0; i < nNum; i++) {
        cin >> coord.x >> coord.y;
        coordArr.push_back(coord);
    }

    // 모든 간선의 경우 계산
    Edge edge;
    for(int i = 0; i < coordArr.size()-1; i++) {
        edge.u = i;
        for(int j = i+1; j < coordArr.size(); j++) {
            edge.v = j;

            edge.weight = sqrt(pow(coordArr[i].x - coordArr[j].x, 2) + pow(coordArr[i].y - coordArr[j].y, 2));

            edges.push_back(edge);
        }
    }

    // 이미 연결된 간선 반영
    while(connected--) {
        int u, v;
        cin >> u >> v;

        unionSet(u-1, v-1);
    }

    
    cout << fixed;
    cout.precision(2);
    cout << kruskal(edges, nNum);

    return 0;
}