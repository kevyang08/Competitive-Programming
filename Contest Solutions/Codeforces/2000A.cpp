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
        string a;
        cin >> a;
        cout << (a[0] == '1' && a[1] == '0' && a[2] != '0' && (a[2] > '1' || a.length() > 3) ? "YES\n" : "NO\n");
    }
    return 0;
}