// 크루스칼 알고리즘을 통한 문제해결
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// 좌표계 
struct Coordinate {
    double x;
    double y;
};

// 간선 구조
struct Edge {
    int sNode; // 시작 노드 번호
    int eNode; // 연결 노드 번호
    double weight; // 가중치
};

// 정렬 기준 - 가중치 오름차순
bool cmp(Edge a, Edge b) {
    return a.weight < b.weight; 
}

// 유니온 파인드
vector<int> parent;
int find(int x) {
    // 자기 자신이 부모인 경우 -> 즉 독자적인 노드
    if(parent[x] == x)
        return x;
    return parent[x] = find(parent[x]); // 부모 루트까지 경로가 이어짐짐
}

void unionSet(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b)  // 부모노드가 다르면 
        parent[b] = a;
}

// 크루스칼 알고리즘
double kruskal(vector<Edge> &edgeList, int nodeNum) {
    parent.resize(nodeNum); 
    for(int i = 0; i < nodeNum; i++) 
        parent[i] = i; // 부모를 자기 자신으로 초기화
    
    
    int count = 0; // 간선의 갯수
    double result = 0;
    for(Edge e : edgeList) {
        if(count == nodeNum - 1) // 간선의 갯수가 충족하면
            break;
        
        if(find(e.sNode) != find(e.eNode)) {
            count++;
            result += e.weight;
            unionSet(e.sNode, e.eNode);
        }
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int nodeNum; cin >> nodeNum;
    vector<Coordinate> coordArr; // 좌표계를 저장할 배열
    vector<Edge> edgeList; // 간선 정보들을 저장할 배열

    Coordinate coord;
    for(int i = 0; i < nodeNum; i++) {
        cin >> coord.x >> coord.y;
        coordArr.push_back(coord);
    }

    // 모든 간선의 정보를 계산
    Edge edge;
    for(int i = 0; i < coordArr.size() - 1; i++) { // 마지막 노드는 계산 필요 x
        Coordinate std = coordArr[i];
        edge.sNode = i; // 시작 노드 번호
        for(int j = i+1; j < coordArr.size(); j++) {
            Coordinate tmp = coordArr[j];
            edge.eNode = j; // 연결 노드 번호
            
            // 가중치(거리) 계산
            edge.weight = sqrt((std.x - tmp.x) * (std.x - tmp.x) + (std.y - tmp.y) * (std.y - tmp.y));

            edgeList.push_back(edge);
        }
    }

    sort(edgeList.begin(), edgeList.end(), cmp); // 가중치 기준 오름차순

    
    cout.precision(3);
    cout << kruskal(edgeList, nodeNum);
    
    return 0;
}