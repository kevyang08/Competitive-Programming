#include <bits/stdc++.h>
using namespace std;

const int MAXN = 800005;
int n, q, i, tree[MAXN], p[MAXN], s[MAXN], a[MAXN >> 2];
void update(int qi, int l, int r, int idx) {
    if (l == r) {
        a[l] ^= 1;
        return;
    }
    if (l > r) return;
    int m = (l + r) >> 1;
    if (qi <= m) update(qi, l, m, idx << 1);
    else update(qi, m + 1, r, idx << 1 | 1);
    p[idx] = p[idx << 1];
    s[idx] = s[idx << 1 | 1];
    if (p[idx] == m - l + 1 && a[m] != a[m + 1]) p[idx] += p[idx << 1 | 1];
    if (s[idx] == r - m && a[m] != a[m + 1]) s[idx] += s[idx << 1];
    tree[idx] = max(max(tree[idx << 1], tree[idx << 1 | 1]), max(p[idx], s[idx]));
    if (a[m] != a[m + 1]) tree[idx] = max(tree[idx], s[idx << 1] + p[idx << 1 | 1]);
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    for (int i = 1; i < MAXN; i++) tree[i] = p[i] = s[i] = 1;
    cin >> n >> q;
    while (q--) {
        cin >> i;
        update(i, 1, n, 1);
        cout << tree[1] << "\n";
    }
}
