/* note: no need for coordinate compression, using a map to store the answers would work
   and is also a lot easier*/
#include <bits/stdc++.h>
using namespace std;
 
#define fi first
#define se second
 
int t, n, q, l, r, a, b, x[200000], ans[600000];
bool comp(pair<int, int> a, pair<int, int> b) {
    return a.se < b.se || a.se == b.se && a.fi > b.fi;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> t;
    while (t--) {
        int cnt = 0;
        cin >> n;
        vector<int> cds;
        unordered_map<int, int> mp, idx;
        deque<pair<int, int>> dq;
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            cin >> l >> r >> a >> b;
            cds.push_back(l);
            cds.push_back(b);
            v.push_back({l, b});
        }
        cin >> q;
        for (int i = 0; i < q; i++) {
            cin >> x[i];
            cds.push_back(x[i]);
        }
        sort(cds.begin(), cds.end());
        for (int i = 0; i < cds.size(); i++) {
            if (i > 0 && cds[i] == cds[i - 1]) continue;
            mp[cnt] = cds[i];
            idx[cds[i]] = cnt++;
        }
        sort(v.begin(), v.end(), comp);
        int idv = n - 1;
        for (int i = cnt - 1; i >= 0; i--) {
            while (!dq.empty() && dq.front().fi > i) dq.pop_front();
            while (idv >= 0 && idx[v[idv].se] == i) {
                while (!dq.empty() && dq.back().se == idx[v[idv].se] && idx[v[idv].fi] <= dq.back().fi) dq.pop_back();
                dq.push_back({idx[v[idv].fi], idx[v[idv].se]});
                idv--;
            }
            if (dq.empty() || dq.front().se == i) ans[i] = i;
            else ans[i] = (ans[dq.front().se] ? ans[dq.front().se] : dq.front().se);
        }
        for (int i = 0; i < q; i++) cout << (i == 0 ? "" : " ") << mp[ans[idx[x[i]]]];
        cout << "\n";
    }
    return 0;
}
