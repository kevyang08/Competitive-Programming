#include <bits/stdc++.h>
using namespace std;

int n, a, q, x, y, idx[150001], bruh[150001];
vector<pair<long long, int>> v;
long long ans = 0;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    v.push_back({0, 0});
    for (int i = 1; i <= n; i++) {
        cin >> a;
        v.push_back({a, i});
    }
    sort(v.begin(), v.end());
    for (int i = 1; i <= n; i++) {
        idx[v[i].second] = i;
        ans += v[i].first * i;
        bruh[i] = v[i].first;
        v[i].first += v[i - 1].first;
    }
    cin >> q;
    while (q--) {
        cin >> x >> y;
        int l = 1, r = n, thing = 0;
        while (l <= r) {
            int m = (l + r)/2;
            if (y >= bruh[m]) {
                thing = m;
                l = m + 1;
            }
            else r = m - 1;
        }
        long long res = ans - (long long)bruh[idx[x]] * idx[x] + (long long)y * (thing + 1);
        if (thing + 1 < idx[x]) res += v[idx[x] - 1].first - v[thing].first;
        else if (thing + 1 > idx[x]) res -= v[thing].first - v[idx[x]].first + y;
        cout << res << "\n";
    }
    return 0;
}
