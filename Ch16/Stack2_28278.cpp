#include <iostream>
using namespace std;

class Stack{
private:    
    int *arr; // 동적 배열 할당
    int top;
    int capacity;

public:
    // 생성자
    Stack(int size = 1000000) {
        arr = new int[size];
        capacity = size;
        top = -1;
    }

    // 비어있는지 확인하는 함수
    int isEmpty() {
        if(top == -1)
            return 1;
        else
            return 0;
    }

    // 가득차있는지 확인하는 함수
    int isFull() {
        if(top == capacity - 1)
            return 1;
        
        return 0;
    }

    // push() 함수
    void push(int element) {
        top += 1;
        arr[top] = element; 
    }
    
    // pop()함수
    int pop() {
        if(this->isEmpty())
            return -1;
        else {
            int e = arr[top];
            top -= 1;
            return e;
        }
    }
    
    // 마지막 부분 참조 함수수
    int peek() {
        if(this->isEmpty())
            return -1;
        else
            return arr[top];
    }

    // 원소 갯수 리턴
    int getElementNum() {
        return top + 1;
    }

};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Stack S;
    int test; cin >> test;
     
    while(test--) {
        int def; cin >> def;

        switch (def)
        {
        case 1: // push함수
            int num; cin >> num;
            S.push(num);
            break;
        case 2: // pop함수
            cout << S.pop() << '\n';
            break;
        case 3: // 원소 갯수
            cout << S.getElementNum() << '\n';
            break;
        case 4: // 스택이 비었는지
            cout << S.isEmpty() << '\n';
            break;
        case 5: // 마지막 요소 참조
            cout << S.peek() << '\n';
            break;
        }
    
    }

    return 0;
}