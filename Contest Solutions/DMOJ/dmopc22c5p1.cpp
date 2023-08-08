#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    long long n;
    cin >> n;
    if (n < 4) cout << "0\n";
    else {
        long long mx = 0;
        for (long long i = 1; i * 2 <= n - 2; i++) mx = max(mx, (n - i * 2) * (n - i * 2 - 1)/2 * i);
        cout << mx << "\n";
    }
    return 0;
}
