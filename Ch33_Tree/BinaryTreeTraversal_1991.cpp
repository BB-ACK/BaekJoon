#include <iostream>
using namespace std;

struct Node {
    char data;
    Node *left;
    Node *right;
};

void preOrder(Node *node) {
    if(node != nullptr) {
        cout << node->data;
        preOrder(node->left);
        preOrder(node->right);
    }
}

void inOrder(Node *node) {
    if(node != nullptr) {
        inOrder(node->left);
        cout << node->data;
        inOrder(node->right);
    }
}

void postOrder(Node *node) {
    if(node != nullptr) {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data;
    }
}

int main() {
    int num; cin >> num;
    Node *node = new Node[num+1];

    for(int i = 1; i <= num; i++) {
        char cur; cin >> cur;
        Node *root = &node[cur - '@'];
        root->data = cur;

        // 왼쪽 노드 연산
        char left; cin >> left;
        if(left != '.') 
            root->left = &node[left - '@'];
        else
            root->left = nullptr;
    

        // 오른쪽 노드 연산
        char right; cin >> right;
        if(right != '.')
            root->right = &node[right - '@'];
        else
            root->right = nullptr;
    }

    preOrder(&node[1]);
    cout << '\n';

    inOrder(&node[1]);
    cout << '\n';

    postOrder(&node[1]);
    
    return 0;
}