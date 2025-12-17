#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
// const int M = 998244353;
const int M = 1e9 + 7;

int n, l, a[10001], q, k[101], idx[10001], ans[10001][101];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> l;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> q;
    vector<int> v;
    for (int i = 0; i < q; i++) {
        cin >> k[i];
        v.push_back(k[i]);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < q; i++) idx[v[i]] = i + 1;
    for (int i = l, j = 0; i >= 0; i--) {
        if (idx[i]) j = idx[i];
        idx[i] = j;
    }
    for (int j = 1; j <= n - l; j++) {
        int diff = 0;
        for (int i = 1; i + j <= n; i++) {
            if (i > l) diff -= (a[i - l] != a[i + j - l]);
            diff += (a[i] != a[i + j]);
            if (i < l || !idx[diff]) continue;
            ++ans[i - l + 1][idx[diff]];
            ++ans[i + j - l + 1][idx[diff]];
        }
    }
    for (int i = 1; i <= n - l + 1; i++) for (int j = 1; j <= q; j++) ans[i][j] += ans[i][j - 1];
    for (int j = 0; j < q; j++) {
        int id = idx[k[j]];
        for (int i = 1; i <= n - l + 1; i++) cout << ans[i][id] << ' ';
        cout << '\n';
    }
    return 0;
}