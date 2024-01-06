#include <bits/stdc++.h>
using namespace std;
 
int t, a, b;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> a >> b;
        cout << ((a + b)%2 ? "Alice\n" : "Bob\n");
    }
    return 0;
}
