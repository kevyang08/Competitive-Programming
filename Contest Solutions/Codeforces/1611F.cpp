#include <bits/stdc++.h>
using namespace std;

// dont need the queue

int t, n, s, a[200001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> s;
        int l = 1, al = 0, ar = -1;
        long long cur = s, prev = s;
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (cur + a[i] >= 0) {
                if (i - l + 1 > ar - al + 1) ar = i, al = l;
                cur += a[i];
            }
            else {
                while (l < i && cur + a[i] < 0) cur -= a[l++];
                if (cur + a[i] < 0) l = i + 1;
                else {
                    cur += a[i];
                    if (i - l + 1 >= ar - al + 1) ar = i, al = l;
                }
            }
        }
        if (al) cout << al << " " << ar << "\n";
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
