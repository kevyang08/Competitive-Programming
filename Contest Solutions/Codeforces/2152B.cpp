#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
// const int M = 998244353;
const int M = 1e9 + 7;

int t, n, rk, ck, rd, cd;
void solve() {
    cin >> n >> rk >> ck >> rd >> cd;
    int ans = 0;
    if (rk == rd) {
        if (ck < cd) ans = ck;
        else ans = n - ck;
        ans += abs(ck - cd);
    }
    else if (ck == cd) {
        if (rk < rd) ans = rk;
        else ans = n - rk;
        ans += abs(rk - rd);
    }
    else {
        if (rk > rd) {
            // ans = n - rk + (n - rk < abs(ck - cd);
            if (n - rk <= abs(ck - cd)) {
                if (ck > cd) ans = n - min(rd, cd);
                else ans = max(cd, n - rd);
            }
            else ans = n - rk + abs(rk - rd);
        }
        else {
            if (rk <= abs(ck - cd)) {
                if (ck > cd) ans = max(rd, n - cd);
                else ans = max(rd, cd);
            }
            else ans = rk + abs(rk - rd);
        }
        if (ck > cd) {
            int tmp;
            if (n - ck <= abs(rk - rd)) {
                if (rk > rd) tmp = n - min(rd, cd);
                else tmp = max(rd, n - cd);
            }
            else tmp = n - ck + abs(ck - cd);
            ans = max(tmp, ans);
        }
        else {
            int tmp;
            if (ck <= abs(rk - rd)) {
                if (rk > rd) tmp = max(n - rd, cd);
                else tmp = max(rd, cd);
            }
            else tmp = ck + abs(ck - cd);
            ans = max(tmp, ans);
        }
        // ans += min(abs(rk - rd), abs(ck - cd));
    }
    cout << ans << "\n";
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