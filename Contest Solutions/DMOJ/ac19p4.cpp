#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v;
set<pair<int, int>> s;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n, x, y, mx = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        v.push_back({x, y});
        s.insert({x, y});
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s.contains({v[i].first, v[j].second}) && s.contains({v[j].first, v[i].second})) mx = max(mx, abs(v[j].first - v[i].first) * abs(v[j].second - v[i].second));
        }
    }
    cout << mx << "\n";
    return 0;
}
