#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data; // 데이터 값
    Node* Llink; // 앞쪽 노드 요소
    Node* Rlink; // 뒤쪽 노드 요소
};

class DoubleLinkedList{
public:
    Node* cursor; // 커서의 역할
    Node* front; // 출력문을 위한 빈노드
    // 생성자
    DoubleLinkedList() {
        this->cursor = NULL; 
        
        Node *first = new Node;
        first->Llink = NULL;
        first->Rlink = NULL;
        this->front = first;

    }

    int isEmpty() {
        return this->front->Rlink == NULL;
    }

    // P에 대응 - 마지막에 요소를 넣어줌
    void insert(char e) {
        Node *node = new Node;
        node->data = e;
        
        if(this->isEmpty()) {
            node->Llink = this->front; 
            node->Rlink = NULL;
            this->front->Rlink = node;
        }
        
        // 현재 커서가 제일 위에 있는 경우
        else if(this->cursor->Rlink == NULL) {
            // 새로운 노드 설정
            node->Llink = this->cursor;
            node->Rlink = NULL;
            // 원래 노드 값들 변경
            this->cursor->Rlink = node;
        }
        else {
            node->Llink = this->cursor;
            node->Rlink = this->cursor->Rlink;

            this->cursor->Rlink->Llink = node;
            this->cursor->Rlink = node;
        }

        this->cursor = node; // 제일 위 노드를 새 노드로 교체
    }

    // L에 대응 - 커서를 왼쪽으로 옮김
    void moveLeft() {
        // 맨 앞이면 무시
        if(this->cursor->Llink == NULL)
            return;
        this->cursor = this->cursor->Llink; // 왼쪽으로 옮김
    }

    // D에 대응 - 커서를 오른쪽으로 옮김
    void moveRight() {
        // 맨 끝이면 무시
        if(this->cursor->Rlink == NULL) 
            return;
        this->cursor = this->cursor->Rlink; // 오른쪽으로 옮김
    }

    // B에 대응 - 현재 가리키는 커서 원소 삭제
    void backSpace() {
        // 맨 앞이면 무시
        if(this->cursor == this->front)
            return;
        
        Node *prev = this->cursor->Llink; // 커서 왼쪽 노드를 가리킴
        if(this->cursor->Rlink == NULL) { // 커서가 맨위에 있는 경우
            prev->Rlink = NULL;
        }
        else {
            prev->Rlink = this->cursor->Rlink;
            this->cursor->Rlink->Llink = prev;
        }
        
        this->cursor = prev;
    }

};

int main() {
    DoubleLinkedList DLL;
    string element; cin >> element;

    for(char idx : element) {
        DLL.insert(idx);
    }

    int num; cin >> num;
    while(num--) {
        char instructions; cin >> instructions;

        switch (instructions) {
        case 'L':
            DLL.moveLeft();
            break;
        case 'D':
            DLL.moveRight();
            break;
        case 'B':
            DLL.backSpace();
            break;
        case 'P':
            char e; cin >> e;
            DLL.insert(e);
            break;
        }
    }

    Node *tmp = DLL.front->Rlink;
    while(tmp != NULL) {
        cout << tmp->data;
        if(tmp->Rlink != NULL)
            tmp = tmp->Rlink; // 다음 노드로 변경
        
        else if(tmp->Rlink == NULL){
            break;
        }
    }

    cout << endl;

    return 0;
}