#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

class Comp {
public:
    bool operator() (pair<ll, ll> a, pair<ll, ll> b) {
        return (double)((a.fi + 1) * a.se - a.fi * (a.se + 1))/(a.se * a.se + a.se) <= (double)((b.fi + 1) * b.se - b.fi * (b.se + 1))/(b.se * b.se + b.se);
    }
};
int n, k;
ll a[200001], b;
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, Comp> pq;
double ans = 0;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        cin >> b;
        pq.push({a[i], b});
    }
    while (k--) {
        auto [f, s] = pq.top(); pq.pop();
        // cout << f << " " << s << " bruh\n";
        pq.push({f + 1, s + 1});
    }
    while (!pq.empty()) {
        auto [f, s] = pq.top(); pq.pop();
        ans += (double)f/s;
    }
    cout << fixed << setprecision(6) << ans/n * 100 << "\n";
    return 0;
}