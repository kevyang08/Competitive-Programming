#include <bits/stdc++.h>
using namespace std;

int n, m, k[1000001], a, b, out[1000001], dp[1000001], ans = 0;
queue<int> q;
stack<int> st;
vector<int> adj[2][1000001];
bool vis[1000001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> k[i];
    while (m--) {
        cin >> a >> b;
        adj[1][a].push_back(b);
        adj[0][b].push_back(a);
        out[a]++;
    }
    for (int i = 1; i <= n; i++) if (!out[i]) q.push(i);
    while (!q.empty()) {
        int c = q.front();
        vis[c] = true;
        q.pop();
        for (int j : adj[0][c]) {
            out[j]--;
            if (!out[j]) q.push(j);
        }
        st.push(c);
    }
    for (int i = 1; i <= n; i++) if (!vis[i] && k[i]) {
        cout << "-1\n";
        return 0;
    }
    while (!st.empty()) {
        int c = st.top();
        st.pop();
        for (int j : adj[1][c]) dp[j] += dp[c] + (k[c] + dp[c])%2;
        if ((k[c] + dp[c])%2) ans++;
    }
    cout << ans << "\n";
    return 0;
}
