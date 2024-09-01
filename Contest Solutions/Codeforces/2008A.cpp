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
        int a, b;
        cin >> a >> b;
        if (a%2) cout << "NO\n";
        else cout << (a || b%2 == 0 ? "YES\n" : "NO\n");
    }
    return 0;
}