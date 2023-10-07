#include <bits/stdc++.h>
using namespace std;

int t, n, x[100001];
double solve(int l, int r) {
    return (x[l] + x[r])/2.0;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    freopen("here_comes_santa_claus_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> t;
    for (int bruh = 1; bruh <= t; bruh++) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> x[i];
        sort(x, x + n + 1);
        if (n == 5) printf("Case #%d: %.6f\n", bruh, max(solve(n - 2, n) - solve(1, 2), solve(n - 1, n) - solve(1, 3)));
        else printf("Case #%d: %.6f\n", bruh, solve(n - 1, n) - solve(1, 2));
    }
    return 0;
}
