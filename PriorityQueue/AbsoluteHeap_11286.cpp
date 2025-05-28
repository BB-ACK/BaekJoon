#include <iostream>
#include <deque>
using namespace std;

class AHeap {
private:
    deque<int> heap;
    int size;

public:
    // 생성자
    AHeap() {
        this->heap.push_back(0); // 완전 이진트리의 0번 인덱스 사용을 하지 않기 위함
        this->size = 0;
    }

    int isEmpty() {
        return this->size == 0;
    }

    void insert(int e) {
        this->heap.push_back(e);
        this->size++;

        this->upHeap();
    }

    void upHeap() {
        int idx = this->size;
        int key = this->heap[size];
        
        // 노드가 현재 루트 노드가 아니고 절대값이 더 작다면면
        while(idx != 1 && (abs(key) < abs(this->heap[idx / 2]) || (abs(key) == abs(this->heap[idx / 2]) && key < this->heap[idx / 2]) )) {
            this->heap[idx] = this->heap[idx / 2]; // 부모 노드와 교체
            idx /= 2;
        }

        // 절대값이 같고 더 작은 경우
        // if(abs(key) == abs(this->heap[idx / 2]) && key < this->heap[idx / 2]) {
        //     this->heap[idx] = this->heap[idx / 2];
        //     idx /= 2;
        // }

        this->heap[idx] = key;
    }

    int remove() {
        if(this->isEmpty())
            return 0;
        
        int key = this->heap[1];
        this->heap[1] = this->heap.back();
        this->heap.pop_back();
        this->size--;

        this->downHeap();

        return key;
    }

    void downHeap() {
        int key = this->heap[1];
        int pi = 1;
        int ci = 2;

        while(ci <= this->size) {
            // 내려갈 방향을 선택 : 더 작은 값을 올려야함
            if(ci < this->size && (abs(this->heap[ci+1]) < abs(this->heap[ci]) || (abs(this->heap[ci+1]) == abs(this->heap[ci]) && this->heap[ci+1] < this->heap[ci])))
                ci++;
            
            // 절대값이 더 작거나
            if(abs(key) < abs(this->heap[ci]) || (abs(key) == abs(this->heap[ci]) && key <= this->heap[ci]))
                break;

            this->heap[pi] = this->heap[ci];
            pi = ci;
            ci *= 2;
        }

        // 절대 값이 같은 경우
        // if(abs(key) == abs(this->heap[ci]) && key < this->heap[ci]) {
        //     this->heap[pi] = this->heap[ci];
        //     pi = ci;
        //     ci *= 2;
        // }

        this->heap[pi] = key;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int num; cin >> num;
    AHeap ah;

    while(num--) {
        int cmd; cin >> cmd;

        if(cmd != 0) {
            ah.insert(cmd);        
        }
        else {
            cout << ah.remove() << '\n';
        }
    }
    return 0;
}