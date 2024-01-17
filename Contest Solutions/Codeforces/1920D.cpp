#include <bits/stdc++.h>
using namespace std;

int t, n, q, b, x, idx = 0;
long long k;
vector<int> v[64];
vector<pair<long long, long long>> p;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        for (int i = 0; i <= idx; i++) v[i].clear();
        p.clear();
        p.push_back({0, 0});
        idx = 0;
        cin >> n >> q;
        for (int i = 0; i < n; i++) {
            cin >> b >> x;
            if (p[idx].first * p[idx].second + v[idx].size() >= (long long)1e18) continue;
            if (b == 1) v[idx].push_back(x);
            else {
                p.push_back({p[idx].first * p[idx].second + v[idx].size(), x + 1});
                ++idx;
            }
            if (ceil(1e18/p[idx].first) < p[idx].second) {
                p[idx].second = (long long)ceil(1e18/p[idx].first);
                v[idx].clear();
            }
        }
        for (int i = 0; i < q; i++) {
            cin >> k;
            for (int j = idx; j >= 0; j--) {
                long long temp = k - p[j].first * p[j].second;
                if (temp > 0) {
                    cout << v[j][(int)temp - 1] << (i == q - 1 ? "\n" : " ");
                    break;
                }
                else k = (k%p[j].first == 0 ? p[j].first : k%p[j].first);
            }
        }
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
