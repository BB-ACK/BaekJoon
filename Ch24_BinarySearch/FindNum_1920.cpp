// 이진탐색트리를 이용한 탐색
#include <iostream>
using namespace std;

struct Node {
    int data;
    int height;
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

    // 높이를 얻는 함수
    int getHeight(Node *node) {
        if(node == nullptr)
            return 0;

        return node->height;
    }

    // 노드의 균형을 계산 -> 양족 서브 트리의 높이차
    int calBalance(Node *node) {
        return this->getHeight(node->left) - this->getHeight(node->right);
    }

    void updateHeight(Node *node) {
        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    }

    // 왼쪽 자식의 왼쪽 서브트리에 대입해 균형이 무너짐 
    Node *rotateLL(Node *node) {
        Node *lNode = node->left;
        node->left = lNode->right;
        lNode->right = node;

        updateHeight(node);
        updateHeight(lNode);
        
        return lNode;
    }

    // 오른쪽 자식의 오른쪽 서브트리에 대입해 균형이 무너짐
    Node *rotateRR(Node *node) {
        Node *rNode = node->right;
        node->right = rNode->left;
        rNode->left = node;

        updateHeight(node);
        updateHeight(rNode);
        
        return rNode;
    }

    // 왼쪽 자식의 오른쪽 서브트리에 대입해 균형이 무너짐 -> 자식부터 RR - LL 순서로
    Node *rotateLR(Node *node) { 
        node->left = this->rotateRR(node->left);

        return this->rotateLL(node);
    }

    // 오른쪽 자식의 왼쪽 서브트리에 대입해 균형이 무너짐 -> 자식부터 LL - RR 순서로
    Node *rotateRL(Node *node) {
        node->right = this->rotateLL(node->right);

        return this->rotateRR(node);
    }
    // 예제 4 1 5 2 3를 대입하는 경우
    void insert(Node *&node, int e) {
        if(node == nullptr) {
            node = new Node{e, 1, nullptr, nullptr};
            return;
        }

        if(e < node->data) // 값이 작으면 왼쪽
            this->insert(node->left, e);
        else if(e > node->data) // 값이 크면 오른쪽
            this->insert(node->right, e);
        
        updateHeight(node); // 삽입 후 높이 계산산

        // 원소 대입 후 균형 계산
        int bf = this->calBalance(node);

        if(bf > 1) { // 왼쪽에서 균형이 무너짐
            if(e < node->left->data) // LL의 경우
                node = this->rotateLL(node);
            else  
                node = this->rotateLR(node);
        }
        else if(bf < -1) { // 오른쪽에서 균형이 무너짐
            if(e > node->right->data) // RR의 경우 
                node = this->rotateRR(node);
            else 
                node = this->rotateRL(node);
        }
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
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

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