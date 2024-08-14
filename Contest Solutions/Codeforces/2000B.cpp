#include <bits/stdc++.h>
using namespace std;

int t, n, a;
bool thing[200005];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        fill(thing, thing + n + 2, false);
        bool ans = true;
        for (int i = 0; i < n; i++) {
            cin >> a;
            thing[a] = true;
            if (i > 0 && !thing[a - 1] && !thing[a + 1]) ans = false;
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
    return 0;
}