#include <iostream>
#include <deque>
using namespace std;

class MaxHeap
{
private:
    deque<int> tree;
    int size;

public:
    // 생성자
    MaxHeap()
    {
        this->tree.push_back(NULL); // 0번 인덱스를 사용하지 않기 위함
        this->size = 0;
    }

    int isEmtpy()
    {
        return this->size == 0;
    }

    // 원소 삽입 함수
    void insert(int e)
    {
        this->size++;
        this->tree.push_back(e);
        this->upHeap();
    }

    // 삽입된 원소에 위치를 찾는 함수
    void upHeap()
    {
        int index = this->size;
        int key = this->tree[index];

        // 루트 노드가 아니고 부모 노드보다 크다면
        while (index != 1 && key > this->tree[index / 2])
        {
            this->tree[index] = this->tree[index / 2]; // 부모노드와 교체
            index /= 2;
        }

        this->tree[index] = key;
    }

    // 원소 삭제 함수
    int remove()
    {
        if (this->isEmtpy())
            return 0;

        int key = this->tree[1];
        this->tree[1] = this->tree.back();
        this->tree.pop_back();
        // 여기까지 맨 앞요소와 바꾸고 버림

        this->size--;
        this->downHeap();

        return key;
    }

    void downHeap()
    {
        int key = this->tree[1];
        int pi = 1;
        int ci = 2; // 기본적으로 자식 노드는 왼쪽 - 2i

        while (ci <= this->size)
        { // 자식노드가 있어야함
            if (ci < this->size && this->tree[ci + 1] > this->tree[ci])
            {         // 형제 노드가 존재하고 오른쪽 노드가 큰경우
                ci++; // 오른쪽 노드로 변경
            }

            // 자신이 더 크면 내려갈 필요가 없음
            if (key > this->tree[ci])
                break;

            this->tree[pi] = this->tree[ci];
            pi = ci; // 부모노드가 자식 노드로 내려감
            ci *= 2; // 바뀐 부모 노드의 값에 맞춰 자식 노드 인덱스 값 변경
        }

        this->tree[pi] = key;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    cin >> test;
    MaxHeap H;

    while (test--)
    {
        int cmd;
        cin >> cmd;

        if (cmd == 0)
            cout << H.remove() << '\n';
        else
        {
            H.insert(cmd);
        }
    }

    return 0;
}