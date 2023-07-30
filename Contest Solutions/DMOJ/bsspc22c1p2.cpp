#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n, a, b;
    cin >> n;
    while (n--) {
        cin >> a >> b;
        if (a%10 == 7 && a%100 != 17 && b%100 == 11 || b%10 == 7 && b%100 != 17 && a%100 == 11) cout << "YES\n";
        else cout << "NO\n";
    }
}
