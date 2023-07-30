#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n, x, c = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        c += x;
        cout << c << "\n";
    }
}
