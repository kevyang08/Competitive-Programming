#include <bits/stdc++.h>
using namespace std;

int t, n, a;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        int c = 0, r = n, mx = 0;
        vector<int> id(n + 1, -1);
        set<pair<int, int>> ed;
        set<int> st;
        auto find = [&](int i, auto &find) -> int {
            return (id[i] < 0 ? i : (id[i] = find(id[i], find)));
        };
        auto join = [&](int u, int v, auto &find) {
            if (id[u = find(u, find)] < id[v = find(v, find)]) {
                id[u] += id[v];
                id[v] = u;
            }
            else {
                id[v] += id[u];
                id[u] = v;
            }
        };
        for (int i = 1; i <= n; i++) {
            cin >> a;
            if (find(a, find) != find(i, find)) {
                join(a, i, find);
                ed.insert({a, i});
                ed.insert({i, a});
            }
            else {
                c += (ed.find({i, a}) == ed.end());
                if (ed.find({i, a}) == ed.end()) r += id[find(a, find)];
            }
        }
        for (int i = 1; i <= n; i++) st.insert(find(i, find));
        cout << c + (r > 0) << " " << st.size() << "\n";
    }
    return 0;
}
 
/*
tips:
- look out for int overflow and array out of bounds
- don't get stuck debugging a wrong solution, take time to think of a new one instead of spamming submissions
- make sure stuestion was read correctly
- for certain problems, solve a few cases by hand and try to make observations
- if behind, stop looking at leaderboard and focus on solving
*/