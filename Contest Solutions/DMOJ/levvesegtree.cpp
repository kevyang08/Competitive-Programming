#include <bits/stdc++.h>
using namespace std;

// pointers would be much simpler, but comes way too close to the tl for some reason

typedef long long ll;

const int MX = 3e7 + 1;

int q, sz = 1;
ll n, a, b, ans = 0;
char op;
struct Node {
    ll mx, s;
    int idl{0}, idr{0};
    Node(): mx{0}, s{0} {}
} st[MX];
void update(int idx, ll l, ll r, ll i, int v) {
    if (!v) return;
    if (l == r) {
        st[idx].mx = st[idx].s = v;
        return;
    }
    ll m = (l + r) >> 1;
    if (i > m) {
        if (!st[idx].idr) st[idx].idr = ++sz;
        update(st[idx].idr, m + 1, r, i, v);
    }
    else {
        if (!st[idx].idl) st[idx].idl = ++sz;
        update(st[idx].idl, l, m, i, v);
    }
    st[idx].mx = max(st[st[idx].idl].mx, st[st[idx].idr].mx);
    st[idx].s = st[st[idx].idl].s + st[st[idx].idr].s;
}
ll queryS(int idx, ll l, ll r, ll ql, ll qr) {
    if (l > qr || r < ql || !st[idx].s) return 0;
    if (ql <= l && r <= qr) return st[idx].s;
    ll m = (l + r) >> 1;
    return queryS(st[idx].idl, l, m, ql, qr) + queryS(st[idx].idr, m + 1, r, ql, qr);
}
ll queryM(int idx, ll l, ll r, ll ql, ll qr) {
    if (l > qr || r < ql || !st[idx].mx) return 0;
    if (ql <= l && r <= qr) return st[idx].mx;
    ll m = (l + r) >> 1;
    return max(queryM(st[idx].idl, l, m, ql, qr), queryM(st[idx].idr, m + 1, r, ql, qr));
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> q;
    while (q--) {
        cin >> op >> a >> b;
        a ^= ans, b ^= ans;
        if (op == 'C') update(1, 1, n, a, b);
        else {
            if (op == 'S') ans = queryS(1, 1, n, a, b);
            else ans = queryM(1, 1, n, a, b);
            cout << ans << "\n";
        }
    }
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
