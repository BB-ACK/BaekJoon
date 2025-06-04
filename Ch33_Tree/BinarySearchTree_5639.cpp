#include <iostream>
using namespace std;

struct TreeNode {
    TreeNode *left;
    TreeNode *right;
    int key;
};


class BST {
private:
public:
    TreeNode *root;
    
    // 생성자
    BST() {
        this->root = nullptr;
    }

    void insert(TreeNode *&root, int key) {
        // 처음 키 값이 들어온 경우
        if(root == nullptr) {
            root = new TreeNode{nullptr, nullptr, key};
            return;
        }

        // 키값에 따른 포지션 위치
        if(key < root->key) {
            this->insert(root->left, key);
        }
        else if(key > root->key) {
            this->insert(root->right, key);
        }
        else {}

    }

    void postOrder(TreeNode *node) {
        if(node != nullptr) {
            postOrder(node->left);
            postOrder(node->right);
            cout << node->key << '\n';
        }
    }
};

int main() {
    BST bst;

    int num;
    while(cin >> num) {
        if(cin.eof())
            break;

        bst.insert(bst.root, num);
    }

    bst.postOrder(bst.root);

    return 0;
}