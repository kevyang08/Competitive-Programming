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
        for (int i = 1; i <= n; i++) cout << n/i * i << (i == n ? "\n" : " ");
    }
    return 0;
}