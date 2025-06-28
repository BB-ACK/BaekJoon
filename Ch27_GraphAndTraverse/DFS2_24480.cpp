#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

// DFS 알고리즘
void DFS(int s, deque<deque<int>> &arr, deque<bool> &viisted, deque<int> &result) {
    int count = 1;
    deque<int> dq;
    dq.push_back(s);
    result[s] = count++;

    while(!dq.empty()) {
        int cur = dq.back();
        viisted[cur] = true;

        bool goNext = false;
        for(int e : arr[cur]) {
            if(viisted[e] == false) {
                result[e] = count++;
                arr[cur].pop_front();
                dq.push_back(e);
                viisted[e] = true;
                goNext = true;

                break;
            }
        }

        if(goNext == false)
            dq.pop_back();
    }
}

int main() {
    // 입출력 최적화
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int node, edge, start;
    cin >> node >> edge >> start;

    deque<deque<int>> arr(node+1);
    deque<bool> visited(node+1);
    deque<int> result(node+1, 0);

    // 입력문 
    for(int i = 0; i < edge; i++) {
        int u, v;
        cin >> u >> v;
        
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    // 정렬
    for(int i = 1; i <= node; i++) 
        sort(arr[i].begin(), arr[i].end(), cmp);

    DFS(start, arr, visited, result);

    for(int i = 1; i < result.size(); i++)
        cout << result[i] << '\n';

    return 0;
}