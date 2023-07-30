#include <bits/stdc++.h>
using namespace std;

int n, a, b, ans = 0, mn = 0x3f3f3f3f;
vector<int> adj[20001];
int dfs(int i, int p) {
    int mx = 0, cnt = 1;
    for (int j : adj[i]) {
        if (j == p) continue;
        int res = dfs(j, i);
        cnt += res;
        mx = max(res, mx);
    }
    mx = max(n - cnt, mx);
    if (mx < mn || mx == mn && i < ans) {
        mn = mx;
        ans = i;
    }
    return cnt;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    cout << ans << " " << mn << "\n";
    return 0;
}
