/* 개선점 
1. 현재 이름은 BFS나 DFS 방식으로 진행중 -> dequeue를 이용해서 front, pop이용(그러나 탐색방법은 상관없음)
2. 방문처리를 push하는 시점에서 하는 것이 좋다 - 중복 push의 가능성
3. 4방향 탐색보다 dx, dy 배열을 활용하면 간결해짐
// 방향 벡터 (상, 하, 좌, 우)
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
*/

#include <iostream>
#include <vector>
using namespace std;

// 좌표계 구조체
struct Coordinate
{
    int x; 
    int y;
};

int BFS(vector<vector<int>> &ground, vector<vector<bool>> &visit) {
    vector<Coordinate> arr; // 현재 탐색중인 배열
    int row = ground.size();
    int col = ground[0].size();
    int worm = 0;

    for(int y = 0; y < row; y++) {
        for(int x = 0; x < col; x++) {
            // 배추가 없거나 방문한 경우는 스킵
            if(ground[y][x] == 0 || visit[y][x] == true) continue;

            Coordinate coord = {x, y};
            arr.push_back(coord);
            
            // BFS 탐색
            while(!arr.empty()) {
                Coordinate now = arr.back();
                visit[now.y][now.x] = true; // 방문처리
                arr.pop_back();

                Coordinate tmp;
                // 4방향 탐색(시계방향) - 범위, 배추여부, 방문여부
                if(now.y - 1 >= 0 && ground[now.y-1][now.x] == 1 && visit[now.y-1][now.x] == false) {
                    tmp.x = now.x; tmp.y = now.y - 1;
                    arr.push_back(tmp);
                }
                if(now.x + 1 < col && ground[now.y][now.x+1] == 1 && visit[now.y][now.x+1] == false) {
                    tmp.x = now.x + 1; tmp.y = now.y;
                    arr.push_back(tmp);
                }
                if(now.y + 1 < row && ground[now.y+1][now.x] == 1 && visit[now.y+1][now.x] == false) {
                    tmp.x = now.x; tmp.y = now.y + 1;
                    arr.push_back(tmp);
                }
                if(now.x - 1 >= 0 && ground[now.y][now.x-1] == 1 && visit[now.y][now.x-1] == false) {
                    tmp.x = now.x - 1; tmp.y = now.y;
                    arr.push_back(tmp);
                }
            }

            worm++;
        }
    }
    
    return worm;
}

int main() {
    // 입출력 최적화
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int testCase; cin >> testCase;

    while(testCase--) {
        // 가로 세로 배추갯수 입력값
        int col, row, cabbage; 
        cin >> col >> row >> cabbage;

        vector<vector<int>> ground(row, vector<int>(col)); // 실제 배추농지
        vector<vector<bool>> visit(row, vector<bool>(col, false)); // 방문 여부
        // 배추 위치 입력값
        for(int i = 0; i < cabbage; i++) {
            int x, y; cin >> x >> y;
            ground[y][x] = 1;
        }

        // 결과값 출력
        cout << BFS(ground, visit) << '\n';
    }
    return 0;
}