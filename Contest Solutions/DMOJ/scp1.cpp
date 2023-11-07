#include <bits/stdc++.h>
using namespace std;

int n, p[200001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i];
    if (n < 4) {
        for (int i = 1; i <= n; i++) if (p[i] == n) cout << i << " " << i << "\n";
    }
    else {
        if (p[1] == 1) cout << 2 << " " << n << "\n";
        else if (p[n] == 1) cout << 1 << " " << n - 1 << "\n";
        else cout << 1 << " " << n << "\n";
    }
    return 0;
}
