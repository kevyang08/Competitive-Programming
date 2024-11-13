#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int n, m, k, a, res[100001][11];
ll dp[100001];
priority_queue<int> pq[100001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a;
            pq[j].push(a);
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            res[i][j] = pq[i].top() + res[i][j - 1];
            pq[i].pop();
        }
    }
    for (int i = 1; i <= m; i++) {
        // get min and max amounts that could have previously been chosen
        int mn = max(0, i - k), mx = min(i - 1, m - k + 1);
        map<int, ll> tmp;
        for (int j = mn; j <= mx; j++) tmp[j] = dp[j];
        // all the possible totals up until i
        for (int b = mn + 1; b <= min(i, m - k + 1); b++) {
            for (int j = mn; j < b; j++) {
                if (b - j > min(m - i + 1, i)) continue;
                dp[b] = max(dp[b], tmp[j] + res[i][b - j]);
            }

            // cout << i << " " << b << " bruh\n";
        }
    }
    cout << dp[m - k + 1] << "\n";
    return 0;
}