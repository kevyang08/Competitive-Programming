#include <bits/stdc++.h>
using namespace std;

int n, x, y, r, idx = 0, lo[10], hi[10];
bool thing = true;
vector<pair<pair<int, int>, pair<int, int>>> v;
vector<pair<int, pair<int, int>>> cr, nx;
long long ans = 0;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y >> r;
        v.push_back({{x, y}, {0, i}});
        v.push_back({{x, y + r}, {-1, i}});
    }
    sort(v.begin(), v.end());
    for (int i = 1; i <= 2000000; i++) {
        for (auto p : nx) cr.push_back(p);
        while (idx < 2 * n && v[idx].first.first == i) {
            cr.push_back({v[idx].first.second, v[idx].second});
            if (v[idx].second.first) hi[v[idx].second.second] = v[idx].first.second;
            else lo[v[idx].second.second] = v[idx].first.second;
            idx++;
        }
        sort(cr.begin(), cr.end());
        int pr = 0, pd = 0;
        for (auto p : cr) {
            thing ^= 1;
            if (thing) {
                ans += (p.first - pr) * 2;
                if (p.second.first != pd) ans--;
                if (p.second.first == 0 && pd == -1) ans += 2;
            }
            pr = p.first;
            pd = p.second.first;
        }
        nx.clear();
        for (int j = 0; j < cr.size(); j++) {
            if (hi[cr[j].second.second] - lo[cr[j].second.second] <= 1) continue;
            nx.push_back({cr[j].first + cr[j].second.first, cr[j].second});
        }
        for (int i = 0; i < n; i++) hi[i]--;
        cr.clear();
    }
    printf("%.1f\n", ans/2.0);
    return 0;
}

/* fixed
4
1 1 1
1 2 1
2 1 1
1 1 2

Expected: 0.5
Got: -0.5
*/

/* fixed
2
1 2 3
2 1 2

Expected: 5.5
Got: 6.5
*/
