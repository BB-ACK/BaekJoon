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
    bool visited = false; // 해당 좌표에 방문 정보보
};

// 간선 구조
struct Edge {
    Coordinate *sNode; // 시작 좌표
    Coordinate *eNode; // 연결 좌표
    double weight; // 가중치
};

// 정렬 기준 - 가중치 오름차순
bool cmp(Edge a, Edge b) {
    return a.weight < b.weight; 
}

// 크루스칼 알고리즘즘
double kruskal(vector<Edge> &edgeList, int nodeNum) {
    int count = 0; // 간선의 갯수
    double result = 0;
    for(Edge e : edgeList) {
        if(count == nodeNum - 1) // 간선의 갯수가 충족하면
            break;

        // 사이클이 생기지 않으면
        if(e.sNode->visited == false || e.eNode->visited == false) {
            result += e.weight;
            count++;
        }
    }

    return result;
}

int main() {
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
        Coordinate *std = &coordArr[i];
        edge.sNode = std;
        for(int j = i+1; j < coordArr.size(); j++) {
            Coordinate *tmp = &coordArr[j];
            edge.eNode = tmp;
            
            // 가중치(거리) 계산
            edge.weight = sqrt((std->x - tmp->x) * (std->x - tmp->x) + (std->y - tmp->y) * (std->y - tmp->y));

            edgeList.push_back(edge);
        }
    }

    sort(edgeList.begin(), edgeList.end(), cmp); // 가중치 기준 오름차순

    
    cout.precision(3);
    cout << kruskal(edgeList, nodeNum);
    
    return 0;
}