#include <iostream>
#include <string>
using namespace std;

struct information{
    int prev;
    int next;
};
information trail[1000000];

class Station {
private:
    int size;
    int top;
    int front;
public:
    // 생성자
    Station() {
        this->size = 0;
        this->top = 0;
        this->front = 0;
    }

    int isEmpty() {
        return this->size == 0;
    } 

    // 기본 건설 세팅 함수
    void insert(int e) {
        if(this->isEmpty()) {
            trail[e].prev = e;
            trail[e].next = e;
            this->top = e;
            this->front = e;
        }
        else {
            trail[e].prev = this->top;
            trail[e].next = this->front;

            trail[this->top].next = e;
            trail[this->front].prev = e;
            this->top = e;
        }

        size++;
    }

    // 다음 역의 고유 번호 출력 및 설립
    void BN(int find, int bulid) {
        cout << trail[find].next << '\n';
        
        // 새로 지을 역의 값 설정
        trail[bulid].prev = find;
        trail[bulid].next = trail[find].next;
        
        // 기존 역들 정보 변경
        trail[trail[find].next].prev = bulid;
        trail[find].next = bulid;

        if(find == this->top)
            this->top = bulid;
        
        size++;
    }

    // 이전 역의 고유 번호 출력 및 설립
    void BP(int find, int bulid) {
        cout << trail[find].prev << '\n';

        // 새로 지을 역의 값 설정
        trail[bulid].next = find;
        trail[bulid].prev = trail[find].prev;

        // 기존 역들 정보 변경
        trail[trail[find].prev].next = bulid;
        trail[find].prev = bulid;

        if(find == this->front)
            this->front = bulid;

        size++;
    }

    // 다음 역을 폐쇄하고 고유번호 출력
    void CN(int find) {
        if (this->size < 2)
            return;

        cout << trail[find].next << '\n';

        if(trail[find].next == this->top) 
            this->top = find;
        
        int oldNext = trail[find].next; // 예제의 6
        int newNext = trail[oldNext].next; // 에제의 3

        trail[find].next = newNext;
        trail[newNext].prev = find;
        size--;

    }

    // 다음 역을 폐쇄하고 고유번호 출력
    void CP(int find) {
        if (this->size < 2)
            return;
        cout << trail[find].prev << '\n';

        if(trail[find].prev == this->front)
            this->front = find;
        
        int oldPrev = trail[find].prev; // 예제의 11;
        int newPrev = trail[oldPrev].prev; // 예제의 5;

        trail[find].prev = newPrev;
        trail[newPrev].next = find;

        size--;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int built, toBuild;
    cin >> built >> toBuild;

    Station st;

    while (built--) {
        int num;
        cin >> num;
        st.insert(num);
    }

    while (toBuild--) {
        string fun;
        cin >> fun;
        if (fun == "BN") {
            int find, bulid;
            cin >> find >> bulid;
            st.BN(find, bulid);
        }
        else if (fun == "BP") {
            int find, bulid;
            cin >> find >> bulid;
            st.BP(find, bulid);
        }
        else if (fun == "CN") {
            int find;
            cin >> find;
            st.CN(find);
        }
        else if (fun == "CP") {
            int find;
            cin >> find;
            st.CP(find);
        }
    }

    return 0;
}