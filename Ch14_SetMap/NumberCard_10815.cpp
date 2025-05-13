#include <iostream>
#include <vector>
using namespace std;

int capacity = 500001;

struct Node {
    int data;
    Node *next;
};

class Chaining {
private:
    vector<Node *> arr;

public:
    // 생성자
    Chaining() {
        arr.resize(capacity, nullptr);
    }

    void insert(int e) {
        int idx = ((e % capacity) + capacity) % capacity;

        Node *node = new Node{e, this->arr[idx]};
        this->arr[idx] = node;
    }

    void search(int e) {
        int idx = ((e % capacity) + capacity) % capacity;

        Node *node = this->arr[idx];
        if (node == nullptr) {
            cout << 0 << '\n';
            return;
        }

        while (node != nullptr) {
            if (node->data == e) {
                cout << 1 << '\n';
                return;
            }

            node = node->next;
        }

        cout << 0 << '\n';
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    Chaining Ch;
    int have;
    cin >> have;
    while (have--) {
        int e;
        cin >> e;
        Ch.insert(e);
    }

    int find;
    cin >> find;
    while (find--) {
        int e;
        cin >> e;
        Ch.search(e);
    }

    return 0;
}
