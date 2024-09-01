#include <bits/stdc++.h>
using namespace std;

int t, n, p[200001], sz[200001];
string s;
bool cur[200001], vis[200001];
int dfs(int i, int c) {
    sz[i] = (s[i - 1] == '0');
    vis[i] = true;
    cur[i] = true;
    if (cur[p[i]]) {
        sz[i] = c + sz[i];
        cur[i] = false;
        return p[i];
    }
    if (vis[p[i]]) {
        sz[i] += sz[p[i]];
        cur[i] = false;
        return 0;
    }
    int tmp = dfs(p[i], c + sz[i]);
    if (tmp) sz[i] = sz[p[i]];
    else sz[i] += sz[p[i]];
    cur[i] = false;
    return (tmp == i ? 0 : tmp);
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> p[i];
        fill(vis, vis + n + 1, false);
        cin >> s;
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) dfs(i, 0);
            cout << sz[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}