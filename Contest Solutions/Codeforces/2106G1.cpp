#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int t, n, v[1001], f, a, b;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i < n; i++) cin >> a >> b;
        cout << "? 1 1 1" << endl;
        cin >> f;
        if (abs(f) == 2) {
            cout << "? 2 1" << endl;
            f = 0;
        }
        if (abs(f) == 1) v[1] = f;
        for (int i = 2; i <= n; i++) {
            cout << "? 1 1 " << i << endl;
            cin >> v[i];
            v[i] -= f;
        }
        if (!f) {
            cout << "? 2 1" << endl;
            cout << "? 1 1 1" << endl;
            cin >> v[1];
            v[1] /= 2;
        }
        cout << "!";
        for (int i = 1; i <= n; i++) cout << " " << v[i];
        cout << endl;
    }
    return 0;
}