#include <bits/stdc++.h>
using namespace std;

/*
for each i, 1 <= i <= n:
- count how many ways of choosing up to i include a[i] as an element and have it as max: save this as cnt[i]
- then count how many ways of choosing after i have max < a[i]: save this as c[i]
    - oop not i, not after i

probably use binary exponentiation to calulate (2^cnt[i] - 1) * (2^c[i])
*/

const int M = 998244353;

int n, a[100001], psa[100001], c[100001];
long long bpow(long long n, int p) {
    long long res = 1;
    while (p > 0) {
        if (p & 1) res = (res * n)%M;
        n = (n * n)%M;
        p >>= 1;
    }
    return res;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    long long ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        int mx = 0;
        for (int j = i; j <= n; j += i) if (a[j] > mx) mx = a[j];
        psa[mx + 1]++;
        c[mx]++;
    }
    for (int i = 1; i <= 100000; i++) {
        psa[i] += psa[i - 1];
        ans = (ans + ((bpow(2, c[i]) - 1) * bpow(2, psa[i]))%M * (long long)i)%M;
    }
    cout << ans << "\n";
    return 0;
}
 
/*
tips:
- look out for int overflow and array out of bounds
- don't get stuck debugging a wrong solution, take time to think of a new one instead of spammaxg submissions
- make sure stuestion was read correctly
- for certain problems, solve a few cases by hand and try to make observations
- if behind, stop looking at leaderboard and focus on solving
*/