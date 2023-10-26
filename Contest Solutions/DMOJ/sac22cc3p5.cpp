#include <bits/stdc++.h>
using namespace std;

const int R1 = 127, M1 = 1000000007, R2 = 257, M2 = 998244353;

int n, m;
long long h1[501], h2[501], p1[501], p2[501];
string s, t;
unordered_set<long long> st1, st2;
long long hsh1(int l, int r) {
    return (h1[r] - h1[l] * p1[r - l]%M1 + M1)%M1;
}
long long hsh2(int l, int r) {
    return (h2[r] - h2[l] * p2[r - l]%M2 + M2)%M2;
}
int check(string &t) {
    unordered_set<long long> ans;
    int cnt = 0;
    for (int i = 1; i <= t.length(); i++) {
        h1[i] = (h1[i - 1] * R1 + t[i - 1] + 32 * (t[i - 1] >= 'A' && t[i - 1] <= 'Z'))%M1;
        h2[i] = (h2[i - 1] * R2 + t[i - 1] + 32 * (t[i - 1] >= 'A' && t[i - 1] <= 'Z'))%M2;
        for (int j = max(i - 25, 0); j < i; j++) {
            long long tmp1 = hsh1(j, i), tmp2 = hsh2(j, i);
            if (st1.find(tmp1) != st1.end() && st2.find(tmp2) != st2.end()) {
                if (ans.find(tmp1) == ans.end() || ans.find(tmp2) == ans.end()) cnt++;
                ans.insert(tmp1);
                ans.insert(tmp2);
            }
        }
    }
    return cnt;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> m;
    p1[0] = p2[0] = 1;
    for (int i = 1; i <= 500; i++) p1[i] = (p1[i - 1] * R1)%M1;
    for (int i = 1; i <= 500; i++) p2[i] = (p2[i - 1] * R2)%M2;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 1; j <= s.length(); j++) h1[j] = (h1[j - 1] * R1 + s[j - 1] + 32 * (s[j - 1] >= 'A' && s[j - 1] <= 'Z'))%M1;
        st1.insert(h1[s.length()]);
        for (int j = 1; j <= s.length(); j++) h2[j] = (h2[j - 1] * R2 + s[j - 1] + 32 * (s[j - 1] >= 'A' && s[j - 1] <= 'Z'))%M2;
        st2.insert(h2[s.length()]);
    }
    while (m--) {
        cin >> t;
        cout << check(t) << "\n";
    }
    return 0;
}
