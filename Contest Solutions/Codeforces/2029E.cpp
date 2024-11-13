#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

/*
i might be stupid

- if there is more than one prime in a, -1
- else if there is one prime in a, let's say p, then check if p is a generator for every other element
    - how to check? (idk check below)
    - every element must be >= 2 * p
    - other than primes, all impossible value for p seem to be in the range (2 * p, 3 * p)
- else probably just output 2


- random ideas for checking which prime numbers cannot generate some composite number
    
- for all prime factors j of x up to sqrtx:
    - if st[x - j].contains(y) for all j for some number y, then y cannot generate x
*/

int t, n, a[100001], sieve[400001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    for (int i = 2; i <= 400000; i++) {
        if (sieve[i]) continue;
        for (int j = i + i; j <= 400000; j += i) sieve[j] = 1;
    }
    cin >> t;
    while (t--) {
        cin >> n;
        set<int> st;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (!sieve[a[i]]) st.insert(a[i]);
        }
        if (st.size() > 1) cout << "-1\n";
        else if (st.empty()) cout << "2\n";
        else {
            bool ans = true;
            int p = *st.begin();
            for (int i = 1; i <= n; i++) {
                if (a[i] == p) continue;
                if (a[i] < 2 * p) ans = false;
                else if (a[i] < 3 * p) {
                    bool bruh = (a[i] == 2 * p);
                    for (int j = 2; j * j <= a[i]; j++) if (a[i]%j == 0 && a[i] - j >= 2 * p) bruh = true;
                    ans &= bruh;
                }
            }
            if (ans) cout << p << "\n";
            else cout << "-1\n";
        }
    }
    return 0;
}