#include <iostream>
#include <vector>
using namespace std;

int capacity = 100003; // 해쉬를 이용하기 위힌 

struct Node {
    int data;
    int count; // 등장 횟수를 알기 위한 변수수
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

        Node *node = this->arr[bucket];

        while(node != nullptr) {
            if(node->data == e) { // data값이 같은 노드가 존재하다면 count++하고 리턴
                node->count++;
                return;
            }
            node = node->next; // 다른 노드를 검사
        }

        // 존재하지 않는 값을 가진 노드라면 새로 생성
        Node *newNode = new Node{e, 1, this->arr[bucket]};
        this->arr[bucket] = newNode;
    }

    int search(int e) {
        int bucket = (e % capacity + capacity) % capacity;
        Node *node = this->arr[bucket];

        while(node != nullptr) {
            if(node->data == e) {
                return node->count;
            }
            node = node->next;
        }
        
        // 못 찾았다면 0
        return 0;
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