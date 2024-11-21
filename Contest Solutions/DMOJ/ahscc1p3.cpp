#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int n, psa[1000001], ans = 0, cur = 0;
string s, t;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> s >> t;
    for (int i = 1; i < n; i++) psa[i] = psa[i - 1] + (s[i - 1] == t[i - 1]);
    ans = psa[n - 1];
    for (int i = n; i > 1; i--) {
        cur += (s[i - 1] == t[i - 2]);
        ans = max(ans, cur + psa[i - 2]);
    }
    cout << ans << "\n";
    return 0;
}