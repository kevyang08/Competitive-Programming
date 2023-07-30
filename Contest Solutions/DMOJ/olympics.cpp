#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, b, s, g, p;
    cin >> n >> b >> s >> g;
    p = b + 3 * s + 5 * g;
    if (n >= p) {
        cout << (n - p)/5 + 1;
    }
    else {
        cout << 0;
    }
    return 0;
}
