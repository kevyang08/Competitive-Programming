#include <bits/stdc++.h>
using namespace std;

int t, a, b;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> t;
    while (t--) {
        cin >> a >> b;
        cout << a + b - 1 << "\n";
    }
    return 0;
}
