#include <bits/stdc++.h>
using namespace std;

int n, q, s[1000001], a, b, c;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> s[i];
    for (int i = 1; i <= n; i++) s[i] += s[i - 1];
    while (q--) {
        cin >> a >> b >> c;
        if (a == 1) s[b - 1] += c;
        else if (a == 2) s[b] -= c;
        else cout << s[c] - s[b - 1] << "\n";
    }
    return 0;
}
