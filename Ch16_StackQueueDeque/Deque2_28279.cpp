#include <iostream>
using namespace std;

class Deque {
private:
    int capacity;
    int top;
    int *arr;

public:
    // 생성자
    Deque(int capacity = 1000000) {
        this->capacity = capacity;
        this->top = -1;
        this->arr = new int[this->capacity];
    }

    // 비어있는지 확인
    int empty() {
        if(this->top == -1)
            return 1;
        return 0;
    }

    // 원소의 갯수 리턴
    int size() {
        return this->top + 1;
    }

    // 맨 앞에 대입
    void pushFront(int e) {
        // 뒤로 한 칸씩 밀기
        for(int i = this->size(); i > 0; i--) {
            this->arr[i] = this->arr[i-1];
        }
        this->top++;
        this->arr[0] = e;
    }

    // 맨 뒤에 대입
    void pushBack(int e) {
        this->top++;
        this->arr[this->top] = e;
    }


    // 맨 앞에 요소 빼기
    int popFront() {
        if(this->empty()) 
            return -1;
        
        int tmp = this->arr[0];
        // 배열 정리
        for(int i = 0; i < this->size(); i++) {
            this->arr[i] = this->arr[i+1];
        }
        this->top--;

        return tmp;
    }

    // 맨 뒤에 요소 빼기
    int popBack() {
        if(this->empty())
            return -1;
        
        int tmp = this->arr[this->top];
        // this->arr[this->top] = NULL;
        this->top--;

        return tmp;
    }

    // 맨 앞에 요소 참조
    int front() {
        if(this->empty())
            return -1;
        
        return this->arr[0];
    }

    // 맨 뒤에 요소 참조
    int back() {
        if(this->empty()) 
            return -1;
        
        return this->arr[this->top];
    }

    
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Deque Dq;
    int test; cin >> test;

    while(test--) {
        int instructions; cin >> instructions;
        int num;
        switch (instructions) {
        case 1:
            cin >> num;
            Dq.pushFront(num);
            break;
        case 2:
            cin >> num;
            Dq.pushBack(num);
            break;
        case 3:
            cout << Dq.popFront() << '\n';
            break;
        case 4:
            cout << Dq.popBack() << '\n';
            break;
        case 5:
            cout << Dq.size() << '\n';
            break;
        case 6:
            cout << Dq.empty() << '\n';
            break;
        case 7:
            cout << Dq.front() << '\n';
            break;
        case 8:
            cout << Dq.back() << '\n';
        }
    }

    cout << endl;

    return 0;
}