#include <bits/stdc++.h>
using namespace std;

int t, n;
long long m, k;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        long long ml = 0, ans = 0;
        int mxt = 0;
        map<int, vector<int>> adj;
        map<int, int> mp;
        while (n--) {
            cin >> k;
            ml = max(ml, k);
            vector<int> v(k);
            for (int i = 0; i < k; i++) cin >> v[i];
            sort(v.begin(), v.end());
            long long j = 0, thing = 1, p = 0;
            for (int i = 0; i < k; i++) {
                if (i && v[i] == v[i - 1]) continue;
                if (v[i] != j && thing) {
                    ++mp[j];
                    p = j;
                    ++j, thing = 0;
                }
                if (v[i] == j) ++j;
                else break;
            }
            if (thing) {
                ++mp[j];
                adj[j].push_back(j + 1);
            }
            else adj[p].push_back(j);
        }
        vector<int> mx(ml + 2);
        iota(mx.begin(), mx.end(), 0);
        for (int i = ml + 1; i >= 0; i--) {
            if (adj.find(i) == adj.end()) continue;
            for (int j : adj[i]) mx[i] = max(mx[i], mx[j]);
        }
        for (auto &[i, j] : mp) {
            mxt = max(mxt, i);
            if (j > 1) mxt = max(mxt, mx[i]);
        }
        for (int i = min(m, ml + 1); i >= 0; i--) ans += max(mx[i], mxt);
        cout << max(m * (m + 1)/2 - (ml + 1) * (ml + 2)/2, 0LL) + ans << "\n";
    }
    return 0;
}