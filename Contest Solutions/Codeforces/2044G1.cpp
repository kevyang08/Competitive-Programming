#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int t, n, r[200001], in[200001], mx[200001];
bool vis[200001];
queue<int> q;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        fill(vis, vis + n + 1, false);
        fill(in, in + n + 1, 0);
        fill(mx, mx + n + 1, 1);
        for (int i = 1; i <= n; i++) cin >> r[i];
        for (int i = 1; i <= n; i++) ++in[r[i]];
        for (int i = 1; i <= n; i++) if (!in[i]) q.push(i);
        while (!q.empty()) {
            int c = q.front(); q.pop();
            vis[c] = true;
            mx[r[c]] = max(mx[r[c]], mx[c] + 1);
            --in[r[c]];
            if (!in[r[c]]) q.push(r[c]);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) if (!vis[i]) ans = max(ans, mx[i] + 1);
        cout << ans << "\n";
    }
    return 0;
}