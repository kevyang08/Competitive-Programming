#include <bits/stdc++.h>
using namespace std;

// forgot about pigeonhole principle

int t, n, a[2001], id[2001];
int find(int i) {
    return id[i] < 0 ? i : (id[i] = find(id[i]));
}
void join(int u, int v) {
    if (id[u = find(u)] < id[v = find(v)]) {
        id[u] += id[v];
        id[v] = u;
    }
    else {
        id[v] += id[u];
        id[u] = v;
    }
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        vector<pair<int, int>> ans;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            id[i] = -1;
        }
        for (int i = n - 1; i > 0; i--) {
            vector<int> thing[i];
            for (int j = 1; j <= n; j++) {
                thing[a[j]%i].push_back(j);
            }
            for (int j = 0; j < i; j++) {
                if (ans.size() >= n - i) break;
                for (auto &k : thing[j]) if (find(k) != find(thing[j][0])) {
                    join(k, thing[j][0]);
                    ans.push_back({k, thing[j][0]});
                    break;
                }
            }
        }
        reverse(ans.begin(), ans.end());
        cout << "YES\n";
        for (auto &[u, v] : ans) cout << u << " " << v << "\n";
    }
    return 0;
}