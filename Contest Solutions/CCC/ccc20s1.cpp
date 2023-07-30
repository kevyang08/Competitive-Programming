#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n, t, x;
    double ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t >> x;
        v.push_back({t, x});
    }
    sort(v.begin(), v.end());
    for (int i = 1; i < n; i++) ans = max(ans, (double)abs(v[i].second - v[i - 1].second)/(v[i].first - v[i - 1].first));
    cout << ans;
}
