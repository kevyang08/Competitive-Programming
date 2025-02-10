#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int t, n, m, k;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        int a = 0, b = 1;
        if (m > n) {
            swap(n, m);
            swap(a, b);
        }
        if (n < k || n - m > k) {
            cout << "-1\n";
            continue;
        }
        for (int i = 0; i < k; i++) cout << a;
        for (int i = 0; i < n - k; i++) cout << b << a;
        for (int i = 0; i < m - n + k; i++) cout << b;
        cout << "\n";
    }
    return 0;
}