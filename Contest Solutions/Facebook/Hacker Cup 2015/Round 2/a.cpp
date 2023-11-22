#include <bits/stdc++.h>
using namespace std;

int t, n, a[50001];
bool solve(int idx) {
    int l = 1, r = n, mn = a[idx], mx = a[idx];
    if (idx == r) r--;
    else l++;
    while (l < r) {
        if (a[l] == mn - 1) mn = a[l++];
        else if (a[l] == mx + 1) mx = a[l++];
        else if (a[r] == mn - 1) mn = a[r--];
        else if (a[r] == mx + 1) mx = a[r--];
        else return false;
    }
    return true;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    for (int k = 1; k <= t; k++) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        cout << "Case #" << k << ": " << (n < 4 || solve(1) || solve(n) ? "yes" : "no") << '\n';
    }
    return 0;
}
