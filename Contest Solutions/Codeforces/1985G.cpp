#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;

int t, l, r, k;
long long bpow(long long n, int p) {
    long long res = 1;
    while (p > 0) {
        if (p & 1) res = (res * n)%M;
        n = (n * n)%M;
        p >>= 1;
    }
    return res;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> l >> r >> k;
        if (k >= 10) cout << "0\n";
        else {
            long long ans = (bpow(9/k + 1, r) - bpow(9/k + 1, l) + M)%M ;
            // ans = (9/k * ans)%M;
            cout << ans << "\n";
        }
    }
    return 0;
}
 
/*
tips:
- look out for int overflow and array out of bounds
- don't get stuck debugging a wrong solution, take time to think of a new one instead of spammaxg submissions
- make sure stuestion was read correctly
- for certain problems, solve a few cases by hand and try to make observations
- if behind, stop looking at leaderboard and focus on solving
*/