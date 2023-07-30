#include <bits/stdc++.h>
using namespace std;

int n, h, p = -1, a = 0, b = 1, ansa = 1, ansb = 1;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> h;
        if (h > p) {
            b = 1;
            a++;
        }
        else if (h < p) {
            a = 1;
            b++;
        }
        else a = b = 1;
        ansa = max(a, ansa);
        ansb = max(b, ansb);
        p = h;
    }
    cout << ansa << "\n";
    cout << ansb << "\n";
}
