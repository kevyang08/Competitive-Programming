#include <bits/stdc++.h>
using namespace std;

int n, k, c = 0;
long long a, b, m;
unordered_map<long long, set<int>> idx;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> k >> m;
    for (int i = 0; i < n; i++) {
        cin >> a;
        idx[a].insert(i);
    }
    for (int i = 0; i < n; i++) {
        cin >> b;
        if (idx[m - b].lower_bound(i + k) != idx[m - b].end()) {
            c++;
            idx[m - b].erase(*idx[m - b].lower_bound(i + k));
        }
        else if (idx[m - b].lower_bound(0) != idx[m - b].end() && *idx[m - b].lower_bound(0) + k <= i) {
            c++;
            idx[m - b].erase(*idx[m - b].lower_bound(0));
        }
    }
    cout << c << "\n";
    return 0;
}
