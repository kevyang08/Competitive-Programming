#include <bits/stdc++.h>
using namespace std;

int t, a, b, c;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        if (a + 1 != c) {
            cout << "-1\n";
            continue;
        }
        int h = (int)ceil(log2(a + 1)), temp = (int)pow(2, h) - a - 1, thing = (int)pow(2, h - 1) - temp;
        cout << h + ceil((b - temp)/max(temp + thing * 2.0, 1.0)) << "\n";
    }
    return 0;
}