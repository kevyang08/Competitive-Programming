// a much simpler solution is as follows:
// observe that if cnt[i] for any card i >= k, the ans will always be k - 1
// since you can keep making piles of >= k until only one pile left
// else ans will be n

#include <bits/stdc++.h>
using namespace std;

int t, n, k, c, cnt[101];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<int> v;
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; i++) {
            cin >> c;
            cnt[c]++;
        }
        for (int i = 1; i < 101; i++) if (cnt[i]) v.push_back(cnt[i]);
        while (v.size() > 1) {
            sort(v.begin(), v.end());
            if (v.back() < k) break;
            v[0] += v.back() - 1;
            v.pop_back();
        }
        if (v.size() == 1) v[0] = min(v[0], k - 1);
        int ans = 0;
        for (int i : v) ans += i;
        cout << ans << "\n";
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
