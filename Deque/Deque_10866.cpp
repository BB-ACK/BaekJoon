#include <iostream>
#include <string>
using namespace std;

class Deque {
private:
    int *arr; // 배열
    int front; // 맨 앞 요소
    int rear; // 맨 뒤 요소
    int size; // 원소 갯수
    int capacity; // 배열 용량

public:
    // 생성자
    Deque() {
        this->front = 0;
        this->rear = 0;
        this->size = 0;
        this->capacity = 10001;
        this->arr = new int[this->capacity];
    }

    // 비어 있는지 확인
    int isEmpty() {
        return this->front == this->rear;
    }

    // 가득 차 있는 지
    int isFull() {
        return this->front == (this->rear + 1) % this->capacity; 
    }

    // 원소 갯수 출력력
    void getSize() {
        cout << this->size << '\n';
    }

    // 맨 앞에 요소를 넣기
    void push_front(int e) {
        if(this->isFull())
            return;

        arr[this->front] = e;
        this->front = (this->front - 1 + this->capacity) % this->capacity;
        this->size++;
    }

    // 맨 뒤에 요소를 넣기
    void push_back(int e) {
        if(this->isFull())
            return;

        this->rear = (this->rear + 1 + this->capacity) % this->capacity;
        arr[this->rear] = e;
        this->size++;
    }

    // 맨 앞에 요소 빼기
    void pop_front() {
        if(this->isEmpty()) {
            cout << -1 << '\n';
            return;
        }

        this->front = (this->front + 1 + this->capacity) % this->capacity;
        cout << arr[this->front] << '\n';
        // arr[this->front] = NULL;
        this->size--;
    }

    // 맨 뒤에 요소 빼기
    void pop_back() {
        if (this->isEmpty()) {
            cout << -1 << '\n';
            return;
        }

        cout << arr[this->rear] << '\n';
        this->rear = (this->rear - 1 + this->capacity) % this->capacity;
        // arr[this->rear] = NULL;
        this->size--;
    }

    // 맨 앞 요소 참조
    void getFront() {
        if(this->isEmpty()) {
            cout << -1 << '\n';
            return;
        }

        cout << arr[(this->front + 1 + this->capacity) % this->capacity] << '\n';
    }

    // 맨 뒤 요소 참조
    void getRear() {
        if (this->isEmpty()) {
            cout << -1 << '\n';
            return;
        }

        cout << arr[this->rear] << '\n';
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int num; cin >> num;
    Deque dq;

    while(num--) {
        string cmd; cin >> cmd;

        if(cmd == "push_front") {
            int e; cin >> e;
            dq.push_front(e);
        }
        else if (cmd == "push_back") {
            int e; cin >> e;
            dq.push_back(e);
        }
        else if (cmd == "pop_front") {
            dq.pop_front();
        }
        else if (cmd == "pop_back") {
            dq.pop_back();
        }
        else if(cmd == "size") {
            dq.getSize();
        }
        else if(cmd == "empty") {
            cout << dq.isEmpty() << '\n';
        }
        else if(cmd == "front") {
            dq.getFront();
        }
        else if(cmd == "back") {
            dq.getRear();
        }
    }
    return 0;
}