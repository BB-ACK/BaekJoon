#include <iostream>
#include <string>
using namespace std;

class queue {
private:
    int size;
    int front;
    int top;
    int *arr;
public:
    // 생성자
    queue() {
        this->size = 0;
        this->front = 0;
        this->top = 0;
        this->arr = new int[10000];
    }

    int isEmpty() {
        return this->size == 0;
    }

    void push(int e) {
        this->arr[this->top] = e;
        this->top++;

        this->size++;
    }

    int pop() {
        if(this->isEmpty())
            return -1;
        
        int e = this->arr[this->front];
        this->front++;

        this->size--;

        return e;
    }

    int returnSize() {
        return this->size;
    }

    int returnFront() {
        if(this->isEmpty()) 
            return -1;
        
        return this->arr[this->front];
    }

    int back() {
        if(this->isEmpty())
            return -1;

        return this->arr[this->top - 1];
    }
};

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);

    int test; cin >> test;
    queue Q;

    while(test--) {
        string cmd; cin >> cmd;

        if(cmd == "push") {
            int e; cin >> e;
            Q.push(e);
        }
        else if (cmd == "pop") {
            cout << Q.pop() << '\n';
        }
        else if (cmd == "size") {
            cout << Q.returnSize() << '\n';
        }
        else if (cmd == "empty") {
            cout << Q.isEmpty() << '\n';
        }
        else if (cmd == "front") {
            cout << Q.returnFront() << '\n';
        }
        else if (cmd == "back") {
            cout << Q.back() << '\n';
        }
    }
    return 0;
}