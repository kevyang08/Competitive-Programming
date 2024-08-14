#include <bits/stdc++.h>
using namespace std;

int t, n, m, pa, a, x, st[8000010];
char op;
void update(int l, int r, int idx, int i, int v) {
    if (l == r) {
        st[idx] = v;
        return;
    }
    int m = (l + r)/2;
    if (i > m) update(m + 1, r, 2 * idx + 1, i, v);
    else update(l, m, 2 * idx, i, v);
    st[idx] = max(st[2 * idx], st[2 * idx + 1]);
}
int query(int l, int r, int idx, int v) {
    if (l == r) return l;
    int m = (l + r)/2;
    if (st[2 * idx] >= v) return query(l, m, 2 * idx, v);
    else return query(m + 1, r, 2 * idx + 1, v);
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> v;
        set<int> sl;
        set<int, greater<int>> sh;
        cin >> pa;
        v.push_back(pa);
        sl.insert(pa), sh.insert(pa);
        update(1, 2000001, 1, 1, pa - 1);
        for (int i = 1; i < n; i++) {
            cin >> a;
            sl.insert(a), sh.insert(a);
            v.push_back(a);
            update(1, 2000001, 1, pa + 1, a - pa - 1);
            pa = a;
        }
        update(1, 2000001, 1, pa + 1, 0x3f3f3f3f);
        cin >> m;
        while (m--) {
            cin >> op >> x;
            if (op == '+') {
                int lo = (sh.lower_bound(x) != sh.end() ? *sh.lower_bound(x) : 0);
                int hi = (sl.lower_bound(x) != sl.end() ? *sl.lower_bound(x) : 0x3f3f3f3f);
                update(1, 2000001, 1, lo + 1, x - lo - 1);
                update(1, 2000001, 1, x + 1, hi - x - 1);
                sl.insert(x), sh.insert(x);
                v.push_back(x);
            }
            else if (op == '-') {
                update(1, 2000001, 1, x + 1, 0);
                sl.erase(x), sh.erase(x);
                int lo = (sh.lower_bound(x) != sh.end() ? *sh.lower_bound(x) : 0);
                int hi = (sl.lower_bound(x) != sl.end() ? *sl.lower_bound(x) : 0x3f3f3f3f);
                update(1, 2000001, 1, lo + 1, hi - lo - 1);
            }
            else cout << query(1, 2000001, 1, x) << " ";
        }
        cout << "\n";
        update(1, 2000001, 1, 1, 0);
        for (int i : v) update(1, 2000001, 1, i + 1, 0);
    }
    return 0;
}