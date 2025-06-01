#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int capacity = 500001;

// 문자열 해싱을 위한 함수 
unsigned long djb2(string name) {
    unsigned long hash = 5381; // 이 값이 좋다고 함

    for(char c : name) {
        hash = (hash << 5) + hash + c;
    }

    return hash;
} 

struct Node {
    string data;
    Node *next;
};

class Chaining {
private:
    vector<Node*> arr;
    int count; // 듣도 보도 못한 사람의 수

public:
    // 생성자
    Chaining() {
        this->arr.resize(capacity, nullptr);
        this->count = 0;
    }

    void insert(string name) {
        int bucket = djb2(name) % capacity;

        Node *node = new Node{name, this->arr[bucket]};
        this->arr[bucket] = node;
    }

    string search(string name) {
        int bucket = djb2(name) % capacity;
        
        Node *node = this->arr[bucket];

        while(node != nullptr) {
            if(node->data == name) {
                count++;
                return node->data;
            }
            node = node->next;
        }

        return "";
    }

    int getCount() {
        return this->count;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Chaining ch;
    vector<string> result;

    int insert, search;
    cin >> insert >> search;

    string name;
    while(insert--) {
        cin >> name;
        ch.insert(name);
    }

    while(search--) {
        cin >> name;
        string tmp = ch.search(name);
        
        if(tmp != "")
            result.push_back(tmp);
    }

    sort(result.begin(), result.end()); // 사전순 정렬

    cout << ch.getCount() << '\n';
    for(int i = 0; i < result.size(); i++)
        cout << result[i] << '\n';

    return 0;
}