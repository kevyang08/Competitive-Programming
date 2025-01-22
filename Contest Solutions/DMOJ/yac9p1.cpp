#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int n, a[200005], b, idx[200005], ans = 0;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        cin >> b;
        idx[b] = i;
    }
    for (int i = 2; i <= n; i++) if (idx[a[i]] != idx[a[i - 1]] + 1) ++ans;
    cout << ans + 1 << "\n";
    return 0;
}