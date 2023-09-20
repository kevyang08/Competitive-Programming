#include <bits/stdc++.h>
using namespace std;

int n, q, a, l, r, k, idu = 0, idq = 0;
long long bit[200001], ans[200001];
vector<int> bruh;
vector<pair<int, int>> upd;
vector<pair<pair<int, int>, pair<int, int>>> v;
void update(int i, int v) {
    for (; i <= n; i += (i & -i)) bit[i] += v;
}
long long query(int i) {
    long long res = 0;
    for (; i > 0; i -= (i & -i)) res += bit[i];
    return res;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        upd.push_back({a, i});
        bruh.push_back(a);
    }
    for (int i = 1; i <= q; i++) {
        cin >> l >> r >> k;
        v.push_back({{k, i}, {l, r}});
        bruh.push_back(k);
    }
    sort(bruh.begin(), bruh.end());
    sort(upd.begin(), upd.end());
    sort(v.begin(), v.end());
    for (int i : bruh) {
        while (idu < n && upd[idu].first < i) {
            update(upd[idu].second, upd[idu].first);
            idu++;
        }
        while (idq < q && v[idq].first.first == i) {
            ans[v[idq].first.second] -= query(v[idq].second.second) - query(v[idq].second.first - 1);
            idq++;
        }
    }
    memset(bit, 0, sizeof(bit));
    reverse(bruh.begin(), bruh.end());
    reverse(upd.begin(), upd.end());
    reverse(v.begin(), v.end());
    idu = idq = 0;
    for (int i : bruh) {
        while (idu < n && upd[idu].first == i) update(upd[idu++].second, i);
        while (idq < q && v[idq].first.first == i) {
            ans[v[idq].first.second] += query(v[idq].second.second) - query(v[idq].second.first - 1);
            idq++;
        }
    }
    for (int i = 1; i <= q; i++) cout << ans[i] << "\n";
    return 0;
}
