#include <bits/stdc++.h>
using namespace std;

int n, q, p, ql, qr;
vector<pair<int, int>> tree[200001];
void update(int i, int v) {
    for (int j = v; j > 0; j -= (j & -j)) tree[j].push_back({i, tree[j][tree[j].size() - 1].second + 1});
}
int bs1(int v, int idx) {
    int ans = 0, l = 0, r = tree[idx].size() - 1;
    while (l <= r) {
        int m = (l + r)/2;
        if (tree[idx][m].first >= v) r = m - 1;
        else {
            ans = m;
            l = m + 1;
        }
    }
    return ans;
}
int bs2(int v, int idx) {
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
int query(int ql, int qr, int idx) {
    int res = 0;
    for (; idx <= 200000; idx += (idx & -idx)) {
        if (tree[idx][tree[idx].size() - 1].first < ql) continue;
        int l = bs1(ql, idx), r = bs2(qr, idx);
        if (r == 0) continue;
        res += tree[idx][r].second - tree[idx][l].second;
    }
    return res;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    for (int i = 1; i <= 200000; i++) tree[i].push_back({0, 0});
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> p;
        update(i, p);
    }
    while (q--) {
        cin >> ql >> qr;
        int ans = 0, l = 1, r = n;
        while (l <= r) {
            int m = (l + r)/2;
            if (query(ql, qr, m) < m) r = m - 1;
            else {
                ans = m;
                l = m + 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
