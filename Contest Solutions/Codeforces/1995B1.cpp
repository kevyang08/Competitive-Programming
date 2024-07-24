#include <bits/stdc++.h>
using namespace std;

int t, n;
long long m, a;
map<long long, long long> mp;
vector<pair<long long, long long>> v;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        long long ans = 0;
        cin >> n >> m;
        v.clear();
        mp.clear();
        for (int i = 0; i < n; i++) {
            cin >> a;
            ++mp[a];
        }
        for (auto &[a, b] : mp) v.push_back({a, b});
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++) {
            long long res = m/v[i].first, rem = m%v[i].first;
            if (res <= v[i].second) {
                ans = max(ans, res * v[i].first);
                if (i + 1 < v.size() && v[i + 1].first == v[i].first + 1) {
                    long long temp = min(res, min(rem, v[i + 1].second));
                    res -= temp;
                    ans = max(ans, res * v[i].first + temp * v[i + 1].first);
                }
            }
            else {
                res = v[i].second;
                ans = max(ans, res * v[i].first);
                if (i + 1 < v.size() && v[i + 1].first == v[i].first + 1) {
                    long long temp = (m - res * v[i].first)/v[i + 1].first;
                    if (temp >= v[i + 1].second) temp = v[i + 1].second;
                    else {
                        long long bruh = min(res, min(v[i + 1].second - temp, m - res * v[i].first - temp * v[i + 1].first));
                        res -= bruh, temp += bruh;
                    }
                    ans = max(ans, res * v[i].first + temp * v[i + 1].first);
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}