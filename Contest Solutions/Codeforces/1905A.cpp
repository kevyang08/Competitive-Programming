#include <bits/stdc++.h>
using namespace std;
 
int t, n, m;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        cout << max(n, m) << "\n";
    }
    return 0;
}
