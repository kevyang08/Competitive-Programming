#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int t, n, a[101];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> a[0];
        bool ans = true;
        for (int i = 1; i < n; i++) {
            cin >> a[i];
            if (abs(a[i] - a[i - 1]) != 5 && abs(a[i] - a[i - 1]) != 7) ans = false;
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
    return 0;
}