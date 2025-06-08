#include <iostream>
#include <vector>
#include <deque>
using namespace std;

// 노드의 구조
struct Node {
    int data;
    vector<Node*> child;
};

class Tree { 
private:
    Node *root;
    vector<Node*> arr; // 노드들 배열

public:
    // 생성자
    Tree(int num) {
        this->root = nullptr;
        
        // 노드 배열 초기화
        for(int i = 0; i < num; i++) {
            this->arr.push_back(new Node);
        }
    }

    // 트리를 구성하는 함수
    void insert(int idx, int parent) {
        this->arr[idx]->data = idx; // 데이터 값 초기화

        if(parent == -1) {
            this->root = *&this->arr[idx]; // 자신이 루트 노드인 경우
        }
        else {
            this->arr[parent]->child.push_back(this->arr[idx]); // 부모 노드에 자기 자신 추가
        }
    }

    void remove(int idx) {
        // 루트 노드 삭제시
        if(idx == this->root->data) {
            this->root = nullptr;
            return;
        }
        
        // BFS를 통한 탐색
        deque<Node*> dq;
        dq.push_back(this->root);

        while(!dq.empty()) {
            Node &cur = *dq.front();
            dq.pop_front();

            for(auto it = cur.child.begin(); it != cur.child.end(); it++) {
                if((*it)->data == idx) {
                    cur.child.erase(it);
                    break;
                }
                else {
                    dq.push_back(*it);
                }
            }
        }
    }

    // 리프노드의 갯수를 반환
    int countLeaf(Node *node) {
        
        if(node == nullptr)
            return 0;
        else if(node->child.size() == 0)
            return 1;
        else {
            int sum = 0;
            for(int i = 0; i < node->child.size(); i++) {
                sum += countLeaf(node->child[i]);
            }
            return sum;
        }

    }

    Node* getRoot() {
        return this->root;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int nodeNum; cin >> nodeNum;
    Tree tree(nodeNum);

    // 입력문
    for(int i = 0; i < nodeNum; i++) {
        int parent; cin >> parent;
        tree.insert(i, parent);
    }

    int idx; cin >> idx;
    tree.remove(idx);

    int result = tree.countLeaf(tree.getRoot());
    cout << result;
    
    return 0;
}