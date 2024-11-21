#include <bits/stdc++.h>
using namespace std;

/*
- we can prime factorize each number and calculate the number of ways to reach that prime factor so far
- for each prime factor p1, we can also check all the prime factors p2 < p1 and subtract ways[p1 * p2]
- at the end we simply go through each one and sum it up
- hypothetically should be O(nlognlogn) space, O(nsqrtnlogn + nlognlogn) time
    - precompute primes instead

- bruh wtf the max number of prime factors is 7, so looking at each subset would be 128 * 7 * n
    - we can now use inclusion-exclusion principle
- bruh #2 wrong mod
*/

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

const int M = 998244353;

int n, a;
ll dp[1000001], ans = 0;
vector<ll> p[1000001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 2; i <= 1000000; i++) {
        if (!p[i].empty()) continue;
        for (int j = i; j <= 1000000; j += i) p[j].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        cin >> a;
        ll ways = (i == 1);
        for (int k = (1 << p[a].size()) - 1; k > 0; k--) {
            ll tmp = 1, cnt = __builtin_popcount(k);
            for (int j = 0; j < p[a].size(); j++) if ((1 << j) & k) tmp *= p[a][j];
            if (cnt%2) ways = (ways + dp[tmp])%M;
            else ways = (ways - dp[tmp] + M)%M;

            // cout << i << " " << tmp << " " << dp[tmp] << " wtf man\n";
        }
        // for (int j = 0; j < p.size(); j++) dp[p[a][j]] = (dp[p[j]] + ways)%M;
        for (int k = (1 << p[a].size()) - 1; k > 0; k--) {
            int tmp = 1, cnt = __builtin_popcount(k);
            for (int j = 0; j < p[a].size(); j++) if ((1 << j) & k) tmp *= p[a][j];
            dp[tmp] = (dp[tmp] + ways)%M;
        }
        if (i == n) ans = ways;


        // cout << ways << " bruh\n";
        // cout << i << "\n";
        // for (auto j : cur) cout << j << " ";
        // cout << "\nbruh\n";
    }
    cout << ans << "\n";
    return 0;
}