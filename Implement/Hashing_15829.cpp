#include <iostream>
#include <string>
using namespace std;

int hashFn(string word) {
    int r = 31;
    long long r_pow = 1;
    long long sum = 0;

    for(int i = 0; i < word.length(); i++) {
        int tmp = word[i] - 'a' + 1;
        sum = (sum + (tmp * r_pow)) % 1234567891; // 매순간 나머지를 곱해줌

        // 다음 항을 위한 r제곱
        r_pow = (r_pow * r) % 1234567891;
    }

    return sum;
}


int main() {
    int len; cin >> len;
    string word; cin >> word;

    cout << hashFn(word);

    return 0;
}