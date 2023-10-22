#include <bits/stdc++.h>
using namespace std;

const int sz = 450;

int n, m, q, a[200001], l, r, freq[200001], mx1 = 0, mx2 = 0, mxb1 = 0, mxb2 = 0;
bool ans[200001];
vector<pair<pair<int, int>, int>> v[sz];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> l >> r;
        v[l/sz].push_back({{r, l}, i});
    }
    for (int i = 0; i <= n/sz; i++) {
        mx1 = mx2 = 0;
        memset(freq, 0, sizeof(freq));
        sort(v[i].begin(), v[i].end());
        r = (i + 1) * sz - 1;
        for (auto p : v[i]) {
            while (r < p.first.first) {
                r++;
                if (!a[r]) continue;
                freq[a[r]]++;
                if (a[r] == mx1) continue;
                if (freq[a[r]] > freq[mx1]) {
                    mx2 = mx1;
                    mx1 = a[r];
                }
                else if (freq[a[r]] > freq[mx2]) mx2 = a[r];
            }
            mxb1 = mx1; mxb2 = mx2;
            for (int j = p.first.second; j < min((i + 1) * sz, p.first.first + 1); j++) {
                if (!a[j]) continue;
                freq[a[j]]++;
                if (a[j] == mxb1) continue;
                if (freq[a[j]] > freq[mxb1]) {
                    mxb2 = mxb1;
                    mxb1 = a[j];
                }
                else if (freq[a[j]] > freq[mxb2]) mxb2 = a[j];
            }
            ans[p.second] = freq[mxb1] >= (p.first.first - p.first.second + 1)/3.0 * 2 || freq[mxb1] >= (p.first.first - p.first.second + 1)/3.0 && freq[mxb2] >= (p.first.first - p.first.second + 1)/3.0;
            for (int j = p.first.second; j < min((i + 1) * sz, p.first.first + 1); j++) if (a[j]) freq[a[j]]--;
        }
    }
    for (int i = 1; i <= q; i++) cout << (ans[i] ? "YES" : "NO") << "\n";
    return 0;
}
