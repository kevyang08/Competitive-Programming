#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int t, n, k, b, c;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<int> bruh(k + 1);
        for (int i = 0; i < k; i++) {
            cin >> b >> c;
            bruh[b] += c;
        }
        int ans = 0;
        sort(bruh.begin(), bruh.end(), greater<int>());
        for (int i = 0; i < min(k, n); i++) ans += bruh[i];
        cout << ans << "\n";
    }
    return 0;
}