// 이진탐색트리를 이용한 탐색색
#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

class BST {
public:
    Node *root = new Node();

    // 생성자 
    BST() {
        this->root = nullptr;
    }

    // 예제 4 1 5 2 3를 대입하는 경우
    void insert(Node *&node, int e) {
        if(node == nullptr) {
            node = new Node{e, nullptr, nullptr};
            return;
        }

        if(e < node->data) // 값이 작으면 왼쪽
            this->insert(node->left, e);
        else if(e > node->data) // 값이 크면 오른쪽
            this->insert(node->right, e);
    }

    // 탐색 함수 
    int search(Node *node,int e) {
        while(node != nullptr) {
            if(node->data == e)
                return 1;

            if(e < node->data)
                node = node->left;
            else
                node = node->right;
        }

        return 0;
    }


};

int main() {
    BST bst;
    int num; cin >> num;
    int e;

    while(num--) {
        cin >> e;
        bst.insert(bst.root ,e);
    }

    cin >> num;
    while(num--) {
        cin >> e;
        cout << bst.search(bst.root, e) << '\n';
    }

    return 0;
}