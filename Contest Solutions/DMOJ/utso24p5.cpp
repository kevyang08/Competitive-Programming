#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

/*
post-submission: cleanest (still pre bad) implementation of my original idea, was just missing the stupid lines 107 and 108
*/

struct node {
    int p, l, r, pl, pr;
    node() {
        p = l = r = pl = pr = -1;
    }
} st[800005];
int n, q, a[200005], o[200005], x, y;
string s;
char op;
void combine(int l, int r, int m, node *cur, node *lc, node *rc) {
    if (o[m]) {
        cur -> p = (lc -> p) ^ (rc -> p) ^ (lc -> pr) ^ (rc -> pl) ^ (lc -> pr & rc -> pl);
        if (lc -> l == m - l + 1) {
            cur -> pl = lc -> pl & rc -> pl;
            cur -> l = lc -> l + rc -> l;
        }
        else {
            cur -> pl = lc -> pl;
            cur -> l = lc -> l;
        }
        if (rc -> r == r - m) {
            cur -> pr = rc -> pr & lc -> pr;
            cur -> r = rc -> r + lc -> r;
        }
        else {
            cur -> pr = rc -> pr;
            cur -> r = rc -> r;
        }
    }
    else {
        cur -> l = lc -> l;
        cur -> r = rc -> r;
        cur -> pl = lc -> pl;
        cur -> pr = rc -> pr;
        cur -> p = lc -> p ^ rc -> p;
    }
}
void build(int l, int r, int idx) {
    if (l == r) {
        st[idx].p = st[idx].pl = st[idx].pr = (a[l] & 1);
        st[idx].l = st[idx].r = 1;
        return;
    }
    int m = (l + r)/2;
    build(l, m, 2 * idx);
    build(m + 1, r, 2 * idx + 1);
    combine(l, r, m, &st[idx], &st[2 * idx], &st[2 * idx + 1]);
}
void update(int l, int r, int i, int v, int idx) {
    if (l == r) {
        st[idx].p ^= v, st[idx].pl ^= v, st[idx].pr ^= v;
        return;
    }
    int m = (l + r)/2;
    if (i > m) update(m + 1, r, i, v, 2 * idx + 1);
    else update(l, m, i, v, 2 * idx);
    combine(l, r, m, &st[idx], &st[2 * idx], &st[2 * idx + 1]);
}
node query(int l, int r, int ql, int qr, int idx) {
    if (l > qr || r < ql) return node();
    if (ql <= l && r <= qr) return st[idx];
    int m = (l + r)/2;
    node rl = query(l, m, ql, qr, 2 * idx), rr = query(m + 1, r, ql, qr, 2 * idx + 1);
    if (rl.p == -1) return rr;
    else if (rr.p == -1) return rl;
    node res = node();
    combine(max(l, ql), min(r, qr), m, &res, &rl, &rr);
    return res;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> s;
    for (int i = 1; i < n; i++) o[i] = (s[i - 1] == 'x');
    build(1, n, 1);
    while (q--) {
        cin >> op >> x;
        if (op == 'V') update(1, n, x, 1, 1);
        else if (op == 'O') {
            o[x] ^= 1;
            update(1, n, x, 0, 1);
            update(1, n, x + 1, 0, 1);
            update(1, n, x, 0, 1);
        }
        else {
            cin >> y;
            node mid = query(1, n, x, y, 1), left = query(1, n, 1, x - 1, 1), right = query(1, n, y + 1, n, 1);
            node temp = node(), ans = node();
            mid.l = mid.r = y - x + 1; // important
            mid.pl = mid.pr = mid.p;
            if (left.p != -1) combine(1, y, x - 1, &temp, &left, &mid);
            else temp = mid;
            if (right.p != -1) combine(1, n, y, &ans, &temp, &right);
            else ans = temp;
            cout << (ans.p ? "odd" : "even") << "\n";
        }
    }
    return 0;
}