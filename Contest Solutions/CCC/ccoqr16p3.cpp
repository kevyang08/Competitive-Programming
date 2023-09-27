#include <bits/stdc++.h>
using namespace std;

int n, m, r, c, idp = 0, idx = 0;
long long ans = 0, mx = 0;
vector<pair<int, int>> v;
vector<int> vi;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> r >> c;
        v.push_back({c, r});
        vi.push_back(c);
    }
    vi.push_back(n + 1);
    sort(v.begin(), v.end());
    sort(vi.begin(), vi.end());
    for (int i : vi) {
        ans += mx * (mx + 1)/2;
        if (mx > (i - idp)) {
            ans -= (mx - (i - idp)) * (mx - (i - idp) + 1)/2;
            mx -= (i - idp);
        }
        else mx = 0;
        while (idx < m && v[idx].first == i) mx = max(mx, n - v[idx++].second + 1LL);
        idp = i;
    }
    cout << ans << "\n";
    return 0;
}

/*
https://dmoj.ca/problem/ccoqr16p3

- line sweep
- sweep along columns, keeping track of previous index
- maintain maximum height n - r + 1 (height decreases by 1 every column)
- when encountering a new index:
    - if mx > i - idp: ans += sum(1, mx) - sum(1, mx - (i - idp))
    - else: ans += sum(1, mx)
    - mx = max(0, mx - (i - idp))
*/
