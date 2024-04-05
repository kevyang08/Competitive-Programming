#include <bits/stdc++.h>
using namespace std;

int n, q, x, sz = 0, p[200001];
long long a[200001], psa[200001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= q; i++) {
        cin >> x;
        if (p[x]) {
            psa[i] = --sz + psa[i - 1];
            a[x] += psa[i - 1] - psa[p[x] - 1];
            p[x] = 0;
        }
        else {
            psa[i] = ++sz + psa[i - 1];
            p[x] = i;
        }
    }
    for (int i = 1; i <= n; i++) if (p[i]) a[i] += psa[q] - psa[p[i] - 1];
    for (int i = 1; i <= n; i++) cout << a[i] << (i == n ? "\n" : " ");
    return 0;
}

/*
tips:
- look out for int overflow and array out of bounds
- don't get stuck debugging a wrong solution, take time to think of a new one instead of spamming submissions
- make sure stuestion was read correctly
- for certain problems, solve a few cases by hand and try to make observations
- if behind, stop looking at leaderboard and focus on solving
*/
