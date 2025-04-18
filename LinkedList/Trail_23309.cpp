#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;
    Node *Llink;
    Node *Rlink;
};

class Station {
private:
    Node *front; // 지하철 시작위치
    Node *top; // 마지막 지하철위치
    int size;

public:
    // 생성자
    Station() {
        this->size = 0;
        this->front = NULL;
        this->top = NULL;
    }

    int isEmpty() {
        return this->size == 0;
    }

    // 초반 기차역 생성
    void insert(int e) {
        Node *node = new Node;
        node->data = e;

        if(this->isEmpty()) {
            node->Llink = node;
            node->Rlink = node;
            this->front = node;
            this->top = node;
        }
        else {
            node->Llink = this->top;
            node->Rlink = this->front;
            
            this->top->Rlink = node;
            this->top = node;
        }

        size++;
    }

    // 다음 역의 번호 출력, 그 사이에 설립
    void BN(int find, int bulid) {
        Node *node = new Node;
        node->data = bulid;

        Node *cursor = this->front;
        while(cursor->data != find) {
            cursor = cursor->Rlink;
        }
        cout << cursor->Rlink->data << '\n';

        // 새로 생긴 노드 설정
        node->Llink = cursor;
        node->Rlink = cursor->Rlink;

        // 기존 노드 값들 변경
        cursor->Rlink->Llink = node;
        cursor->Rlink = node;

        if(cursor == this->top)
            this->top = node;
        
        size++;
    }

    // 이전 역의 번호 출력, 그 사이에 설립
    void BP(int find, int bulid)
    {
        Node *node = new Node;
        node->data = bulid;

        Node *cursor = this->front;
        while(cursor->data != find) {
            cursor = cursor->Rlink;
        }
        cout << cursor->Llink->data << '\n';

        // 새로 생긴 노드 설정
        node->Rlink = cursor;
        node->Llink = cursor->Llink;

        // 기존 노드 값들 변경
        cursor->Llink->Rlink = node;
        cursor->Llink = node;

        if (cursor == this->front)
            this->front = node;

        size++;
    }

    // 다음 역을 폐쇄하고 출력
    void CN(int find) {
        if(this->size < 2)
            return;
        
        Node *cursor = this->front;
        while(cursor->data != find) {
            cursor = cursor->Rlink;
        }
        cursor = cursor->Rlink;
        cout << cursor->data << '\n';

        // 삭제에 따른 기존 노드값들 변경
        cursor->Llink->Rlink = cursor->Rlink;
        cursor->Rlink->Llink = cursor->Llink;

        delete cursor;
        size--;
    }
    
    // 이전 역을 폐쇄하고 출력
    void CP(int find) {
        if(this->size < 2)
            return;

        Node *cursor = this->front;
        while(cursor->data != find) {
            cursor = cursor->Rlink;
        }
        cursor = cursor->Llink;
        cout << cursor->data << '\n';

        // 삭제에 따른 기존 노드값들 변경
        cursor->Llink->Rlink = cursor->Rlink;
        cursor->Rlink->Llink = cursor->Llink;

        delete cursor;
        size--;
    }
};

int main() {
    int built, toBuild;
    cin >> built >> toBuild;

    Station st;

    while(built--) {
        int num; cin >> num;
        st.insert(num);
    }

    while(toBuild--) {
        string fun; cin >> fun;
        if(fun == "BN") {
            int find, bulid;
            cin >> find >> bulid;
            st.BN(find, bulid);
        }
        else if(fun == "BP") {
            int find, bulid;
            cin >> find >> bulid;
            st.BP(find, bulid);
        }
        else if(fun == "CN") {
            int find; cin >> find;
            st.CN(find);
        }
        else if(fun == "CP") {
            int find; cin >> find;
            st.CP(find);
        }
    }
    return 0;
}