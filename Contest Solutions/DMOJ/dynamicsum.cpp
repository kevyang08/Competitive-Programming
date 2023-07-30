#include <bits/stdc++.h>
using namespace std;

int n, q, op, c = 0;
long long a, b, x, ans = 0;
vector<pair<int, long long>> tree[300001];
void update(int i, int v) {
    for (int j = i; j <= n; j += (j & -j)) tree[j].push_back({c, tree[j][tree[j].size() - 1].second + v});
}
int bs(int v, int idx) {
    int ans = 0, l = 0, r = tree[idx].size() - 1;
    while (l <= r) {
        int m = (l + r)/2;
        if (tree[idx][m].first > v) r = m - 1;
        else {
            ans = m;
            l = m + 1;
        }
    }
    return ans;
}
long long query(int v, int idx) {
    long long res = 0;
    for (; idx > 0; idx -= (idx & -idx)) {
        int i = bs(v, idx);
        res += tree[idx][i].second;
    }
    return res;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) tree[i].push_back({0, 0});
    while (q--) {
        cin >> op >> a >> b;
        a ^= ans;
        b ^= ans;
        if (op == 1) {
            ++c;
            update(a, b);
        }
        else {
            cin >> x;
            x ^= ans;
            ans = query(c - x, b) - query(c - x, a - 1);
            cout << ans << "\n";
        }
    }
    return 0;
}
