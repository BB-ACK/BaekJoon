#include <iostream>
#include <vector>
using namespace std;

class Deque {
private:
    int capacity;
    int start;
    int top;
    int *arr;

public:
    // 생성자
    Deque(int capacity = 2000000) {
        this->capacity = capacity;
        this->start = 1000000; // 100만번째 부터 배열을 시작함
        this->top = 1000000;
        this->arr = new int[this->capacity];
    }

    // 6: 비어있는지 확인
    int empty() {
        if(this->top == this->start)
            return 1;
        return 0;
    }

    // 5: 원소의 갯수 리턴
    int size() {
        return this->top - this->start;
    }

    // 1: 맨 앞에 대입
    void pushFront(int e) {
        this->start--;
        this->arr[this->start] = e;

    }

    // 2: 맨 뒤에 대입
    void pushBack(int e) {
        this->arr[this->top] = e;
        this->top++;
    }


    // 3: 맨 앞에 요소 빼기
    int popFront() {
        if(this->empty()) 
            return -1;
        
        int tmp = this->arr[this->start];
        this->start++;
            
        return tmp;
    }

    // 4: 맨 뒤에 요소 빼기
    int popBack() {
        if(this->empty())
            return -1;
        
        this->top--;
        int tmp = this->arr[this->top];

        return tmp;
    }

    // 7: 맨 앞에 요소 참조
    int front() {
        if(this->empty())
            return -1;
        
        return this->arr[this->start];
    }

    // 8: 맨 뒤에 요소 참조
    int back() {
        if(this->empty()) 
            return -1;
        
        return this->arr[this->top - 1];
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
            break;
        }
    }

    cout << endl;

    return 0;
}