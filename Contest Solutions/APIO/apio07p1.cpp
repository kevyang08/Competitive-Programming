#include <bits/stdc++.h>
using namespace std;

int n, a, b, lo[100001], hi[100001], c[100001], sz[100001];
vector<int> adj[100001];
int dfs(int i) {
    int ans = 0, hc[2] = {0, 0}, s[2] = {0, 0};
    for (int j = 0; j < 2; j++) {
        if (adj[i][j] == -1) {
            hi[i] = 0;
            hc[j] = 1;
            s[j] = 1;
            if (j == 1 && adj[i][0] != -1) hc[0] = 0;
        }
        else {
            int res = dfs(adj[i][j]);
            if (res == -1) ans = -1;
            else if (ans != -1) ans += res;
            if (lo[adj[i][j]] + 1 > lo[i]) lo[i] = lo[adj[i][j]] + 1;
            if (hi[adj[i][j]] + 1 <= hi[i]) {
                hc[j] = c[adj[i][j]];
                hi[i] = hi[adj[i][j]] + 1;
                if (j == 1 && hi[adj[i][0]] + 1 > hi[i]) hc[0] = 0;
            }
            else hc[j] = 0;
            s[j] = sz[adj[i][j]];
        }
    }
    c[i] = hc[0] + hc[1];
    sz[i] = s[0] + s[1];
    if (ans == -1 || lo[i] - hi[i] > 1 || hc[0] < s[0] && hc[1] < s[1] && hc[0] != 0 && hc[1] != 0) return -1;
    if (hc[1] == 0 && hc[0] > 0 || hc[1] < s[1] && hc[0] == s[0]) ans++;
    return ans;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    memset(hi, 0x3f3f3f3f, sizeof(hi));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        adj[i].push_back(a);
        adj[i].push_back(b);
    }
    cout << dfs(1) << "\n";
    return 0;
}
