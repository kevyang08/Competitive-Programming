#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
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
    TrieNode *root;
public:
    Trie() {
        root = new TrieNode();
    }
    ~Trie() {
        delete root;
    }
    void insert(string& word) {
        TrieNode *curr = root;
        for (int i = 0; i < word.length(); i++) {
            if (curr -> child[word[i] - 'a'] == nullptr) curr -> child[word[i] - 'a'] = new TrieNode();
            curr = curr -> child[word[i] - 'a'];
            curr -> cnt++;
        }
    }
    int getMin(string& prefix) {
        TrieNode *curr = root -> child[prefix[0] - 'a'];
        int c = 1;
        for (int i = 1; i < prefix.length(); i++) {
            if (curr -> cnt == 1) break;
            curr = curr -> child[prefix[i] - 'a'];
            c++;
        }
        return c;
    }
};
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t, n;
    cin >> t;
    for (int bruh = 1; bruh <= t; bruh++) {
        Trie trie = Trie();
        long long ans = 0;
        string s;
        cin >> n;
        while (n--) {
            cin >> s;
            trie.insert(s);
            ans += trie.getMin(s);
        }
        cout << "Case #" << bruh << ": " << ans << "\n";
    }
    return 0;
}
