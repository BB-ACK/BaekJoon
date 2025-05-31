#include <iostream>
#include <vector>
using namespace std;

int capacity = 500001; // 해쉬를 이용하기 위힌 

struct Node {
    int data;
    Node *next;
};

class Chaining {
private:
    vector <Node *> arr;
public:
    // 생성자 -> arr의 사이즈 초기화
    Chaining() {
        this->arr.resize(capacity, nullptr);
    }

    void insert(int e) {
        int bucket = (e % capacity + capacity) % capacity; // 음수를 양수로 만들기 위한 hash

        Node *node = new Node{e, this->arr[bucket]};
        this->arr[bucket] = node;
    }

    int search(int e) {
        int count = 0;
        int bucket = (e % capacity + capacity) % capacity;
        Node *node = this->arr[bucket];

        while(node != nullptr) {
            if(node->data == e) 
                count++;
            node = node->next;
        }

        return count;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num; cin >> num;
    Chaining ch;

    int e;
    while(num--) {
        cin >> e;
        ch.insert(e);
    }

    cin >> num;
    while(num--) {
        cin >> e;
        cout << ch.search(e) << " ";
    }

    return 0;
}