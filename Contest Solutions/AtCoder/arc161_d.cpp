#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
// const int M = 998244353;
const int M = 1e9 + 7;

ll n, d;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> d;
    if (d * n > n * (n - 1)/2) {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    for (int k = 1; k <= d; k++) {
        for (int i = 1; i <= n; i++) {
            cout << i << " " << (i + k - 1)%n + 1 << "\n";
        }
    }
    return 0;
}