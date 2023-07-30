#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool sieve1[100001], sieve2[20000000];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    for (int i = 0; i < 100001; i++) sieve1[i] = true;
    for (int i = 0; i < 20000000; i++) sieve2[i] = true;
    ll n, m;
    cin >> n >> m;
    int c = (int)(m - n);
    if (n == 1) c--;
    for (ll i = 2; i < 100001; i++) {
        if (sieve1[(int)i]) {
            for (ll j = i * i; j < 100001; j += i) sieve1[(int)j] = false;
            for (ll j = n/i * i + (n%i != 0 ? i : 0); j < m; j += i) {
                if (j >= n && j > i && sieve2[(int)(j - n)]) {
                    c--;
                    sieve2[(int)(j - n)] = false;
                }
            }
        }
    }
    cout << c << "\n";
}
