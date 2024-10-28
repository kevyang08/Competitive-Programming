#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t, n, q, p[200001], mx[200001], mn[200001];
char s[200001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        int ans = 0;
        cin >> n >> q;
        for (int i = 1; i <= n; i++) cin >> p[i];
        for (int i = 1; i <= n; i++) cin >> s[i];
        mx[1] = p[1], mn[n] = p[n];
        for (int i = 2; i <= n; i++) {
            mx[i] = max(mx[i - 1], p[i]);
            if (mx[i - 1] >= i && s[i - 1] == 'L' && s[i] == 'R') ++ans;
        }
        for (int i = n - 1; i > 0; i--) {
            mn[i] = min(mn[i + 1], p[i]);
            if (mn[i + 1] <= i && s[i + 1] == 'R' && s[i] == 'L') ++ans;
        }
        while (q--) {
            int i;
            cin >> i;
            if (i > 1 && mx[i - 1] >= i && s[i - 1] == 'L' && s[i] == 'R') --ans;
            if (i < n && mx[i] > i && s[i] == 'L' && s[i + 1] == 'R') --ans;
            if (i < n && mn[i + 1] <= i && s[i + 1] == 'R' && s[i] == 'L') --ans;
            if (i > 1 && mn[i] < i && s[i] == 'R' && s[i - 1] == 'L') --ans;
            s[i] = (s[i] == 'L' ? 'R' : 'L');
            if (i > 1 && mx[i - 1] >= i && s[i - 1] == 'L' && s[i] == 'R') ++ans;
            if (i < n && mx[i] > i && s[i] == 'L' && s[i + 1] == 'R') ++ans;
            if (i < n && mn[i + 1] <= i && s[i + 1] == 'R' && s[i] == 'L') ++ans;
            if (i > 1 && mn[i] < i && s[i] == 'R' && s[i - 1] == 'L') ++ans;
            cout << (ans ? "NO\n" : "YES\n");
        }
    }
    return 0;
}