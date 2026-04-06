/* 개선점
1. 두 개의 보드(8x8)을 쓸 필요없이 %2를 활용해서 메모리 절약하기
2. 대칭성 이용하기 - 흰보드에서 12개 틀렸다면, 검은 보드에서는 64 - 12 = 52개가 틀림
3. 이 문제는 50 x 50의 한계가 있지만, 엄청 크다면?
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 재색칠할 최솟값 반환 함수
int recolorBoard(vector<string> &board, vector<string> &white, vector<string> &black) {
    int row = board.size();
    int col = board[0].length();

    int min = 2500;
    
    // row값 탐색범위
    for(int i = 0; i <= row-8; i++) {
        // col값 탐색 범위
        for(int j = 0; j <= col-8; j++) {
            // 제한된 범위 내에서 보드와 완성판 비교
            int wRecolor = 0;
            int bRecolor = 0;

            for(int r = 0; r < 8; r++) {
                for(int c = 0; c < 8; c++) {
                    if(board[i+r][j+c] != white[r][c]) wRecolor++;
                    if(board[i+r][j+c] != black[r][c]) bRecolor++;
                }
            }
            
            // 최솟값 갱신
            if(wRecolor < min) min = wRecolor;
            if(bRecolor < min) min = bRecolor;
        }
    }

    return min;
}

int main() {
    // 입력 최적화
    ios::sync_with_stdio(false);
    cin.tie(0);

    // 입력값 
    int row, col; cin >> row >> col;

    // 화이트, 블랙 보드 생성 
    vector<string> white;
    vector<string> black;

    // 완성형 보드 채우기
    for(int i = 0; i < 8; i++) {
        string boardA = "WBWBWBWB";
        string boardB = "BWBWBWBW";

        if(i % 2 == 0) {
            white.push_back(boardA);
            black.push_back(boardB);
        }
        else {
            white.push_back(boardB);
            black.push_back(boardA);
        }
    }

    // 예제 보드 입력
    vector<string> board;
    for(int i = 0; i < row; i++) {
        string cur; cin >> cur;
        board.push_back(cur);
    }

    cout << recolorBoard(board, white, black);

    return 0;
}