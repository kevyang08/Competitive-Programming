#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int k, l;
ll x;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> x >> k;
    vector<int> idx(k);
    vector<vector<int>> v(k);
    priority_queue<tuple<ll, ll, int>> pq;
    for (int i = 0; i < k; i++) {
        cin >> l;
        v[i].resize(l);
        ll s = 0, mn = 0;
        for (int j = 0; j < l; j++) {
            cin >> v[i][j];
            if (s > 0) continue;
            s += v[i][j];
            mn = min(mn, s);
            ++idx[i];
        }
        if (s > 0) pq.push({mn, s, i});
    }
    while (!pq.empty()) {
        auto [mn, d, i] = pq.top(); pq.pop();
        if (-mn > x) break;
        x += d;
        mn = 0, d = 0;
        for (; idx[i] < v[i].size(); idx[i]++) {
            if (d > 0) break;
            d += v[i][idx[i]];
            mn = min(mn, d);
        }
        if (d > 0) pq.push({mn, d, i});
    }
    cout << x << "\n";
    return 0;
}