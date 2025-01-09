#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int n, k, a, cnt = 0;
vector<int> v;
ll ans = 0;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a;
        v.push_back(a);
        cnt += (a < 0 ? 2 : (a > 0 ? 1 : 0));
    }
    if (k >= cnt) {
        for (int i = 0; i < n; i++) ans += abs(v[i]);
    }
    else {
        sort(v.begin(), v.end(), [&](auto a, auto b) {
            if (a >= 0 && b >= 0) return a > b;
            else if (a < 0 && b < 0) return a < b;
            else if (a >= 0 && b < 0) return abs(b)/2.0 < a;
            else return abs(a)/2.0 > b;
        });
        int idx = 0, p = 0; // previous costing 1
        while (k) {
            if (idx >= n || !v[idx] || k < 0) break;
            if (v[idx] > 0) {
                p = v[idx++];
                ans += p;
                --k;
            }
            else if (k > 1) {
                ans -= v[idx++];
                k -= 2;
            }
            else {
                int mx = 0, tmp = v[idx];
                while (idx < n && v[idx]) {
                    if (v[idx] > 0) {
                        mx = v[idx];
                        break;
                    }
                    ++idx;
                }
                ans = (p ? max(ans + mx, ans - p - tmp) : ans + mx);
                --k;
                break;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}