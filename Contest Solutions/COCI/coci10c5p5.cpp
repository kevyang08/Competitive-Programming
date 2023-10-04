#include <bits/stdc++.h>
using namespace std;

int n, s, arr[100001], mx[100001];
int bsLeft(int l, int r) {
    int i = r;
    while (l <= r) {
        int m = (l + r)/2;
        if (arr[i] - arr[m - 1] <= s) r = m - 1;
        else l = m + 1;
    }
    return l;
}
int bsRight(int l, int r) {
    int i = l - 1;
    while (l <= r) {
        int m = (l + r)/2;
        if (arr[m] - arr[i] <= s) l = m + 1;
        else r = m - 1;
    }
    return r;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    for (int i = 1; i < n; i++) {
        int l = bsLeft(1, i), r = bsRight(i + 1, n), ans = min(i - l + 1, r - i);
        if (ans) mx[i - ans + 1] = max(i, mx[i - ans + 1]);
    }
    for (int i = 1; i <= n; i++) {
        if (mx[i - 1] >= i) mx[i] = max(mx[i], mx[i - 1]);
        cout << (mx[i] ? 2 * (mx[i] - i + 1) : 0) << "\n";
    }
    return 0;
}
