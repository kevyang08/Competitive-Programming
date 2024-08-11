#include <bits/stdc++.h>
using namespace std;

int t, n;
long long x[100001], y[100001], xs, ys, xt, yt;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
        cin >> xs >> ys >> xt >> yt;
        bool ans = true;
        long long dt = (xt - xs) * (xt - xs) + (yt - ys) * (yt - ys);
        double m = (double)(yt - ys)/(xt - xs), b = ys - m * xs, nm = -(double)(xt - xs)/(yt - ys);
        for (int i = 1; i <= n; i++) {
            // find an x and y such that y = mx + b and y = nm*x + tb
            double cb = y[i] - nm * x[i];
            double cx, cy;
            if (yt == ys) cx = x[i], cy = ys;
            else if (xt == xs) cx = xs, cy = y[i];
            else cx = (cb - b)/(m - nm), cy = nm * cx + cb;
            if (cx >= min(xs, xt) && cx <= max(xs, xt) && cy >= min(ys, yt) && cy <= max(ys, yt)) ans &= ((cx - x[i]) * (cx - x[i]) + (cy - y[i]) * (cy - y[i]) > (cx - xs) * (cx - xs) + (cy - ys) * (cy - ys));
            if ((xt - x[i]) * (xt - x[i]) + (yt - y[i]) * (yt - y[i]) <= dt) ans = false;

            // cout << cx << " " << cy << " bruh\n";
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
    return 0;
}