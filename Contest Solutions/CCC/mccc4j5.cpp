#include <bits/stdc++.h>
using namespace std;

int n, t[5001], r, x, in[5001], out[5001], bruh[5001], ans = 0;
vector<int> adj[5001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> r;
        bruh[i] = t[i];
        in[i] = r;
        for (int j = 0; j < r; j++) {
            cin >> x;
            out[x]++;
            adj[x].push_back(i);
        }
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) if (in[i] == 0) q.push(i);
    while (!q.empty()) {
        int c = q.front(); q.pop();
        for (int i : adj[c]) {
            bruh[i] = max(bruh[i], t[i] + bruh[c]);
            in[i]--;
            if (in[i] == 0) q.push(i);
        }
    }
    for (int i = 1; i <= n; i++) if (out[i] == 0) ans = max(ans, bruh[i]);
    cout << ans << "\n";
    return 0;
}
