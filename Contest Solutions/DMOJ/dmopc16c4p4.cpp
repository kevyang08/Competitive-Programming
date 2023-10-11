#include <bits/stdc++.h>
using namespace std;

const int sz = 512;

int n, q, l, r, a[100500], cnt[100500], ans[100500], cur = 0;
vector<pair<pair<int, int>, int>> v;
bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    int lf = a.first.first/sz, ls = b.first.first/sz;
    return lf != ls ? lf < ls : a.first.second < b.first.second;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> l >> r;
        v.push_back({{l, r}, i});
    }
    sort(v.begin(), v.end(), cmp);
    l = 1; r = 0;
    for (auto p : v) {
        while (r < p.first.second) {
            r++;
            cnt[a[r]]++;
            if (cnt[a[r]] > 1) cur += (cnt[a[r]]%2 ? -1 : 1);
        }
        while (r > p.first.second) {
            cnt[a[r]]--;
            if (cnt[a[r]]) cur += (cnt[a[r]]%2 ? -1 : 1);
            r--;
        }
        while (l < p.first.first) {
            cnt[a[l]]--;
            if (cnt[a[l]]) cur += (cnt[a[l]]%2 ? -1 : 1);
            l++;
        }
        while (l > p.first.first) {
            l--;
            cnt[a[l]]++;
            if (cnt[a[l]] > 1) cur += (cnt[a[l]]%2 ? -1 : 1);
        }
        ans[p.second] = cur;
    }
    for (int i = 1; i <= q; i++) cout << ans[i] << "\n";
    return 0;
}
