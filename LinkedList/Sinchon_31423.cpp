#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    string name;
    Node *next;
    Node *rear; // 연결된 마지막 노드 표시시
};

class University {
private:
    vector<Node*> arr;

public:
    void push(string e) {
        Node *node = new Node();
        node->name = e;
        node->next = NULL;
        node->rear = NULL;
        arr.push_back(node);
    }

    void connect(int a, int b) {
        Node *tmp = this->arr[a]; // 연결을 위한 임시노드
        if(tmp->rear == NULL && this->arr[b]->next == NULL) { // 노드의 크기가 둘 다 1인 경우
            tmp->next = this->arr[b];
            tmp->rear = this->arr[b];
        }
        else if(tmp->next == NULL && this->arr[b]->next != NULL){ // a노드는 크기가 1이고 b노드가 큰 경우
            tmp->next = this->arr[b];
            tmp->rear = this->arr[b]->rear;
        }
        else if (tmp->next != NULL && this->arr[b]->next == NULL) { // a노드는 크기가 크고 b노드가 1인 경우
            tmp->rear->next = this->arr[b];
            tmp->rear = this->arr[b];
        }
        else if (tmp->next != NULL && this->arr[b]->next != NULL) { // 두 노드의 크기가 큰 경우
            tmp->rear->next = this->arr[b];
            tmp->rear = this->arr[b]->rear;
        }
    }

    void print(int idx) {
        Node *node = this->arr[idx];
        do {
            cout << node->name;
            node = node->next;
        }
        while(node != NULL);

    }   

    ~University() {
        for (Node *node : arr) {
            delete node; // 동적 메모리 해제
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int num; cin >> num;
    University univ;

    // 예제의 대학이름들 입력
    for(int i = 0; i < num; i++) {
        string name; cin >> name;
        univ.push(name);
    }

    int startidx;
    // 예제의 숫자들
    for(int i = 0; i < num-1; i++) {
        int first, second;
        cin >> first >> second;

        univ.connect(first-1, second-1);
        
        if(i == num - 2)
            startidx = first;
    }

    univ.print(startidx-1);

    return 0;
}