#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    long long n, s = 1;
    cin >> n;
    for (long long i = 2; s < n; i++) {
        if ((n - s)%i == 0) cout << (n - s)/i << " " << (n - s - i)/i + i << "\n";
        s += i;
    }
    return 0;
}
