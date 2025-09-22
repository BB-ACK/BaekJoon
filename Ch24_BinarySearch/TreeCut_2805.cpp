#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cut(vector<int> &tree, const int &need) {
    long long low = 0;
    long long top = tree.back();
    
    int mid;
    int result;

    while(low <= top) {
        mid = (low + top) / 2; // 자르는 높이
        long long sum = 0; // 자른 나무의 총합
        
        // 나무 자르기
        for(int i = 0; i < tree.size(); i++) {
            if(tree[i] - mid > 0)
                sum += tree[i] - mid;
        }

        if(sum >= need) {
            result = mid;
            low = mid + 1;   
        }
        else {
            top = mid - 1;
        }

    }

    return result;
}

int main() {
    // 입력 최적화
    ios::sync_with_stdio(false);
    cin.tie(0);

    int num, need;
    cin >> num >> need;
    vector<int> tree(num); // 나무 배열

    // 나무 길이 입력받기
    for(int i = 0; i < num; i++)
        cin >> tree[i];
    
    // 나무 배열 오름차순 정렬
    sort(tree.begin(), tree.end());
    
    cout << cut(tree, need); 

    return 0;
}