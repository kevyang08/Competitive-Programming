#include <bits/stdc++.h>
using namespace std;

const int sz = 450;

int n, q, l, r, a[200001], ans[200001], freq[200001], cnt = 0;
vector<pair<pair<int, int>, int>> v;
bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    return a.first.first/sz == b.first.first/sz ? a.first.second < b.first.second : a.first.first < b.first.first;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= q; i++) {
        cin >> l >> r;
        v.push_back({{l, r}, i});
    }
    sort(v.begin(), v.end(), cmp);
    l = 1; r = 0;
    for (auto p : v) {
        int ql = p.first.first, qr = p.first.second, idx = p.second;
        while (r < qr) {
            freq[a[++r]]++;
            if (freq[a[r]] == 1) cnt++;
            else if (freq[a[r]] == 2) cnt--;
        }
        while (l < ql) {
            freq[a[l]]--;
            if (freq[a[l]] == 1) cnt++;
            else if (!freq[a[l]]) cnt--;
            l++;
        }
        while (r > qr) {
            freq[a[r]]--;
            if (freq[a[r]] == 1) cnt++;
            else if (!freq[a[r]]) cnt--;
            r--;
        }
        while (l > ql) {
            freq[a[--l]]++;
            if (freq[a[l]] == 1) cnt++;
            else if (freq[a[l]] == 2) cnt--;
        }
        ans[idx] = cnt;
    }
    for (int i = 1; i <= q; i++) cout << ans[i] << "\n";
    return 0;
}

/*
tips:
- look out for int overflow and array out of bounds
- don't get stuck debugging a wrong solution, take time to think of a new one instead of spamming submissions
- make sure question was read correctly
- for certain problems, solve a few cases by hand and try to make observations
- if behind, stop looking at leaderboard and focus on solving
*/
