#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<long long, long long> memo;

long long dfs(const string &word, int idx, long long node) {
    if (idx == word.size()) return node;

    // 벡터를 사용한 메모이제이션 적용
    if (memo[idx].count(node)) return memo[idx][node];

    if (word[idx] == 'L') return memo[idx][node] = dfs(word, idx + 1, 2 * node);
    if (word[idx] == 'R') return memo[idx][node] = dfs(word, idx + 1, 2 * node + 1);
    if (word[idx] == 'P') return memo[idx][node] = dfs(word, idx + 1, node);

    // '*'의 경우 모든 경우를 고려
    return memo[idx][node] = dfs(word, idx + 1, 2 * node) +
                             dfs(word, idx + 1, 2 * node + 1) +
                             dfs(word, idx + 1, node);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string word;
    cin >> word;

    memo.resize(word.size()); // 각 idx마다 unordered_map을 사용

    cout << dfs(word, 0, 1) << "\n";

    return 0;
}
