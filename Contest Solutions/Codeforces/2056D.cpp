#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int t, n, a[100005], cnt[2][200005], off[2];
queue<int> q[2];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        ll ans = (ll)n * (n + 1)/2;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int k = 1; k < 10; k++) {
            off[0] = off[1] = 0;
            while (!q[0].empty()) q[0].pop();
            while (!q[1].empty()) q[1].pop();
            for (int i = 0; i <= n; i++) cnt[0][100000 + i] = cnt[0][100000 - i] = cnt[1][100000 + i] = cnt[1][100000 - i] = 0;
            for (int i = 2; i <= n; i++) {
                int bruh = (a[i] == k || a[i - 1] == k);
                int tmp = (a[i] > k ? 1 : -1) + (a[i - 1] > k ? 1 : -1);
                q[i%2].push(off[i%2]);
                if (bruh) {
                    while (!q[i%2].empty()) {
                        cnt[i%2][100000 + q[i%2].front()]++;
                        q[i%2].pop();
                    }
                }
                off[i%2] -= tmp;
                ans -= cnt[i%2][100000 + off[i%2]];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}