#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int t;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        int n, a, cnt = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a;
            if (a == 1) ++cnt;
        }
        cout << (cnt%2 ? "Josh\n" : "Mike\n");
    }
    return 0;
}