#include <bits/stdc++.h>
using namespace std;

int t, n, a[200001], p[200001];
bool check(int x) {
    deque<int> dq;
    for (int l = 1, r = n; l <= r; ) {
        if (l == r) {
            if (x == 1) dq.push_front(p[l++]);
            else dq.push_back(p[l++]);
        }
        else if (p[l] < p[r]) dq.push_front(p[l++]);
        else dq.push_back(p[r--]);
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] != dq.front()) return false;
        dq.pop_front();
    }
    return true;
}
bool solve(int x) {
    int l = 1 + (x == 1), r = n - (x == n);
    queue<int> ql, qr;
    while (l <= r) {
        if (a[l] > a[r]) ql.push(a[l++]);
        else qr.push(a[r--]);
    }
    // l = 1, r = n;
    p[ql.size() + 1] = a[x];
    for (int i = ql.size(); i > 0; i--) p[i] = ql.front(), ql.pop();
    for (int i = n - qr.size() + 1; i <= n; i++) p[i] = qr.front(), qr.pop();

    // cout << x << " bruh\n";
    // for (int i = 1; i <= n; i++) cout << p[i] << (i == n ? "\n" : " ");

    return check(x);
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        if (solve(1)) for (int i = 1; i <= n; i++) cout << p[i] << (i == n ? "\n" : " ");
        else if (solve(n)) for (int i = 1; i <= n; i++) cout << p[i] << (i == n ? "\n" : " ");
        else cout << "-1\n";
    }
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
