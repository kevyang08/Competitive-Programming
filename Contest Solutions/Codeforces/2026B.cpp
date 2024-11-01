#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int t, n;
ll a[2001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        ll k = 0;
        for (int i = 1; i <= n; i++) cin >> a[i];
        if (n == 1) k = 1;
        else if (n%2) {
            k = INFL;
            vector<ll> mx(n + 1);
            for (int i = 2; i < n; i += 2) mx[i] = max(mx[i - 2], a[i] - a[i - 1]);
            k = mx[n - 1];
            ll thing = 0;
            for (int i = n; i > 1; i -= 2) {
                thing = max(thing, a[i] - a[i - 1]);
                k = min(k, max(thing, mx[i - 3]));
            }
            k = min(k, thing);
        }
        else for (int i = 1; i < n; i += 2) k = max(k, a[i + 1] - a[i]);
        cout << k << "\n";
    }
    return 0;
}