#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int t, n, a;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        int pcnt = 0;
        ll ans = 0;
        vector<int> cnt(n + 1), fcnt(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a;
            int tmp = a, f = 0;
            for (int k = 2; k * k <= a && a != -1; k++) {
                if (tmp%k) continue;
                while (tmp > k && tmp%k == 0) {
                    tmp /= k;
                    if (!f) f = k;
                    else {
                        tmp = -1;
                        break;
                    }
                }
            }
            if (tmp == -1) continue;
            ++cnt[a];
            if (tmp == f) tmp = 0;
            if (!f) {
                ++pcnt;
                ans += pcnt - cnt[a] + fcnt[a];
            }
            else {
                ++fcnt[f], ++fcnt[tmp];
                ans += cnt[a] + cnt[f] + cnt[tmp];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}