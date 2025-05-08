#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int n, dp[1 << 24], ans = 0;
string s;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        int a = (1 << (s[0] - 'a')), b = (1 << (s[1] - 'a')), c = (1 << (s[2] - 'a'));
        ++dp[a], ++dp[b], ++dp[c];
        --dp[a | b], --dp[a | c], --dp[b | c];
        ++dp[a | b | c];
    }
    for (int i = 0; i < 24; i++)
        for (int x = 0; x < (1 << 24); x++)
            if (x & (1 << i)) dp[x] += dp[x ^ (1 << i)];
    for (int x = 0; x < (1 << 24); x++) ans ^= dp[x] * dp[x];
    cout << ans << "\n";
    return 0;
}