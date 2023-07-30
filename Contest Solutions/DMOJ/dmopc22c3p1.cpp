#include <bits/stdc++.h>
using namespace std;

long long n, m;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m;
    if ((n * m)%2 == 0) cout << n * m/2 << " " << n * m/2;
    else cout << (max(n, m) - max(n, m)/2) * min(n, m) << " " << max(n, m)/2 * min(n, m);
}
