#include <iostream>
using namespace std;

int main() {
    int paper_num;
    int paper[100][100] = {0,};
    int result = 0;

    cin >> paper_num;
    int x, y;

    while(paper_num--) {
        cin >> x >> y;
        for(int i = y; i < y + 10; i++) {
            for(int j = x; j < x + 10; j++){
                if((paper[j][i]) == 0) {
                    paper[j][i] = 1;
                }
            }
        }
    }

    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++){
            if((paper[i][j]) == 1) {
                result++;
            }
        }
    }
    cout << result;
    return 0;
}