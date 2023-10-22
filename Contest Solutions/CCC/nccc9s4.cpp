#include <bits/stdc++.h>
using namespace std;

const int sz = 350;

int n, q, s[100001], l, r, freq[100001], mx = 0, mxb = 0, ans[100001];
vector<pair<pair<int, int>, int>> v[sz];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> s[i];
    for (int i = 1; i <= q; i++) {
        cin >> l >> r;
        v[l/sz].push_back({{r, l}, i});
    }
    for (int i = 0; i <= n/sz; i++) {
        mx = 0;
        memset(freq, 0, sizeof(freq));
        sort(v[i].begin(), v[i].end());
        r = (i + 1) * sz - 1;
        for (auto p : v[i]) {
            while (r < p.first.first) {
                r++;
                if (!s[r]) continue;
                freq[s[r]]++;
                if (freq[s[r]] > freq[mx] || freq[s[r]] == freq[mx] && s[r] > mx) mx = s[r];
            }
            mxb = mx;
            for (int j = p.first.second; j < min((i + 1) * sz, p.first.first + 1); j++) {
                if (!s[j]) continue;
                freq[s[j]]++;
                if (freq[s[j]] > freq[mxb] || freq[s[j]] == freq[mxb] && s[j] > mxb) mxb = s[j];
            }
            ans[p.second] = mxb;
            for (int j = p.first.second; j < min((i + 1) * sz, p.first.first + 1); j++) if (s[j]) freq[s[j]]--;
        }
    }
    for (int i = 1; i <= q; i++) cout << ans[i] << "\n";
    return 0;
}
