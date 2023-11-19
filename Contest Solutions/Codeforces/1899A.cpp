#include <bits/stdc++.h>
using namespace std;
 
int t, n;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        cout << ((n - 1)%3 == 0 || (n + 1)%3 == 0 ? "First\n" : "Second\n");
    }
    return 0;
}
