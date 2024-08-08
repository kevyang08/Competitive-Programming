#include <bits/stdc++.h>
using namespace std;

int t, l, r, arr[200001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    for (int i = 1; i <= 200000; i++) arr[i] = arr[i - 1] + (int)floor(log2(i)/log2(3)) + 1;
    cin >> t;
    while (t--) {
        cin >> l >> r;
        cout << arr[r] + arr[l] - 2 * arr[l - 1] << "\n";
    }
    return 0;
}