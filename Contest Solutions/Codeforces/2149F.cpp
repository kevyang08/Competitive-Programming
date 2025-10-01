#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
// const int M = 998244353
const int M = 1e9 + 7;

/*
find min number of rests
- binary search
- how to check if # of rests can be satisfied?
*/

int t, h, d;
void solve() {
    cin >> h >> d;
    int l = 0, r = d;
    while (l < r) {
        int m = (l + r)/2;
        ll tmp = d/(m + 1);
        if (tmp * (m + 1) < d) ++tmp;
        int lo = 1, hi = m + 1;
        while (lo < hi) {
            int mid = (lo + hi)/2;
            if (mid * tmp + (m + 1 - mid) * (tmp - 1) >= d) hi = mid;
            else lo = mid + 1;
        }
        if (h + m > hi * tmp * (tmp + 1)/2 + (m + 1 - hi) * tmp * (tmp - 1)/2) r = m;
        else l = m + 1;
    }
    cout << d + l << '\n';
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

/*
10 7
9 7 8 7 5 6 5 3  
1 2 2 3 4 4 5 6 7
*/