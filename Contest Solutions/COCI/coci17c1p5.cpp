#include <bits/stdc++.h>
using namespace std;

int n, q, a, b, c = 0, ans;
char op;
set<int> bit[200001];
vector<int> v;
unordered_map<int, int> mp;
vector<pair<char, pair<int, int>>> vq;
void update(int i, int v) {
    for (; i <= 200000; i += (i & -i)) bit[i].insert(v);
}
int query(int i, int v) {
    int res = 0x3f3f3f3f;
    for (; i > 0; i -= (i & -i)) res = min(res, *bit[i].lower_bound(v));
    return res;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    for (int i = 1; i <= 200000; i++) bit[i].insert(0x3f3f3f3f);
    cin >> n >> q;
    for (int i = 0; i < q; i++) {
        cin >> op >> a >> b;
        vq.push_back({op, {a, b}});
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < q; i++) if (i == 0 || v[i] != v[i - 1]) mp[v[i]] = ++c;
    for (auto p : vq) {
        if (p.first == 'M') update(mp[p.second.first], p.second.second);
        else {
            ans = query(mp[p.second.first], p.second.second);
            cout << (ans == 0x3f3f3f3f ? -1 : ans) << "\n";
        }
    }
    return 0;
}
