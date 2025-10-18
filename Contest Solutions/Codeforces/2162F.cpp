#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
// const int M = 998244353;
const int M = 1e9 + 7;

/*
- if all intervals cover some index, put 0 at that index
- else if there is some index not covered, put 0 at that index
- else if there is some index such that it is not both the start and end of some intervals, 
  put 0 at that index and 1 either before or after accordingly
    - guarantees {0, 2} \subseteq M, but 1 \notin M
- else, we are guaranteed {0, 1} \subseteq M
    - can we guarantee that 2 \notin M?
    - yes: since n > 2, just put 0 and 1 as far from each other as possible
*/

int t;
void solve() {
    int n, m, l, r;
    cin >> n >> m;
    vector<int> a(n + 5);
    vector<int> ss(n + 5), es(n + 5);
    for (int i = 0; i < m; i++) {
        cin >> l >> r;
        ss[l] = 1, es[r] = 1;
        ++a[l], --a[r + 1];
    }
    int idx = 0, idx1 = 0;
    for (int i = 1; i <= n; i++) {
        a[i] += a[i - 1];
        if (a[i] == m) {
            idx = i;
            break;
        }
    }
    if (!idx) {
        for (int i = 1; i <= n; i++) 
            if (!a[i]) {
                idx = i;
                break;
            }
    }
    if (idx) {
        for (int i = 1, j = 1; i <= n; i++) cout << (i == idx ? 0 : j++) << (i == n ? "\n" : " ");
        return;
    }
    idx = 1, idx1 = n;
    for (int i = 1; i <= n; i++) {
        if (ss[i] && es[i]) continue;
        idx = i;
        if (!es[i]) idx1 = i + 1;
        else idx1 = i - 1;
        break;
    }
    for (int i = 1, j = 2; i <= n; i++) cout << (i == idx ? 0 : (i == idx1 ? 1 : j++)) << (i == n ? "\n" : " ");
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}