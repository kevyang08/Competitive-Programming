#include <bits/stdc++.h>
using namespace std;

bool sieve1[31625], sieve2[5000001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    for (int i = 2; i < 31625; i++) sieve1[i] = true;
    for (int i = 0; i < 5000001; i++) sieve2[i] = true;
    int n, m;
    cin >> n >> m;
    if (n == 1) sieve2[0] = false;
    for (int i = 2; i < 31625; i++) {
        if (sieve1[i]) {
            for (int j = i * i; j < 31625; j += i) sieve1[j] = false;
            for (int j = n/i * i + (n%i != 0 ? i : 0); j <= m; j += i) if (j >= n && j > i && sieve2[j - n]) sieve2[j - n] = false;
        }
    }
    for (int i = 0; i <= m - n; i++) if (sieve2[i]) cout << n + i << "\n";
}
