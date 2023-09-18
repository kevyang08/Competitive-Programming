#include <bits/stdc++.h>
using namespace std;

int n, q, a, l, r, x;
set<int> s[100001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        s[a].insert(i);
    }
    while (q--) {
        cin >> l >> r >> x;
        bool ans = false;
        for (int i = 1; i * i < x; i++) {
            if (x%i) continue;
            if (s[i].lower_bound(l) != s[i].end() && *s[i].lower_bound(l) <= r && s[x/i].lower_bound(l) != s[x/i].end() && *s[x/i].lower_bound(l) <= r) ans = true;
        }
        cout << (ans ? "YES" : "NO") << "\n";
    }
    return 0;
}
