// use C++17 instead of C++20 to avoid MLE

#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode *child[26];
    int cnt = 0;
    TrieNode() {
        for (auto &c : child) c = nullptr;
    }
    ~TrieNode() {
        for (auto &c : child) delete c;
    }
};
class Trie {
public:
    TrieNode *root;
    long long res;
    Trie() {
        root = new TrieNode();
        res = 0;
    }
    ~Trie() {
        delete root;
    }
    void insert(string& s) {
        TrieNode *curr = root;
        for (char c : s) {
            if (curr -> child[c - 'a'] == nullptr) curr -> child[c - 'a'] = new TrieNode();
            curr = curr -> child[c - 'a'];
            curr -> cnt++;
        }
    }
    void calc(string& s) {
        if (root -> child[s[0] - 'a'] != nullptr) dfs(root -> child[s[0] - 'a'], s, 0);
    }
    int dfs(TrieNode *curr, string& s, int depth) {
        int thing = 0;
        if (depth + 1 < s.length() && curr -> child[s[depth + 1] - 'a'] != nullptr) thing = dfs(curr -> child[s[depth + 1] - 'a'], s, depth + 1);
        res += 2LL * (curr -> cnt - thing) * (depth + 1);
        return curr -> cnt;
    }
};
int n;
string s[1000000];
long long ans = 0;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n;
    Trie trie = Trie();
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        ans += s[i].length() * 2LL * n;
        trie.insert(s[i]);
    }
    for (int i = 0; i < n; i++) {
        reverse(s[i].begin(), s[i].end());
        trie.calc(s[i]);
    }
    cout << ans - trie.res << "\n";
    return 0;
}
 
/*
tips:
- look out for int overflow and array out of bounds
- don't get stuck debugging a wrong solution, take time to think of a new one instead of spamming submissions
- make sure stuestion was read correctly
- for certain problems, solve a few cases by hand and try to make observations
- if behind, stop looking at leaderboard and focus on solving
*/
