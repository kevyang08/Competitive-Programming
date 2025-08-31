#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
// const int M = 998244353
const int M = 1e9 + 7;

int t, n, a[1005], r[1005], b[1005];
void solve() {
    cin >> n;
    r[n] = 1, r[n + 1] = 0;
    fill(a, a + n + 1, 0);
    cout << "throw " << n - 1 << endl;
    cin >> r[n - 1];
    a[n - 1] = 3 - r[n - 1];
    cout << "swap " << n - 1 << endl;
    cout << "throw " << n - 1 << endl;
    cin >> r[n - 1];
    a[n] = 3 - r[n - 1];
    b[n - 1] = n, b[n] = n - 1;
    for (int i = n - 2; i > 0; i--) {
        b[i] = i;
        if (a[i + 1] && r[i + 1] == r[i + 2] && i > 1) continue;
        if (!a[i + 1]) {
            swap(b[i], b[i + 1]);
            cout << "throw " << i << endl;
            cin >> r[i];
            a[i] = (r[i] == r[i + 2] + 1 ? 2 : 1);
            r[i + 1] = r[i + 1 + a[i]] + 1;
            cout << "swap " << i << endl;
            cout << "throw " << i << endl;
            cin >> r[i];
            a[i + 1] = (r[i] == r[i + 1] + 1 ? 1 : 2);
            continue;
        }
        int x = i;
        if (r[i + 1] == r[i + 2]) {
            cout << "swap " << i << endl;
            swap(b[i], b[i + 1]);
            ++x;
        }
        assert(r[x + 1] != r[x + 2]);
        cout << "throw " << x << endl;
        cin >> r[x];
        a[i] = (r[x] == r[x + 1] + 1 ? 1 : 2);
        if (x != i) {
            r[i] = r[i + a[b[i]]] + 1;
            // cout << i << " " << r[i] << " " << b[i] << " here" << endl;
        }
        // cout << i << " " << r[i] << " " << r[i + 1] << endl;
    }
    cout << "!";
    for (int i = 1; i <= n; i++) cout << " " << a[i];
    cout << endl;
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