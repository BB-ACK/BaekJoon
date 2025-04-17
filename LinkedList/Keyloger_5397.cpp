#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* Left;
    Node* Right;
};

class DoublieLinkedList {
public:
    Node* front; // 제일 앞 요소를 가리킴
    Node* cursor;
    int size;
    
    // 생성자
    DoublieLinkedList() {
        this->size = 0;
        
        Node *first = new Node;
        first->Left = NULL;
        first->Right = NULL;
        this->front = first;
        this->cursor = first;
    }

    int isEmpty() {
        return this->front->Right == NULL;
    }

    // <의 역할
    void moveLeft() {
        if(this->cursor == this->front)
            return;
        this->cursor = this->cursor->Left;
    }

    // >의 역할
    void moveRight() {
        if(this->isEmpty() || this->cursor->Right == NULL)
            return;
        this->cursor = this->cursor->Right;
    }

    // -의 역할
    void backSpace() {
        if(this->cursor == this->front)
            return;

        Node *toDelete = this->cursor; // 메모리 할당 해제를 위해해
        // 제일 탑이라면
        if(this->cursor->Right == NULL) {
            this->cursor->Left->Right = NULL; // 뒷 요소의 오른쪽 NULL
        }
        else {
            this->cursor->Left->Right = this->cursor->Right;
            this->cursor->Right->Left = this->cursor->Left;
        }
        
        this->cursor = this->cursor->Left; // 커서 위치 변경
        delete toDelete;
        size--;
    }

    // 비밀번호의 해당
    void insert(char e) {
        Node *node = new Node;
        node->data = e;
        node->Left = this->cursor;

        if(this->cursor->Right == NULL) {
            node->Right = NULL;
        }
        else {
            node->Right = this->cursor->Right;
            this->cursor->Right->Left = node; 
        }

        this->cursor->Right = node;
        this->cursor = node;

        size++;
    }

};

int main() {
    int num; cin >> num;
    
    while(num--) {
        DoublieLinkedList DLL;
        string passWord; cin >> passWord;

        for(char idx : passWord) {
            switch (idx) {
            case '<':
                DLL.moveLeft();
                break;
            case '>':
                DLL.moveRight();
                break;
            case '-':
                DLL.backSpace();
                break;
            default:
                DLL.insert(idx);
                break;
            }
        }

        Node *tmp = DLL.front->Right;
        for(int i = 0; i < DLL.size; i++) {
            cout << tmp->data;
            tmp = tmp->Right;
        }
        cout << endl;
    }


    return 0;
}