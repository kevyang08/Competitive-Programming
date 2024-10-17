#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t, n, ans[10000005];
bool sieve[10000005];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    freopen("prime_subtractorization_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    for (int i = 2; i <= 10000000; i++) {
        if (sieve[i]) continue;
        for (int j = i + i; j <= 10000000; j += i) sieve[j] = true;
    }
    ans[5] = 1;
    for (int i = 5; i <= 10000000; i++) {
        ans[i] += ans[i - 1];
        if (!sieve[i] && !sieve[i - 2]) ++ans[i];
    }
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        cin >> n;
        cout << ans[n] << "\n";
    }
    return 0;
}