#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;


void dfs(vector<deque<int>> &adjList, vector<bool> &visited, vector<int> &result, int s) {
    int count = 1;
    vector<int> vec;
    vec.push_back(s);
        
    visited[s] = true; // 방문처리
    result[s] = count++; // 결과의 순서를 반영

    while (!vec.empty()){
        s = vec.back();
        bool goNext = false;

        for(int i : adjList[s]) {
            if(visited[i] == false) {
                adjList[s].pop_front();
                visited[i] = true;
                result[i] = count++;

                goNext = true;
                vec.push_back(i);
                break;
            }

        }
        if(goNext == false) {
            vec.pop_back();
        }
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int node, edge, start;
    cin >> node >> edge >> start;

    vector<deque<int>> adjList(node+1); // 인접 리스트
    vector<bool> visited(node+1, false); // 노드의 방문을 확인용
    vector<int> result(node + 1, 0);

    while(edge--) {
        int s, e; cin >> s >> e;
        adjList[s].push_back(e);
        adjList[e].push_back(s);
    }

    // 정렬
    for(int i = 1; i <=node; i++) {
        sort(adjList[i].begin(), adjList[i].end());
    }

    dfs(adjList, visited, result, start);
    
    // 결과 출력
    for(int i = 1; i <= node; i++) {
        cout << result[i] << '\n';
    }

    return 0;
}