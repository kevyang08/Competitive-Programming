#include <bits/stdc++.h>
using namespace std;

int t;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        cout << min(min(n * m, k * k), min(k * n, k * m)) << "\n";
    }
    return 0;
}