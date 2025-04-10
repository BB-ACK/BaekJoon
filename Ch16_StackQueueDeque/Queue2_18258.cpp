#include <iostream>
#include <string>
using namespace std;

class Queue {
private:
    int capacity;
    int front;
    int back;
    int *arr;

public:
    // 생성자
    Queue(int size = 2000000) {
        capacity = size;
        front = -1;
        back = -1;
        arr = new int[capacity];
    }

    // 비어있는지 확인하는 함수
    int empty() {
        if(this->front == this->back)
            return 1;

        return 0;
    }

    // 정수를 대입하는 함수
    void push(int element) {
        this->back++;
        this->arr[this->back] = element;
    }

    // 앞에 있는 요소를 빼는 함수
    int pop() {
        if(this->empty())
            return -1;
        int tmp = this->arr[this->front + 1];
        this->front++;
        return tmp;
    }
    
    // 들어있는 정수의 개수를 리턴
    int size() {
        return this->back - this->front;
    }

    // 가장 앞에 있는 정수를 출력
    int frontFunc() {
        if(this->empty())
            return -1;
        return this->arr[this->front + 1];
    }

    // 가장 뒤에 있는 정수 출력
    int backFunc() {
        if(this->empty())
            return -1;
        return this->arr[this->back];
    }

};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    Queue Q;
    int constructions; cin >> constructions;
    string str;
    
    while (constructions--) {
        cin >> str;
        
        if(str == "push") {
            int num; cin >> num;
            Q.push(num);
        } 
        else if(str == "pop") {
            cout << Q.pop() << '\n';    
        }
        else if(str == "size") {
            cout << Q.size() << '\n';
        }
        else if(str == "empty") {
            cout << Q.empty() << "\n";
        }
        else if(str == "front") {
            cout << Q.frontFunc() << '\n';
        }
        else if(str == "back") {
            cout << Q.backFunc() << '\n';
        }
  
    }
    
    return 0;
}