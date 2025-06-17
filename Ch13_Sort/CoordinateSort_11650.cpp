// Heap을 이용한 문제 풀이
#include <iostream>
#include <vector>
using namespace std;

struct coordinate {
    int x;
    int y;
};

class CoordHeap {
private:
    vector<coordinate> arr;
    int size;
public:
    // 생성자
    CoordHeap() {
        coordinate null;
        this->arr.push_back(null); // 0번 인덱스 사용하지 않기 위함
        this->size = 0;
    }

    void insert(coordinate coord) {
        // 일단 삽입
        this->arr.push_back(coord);
        this->size++;

        // 올바른 위치의 등산 과정
        int idx = this->size;
        // 루트 노드가 아니고 x값이 더 작거나 같아야함
        while(idx != 1 && this->arr[idx].x <= this->arr[idx/2].x) {
            // 만약 x값이 같은 경우 y값으로 판단
            if(this->arr[idx].x == this->arr[idx/2].x && this->arr[idx].y > this->arr[idx/2].y)
                break;
            
            this->arr[idx] = this->arr[idx/2];
            idx /= 2;
        }

        this->arr[idx] = coord;
    }

    coordinate pop() {
        coordinate result = this->arr[1]; // 리턴값

        this->arr[1] = this->arr[this->size]; // 마지막 값을 루트로 선정
        this->size--;

        // 올라온 노드의 하산과정
        coordinate key = this->arr[1]; // 내려갈 좌표
        int pi = 1;
        int ci = 2;

        // 자식값이 존재해야함
        while(ci <= this->size) {
            // 자식 노드 중 올릴 것을 선택
            if(ci < this->size && this->arr[ci].x >= this->arr[ci+1].x) {
                if(this->arr[ci].x == this->arr[ci+1].x && this->arr[ci].y > this->arr[ci+1].y)
                    ci++;
                else 
                    ci++;
            }

            // 더 작으면 내려갈 필요가 없음
            if(key.x <= this->arr[ci].x) {
                // 같아도 y값이 더 작으면 내려갈 필요없음
                if(key.x == this->arr[ci].x && key.y < this->arr[ci].y)
                    break;
                else break;
            }

            this->arr[pi] = this->arr[ci];
            pi = ci;
            ci *= 2;
        }

        this->arr[pi] = key;

        return result;
    }
};

int main() {
    // 입출력 최적화
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int cNum; cin >> cNum;
    CoordHeap ch;

    coordinate coord;
    for(int i = 0; i < cNum; i++) {
        cin >> coord.x >> coord.y;
        ch.insert(coord);
    }

    while(cNum--) {
        coordinate e = ch.pop();
        cout << e.x << " " << e.y << '\n';
    }
    
    return 0;
}