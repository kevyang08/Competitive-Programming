#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
// const int M = 998244353;
const int M = 1e9 + 7;

int t;
string s, colors = "rgb";
void solve1() {
    int n, m, u, v;
    cin >> n >> m;
    vector<int> c(n + 1, -1);
    vector<vector<int>> adj(n + 1, vector<int>());
    while (m--) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    c[1] = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int j : adj[cur]) {
            if (c[j] != -1) continue;
            c[j] = (c[cur] + 1)%3;
            q.push(j);
        }
    }
    for (int i = 1; i <= n; i++) cout << colors[c[i]];
    cout << '\n';
}
void solve2() {
    int q, d;
    string bruh;
    cin >> q;
    while (q--) {
        cin >> d >> bruh;
        vector<int> v(3);
        for (int i = 0; i < d; i++) {
            if (bruh[i] == 'r') v[0] = i + 1;
            else if (bruh[i] == 'g') v[1] = i + 1;
            else v[2] = i + 1;
        }
        if (v[0]) {
            if (v[1]) cout << v[1] << '\n';
            else cout << v[0] << '\n';
        }
        else if (v[1] && !v[2]) cout << v[1] << '\n';
        else if (v[2] && !v[0]) cout << v[2] << '\n';
    }
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> s >> t;
    bool bruh = s == "first";
    while (t--) {
        if (bruh) solve1();
        else solve2();
    }
    return 0;
}