/**
 * https://dmoj.ca/problem/coi09p1
 * 
 * there will be maximum 1000000 different coordinates -> can use coordinate compression
 * can use fenwick tree to store all of them
 * can go row by row:
 * - sort oaks by row, then by column
 * - iterate through the oaks in the current row, keeping track of the current index in the vector
 * - update the coordinate in fenwick tree
 * - do the same with queries, keeping track of the row, left, and right indices, as well as the query number
 * - add the result to the corresponding query index
 * repeat with columns
 * 
 * time complexity: O(NlogN)
*/
/* note: there is a much easier solution using binary search */

#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

int n, p, a, b, c, d, bit[1000001], ans[100001], cnt = 0, idvc = 0, idvp = 0, idq = 0;
unordered_map<int, int> mp;
vector<int> coords;
vector<pair<int, int>> v;
vector<pair<pair<int, int>, pair<int, int>>> qx, qy;
bool comp(pair<int, int> a, pair<int, int> b) {
    return a.se < b.se || a.se == b.se && a.fi < b.fi;
}
void update(int i, int v) {
    for (; i <= 1000000; i += (i & -i)) bit[i] += v;
}
int query(int i) {
    int res = 0;
    for (; i > 0; i -= (i & -i)) res += bit[i];
    return res;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        coords.push_back(a);
        coords.push_back(b);
        v.push_back({b, a});
    }
    cin >> p;
    for (int i = 1; i <= p; i++) {
        cin >> a >> b >> c >> d;
        coords.push_back(a);
        coords.push_back(b);
        coords.push_back(c);
        coords.push_back(d);
        qx.push_back({{b, i}, {a, c}});
        qx.push_back({{d, i}, {a, c}});
        qy.push_back({{a, i}, {b, d}});
        qy.push_back({{c, i}, {b, d}});
    }
    sort(coords.begin(), coords.end());
    for (int i = 0; i < coords.size(); i++) {
        if (i > 0 && coords[i] == coords[i - 1]) continue;
        mp[coords[i]] = ++cnt;
    }
    sort(v.begin(), v.end());
    sort(qx.begin(), qx.end());
    for (int i = 1; i <= 1000000; i++) {
        while (idvc < n && mp[v[idvc].fi] == i) update(mp[v[idvc++].se], 1);
        // we dont want to double count trees on corners
        while (idq < 2 * p && mp[qx[idq].fi.fi] == i) {ans[qx[idq].fi.se] += query(mp[qx[idq].se.se] - 1) - query(mp[qx[idq].se.fi]); idq++;}
        while (idvp < idvc) update(mp[v[idvp++].se], -1);
    }
    idvc = idvp = idq = 0;
    sort(v.begin(), v.end(), comp);
    sort(qy.begin(), qy.end());
    for (int i = 1; i <= 1000000; i++) {
        while (idvc < n && mp[v[idvc].se] == i) update(mp[v[idvc++].fi], 1);
        while (idq < 2 * p && mp[qy[idq].fi.fi] == i) {ans[qy[idq].fi.se] += query(mp[qy[idq].se.se]) - query(mp[qy[idq].se.fi] - 1); idq++;}
        while (idvp < idvc) update(mp[v[idvp++].fi], -1);
    }
    for (int i = 1; i <= p; i++) cout << ans[i] << "\n";
    return 0;
}
