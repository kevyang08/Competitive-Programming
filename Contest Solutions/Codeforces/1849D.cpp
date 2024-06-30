#include <bits/stdc++.h>
using namespace std;

int n, a[200005], ans = 0;
bool vis[200005];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    auto thing = [&](int i, int dt) {
        ans++;
        vis[i] = true;
        for (int j = i + dt; j > 0 && j <= n && a[j - dt]; j += dt) {
            vis[j] = true;
            if (!a[j] && a[j + dt] && !vis[j + dt]) {
                ans++;
                a[j] = 1;
            }
        }
    };
    if (a[1]) thing(1, 1);
    if (a[n] && !vis[n]) thing(n, -1);
    for (int i = 1; i <= n; i++) {
        if (vis[i] || a[i] != 2) continue;
        thing(i, -1);
        thing(i, 1);
        ans--;
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i] || a[i] != 1) continue;
        if (!vis[i - 1]) thing(i, -1);
        else thing(i, 1);
    }
    for (int i = 1; i <= n; i++) if (!vis[i]) ans++;
    cout << ans << "\n";
    return 0;
}

/*
tips:
- look out for int overflow and array out of bounds
- don't get stuck debugging a wrong solution, take time to think of a new one instead of spamming submissions
- make sure stuestion was read correctly
- for certain problems, solve a few cases by hand and try to make observations
- if behind, stop looking at leaderboard and focus on solving
*/