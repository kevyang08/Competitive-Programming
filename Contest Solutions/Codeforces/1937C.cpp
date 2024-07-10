#include <bits/stdc++.h>
using namespace std;

/*
- can find max in n/2 + n/4 + ... = n
- then, find all numbers such that (n - 1)|ai = (1 << (32 - __builtin_clz(n - 1))) using n operations
    - we use 32 instead of 31 so we can get the msb << 1
- out of these numbers, find the minimum using less than n operations
*/

int t, n;
vector<int> maxOr(int l, int r, int mx) {
    if (l == r) {
        if (l == mx) return vector<int>();
        return vector<int>(1, l);
    }
    int m = (l + r)/2;
    auto ll = maxOr(l, m, mx), rr = maxOr(m + 1, r, mx);
    if (rr.empty()) return ll;
    if (ll.empty()) return rr;
    cout << "? " << ll[0] << " " << mx << " " << rr[0] << " " << mx << endl;
    char res;
    cin >> res;
    if (res == '<') return rr;
    if (res == '>') return ll;
    ll.reserve(ll.size() + distance(rr.begin(), rr.end()));
    ll.insert(ll.end(), rr.begin(), rr.end());
    return ll;
}
int solve(int l, int r, vector<int> &v, char op) {
    if (l == r) return v[l];
    int m = (l + r)/2, ll = solve(l, m, v, op), rr = solve(m + 1, r, v, op);
    char res;
    cout << "? " << ll << " " << ll << " " << rr << " " << rr << endl;
    cin >> res;
    return res == op ? rr : ll;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> v(n);
        iota(v.begin(), v.end(), 0);
        int mx = solve(0, n - 1, v, '<');
        auto res = maxOr(0, n - 1, mx);
        int mn = solve(0, res.size() - 1, res, '>');
        cout << "! " << mx << " " << mn << endl;
    }
    return 0;
}