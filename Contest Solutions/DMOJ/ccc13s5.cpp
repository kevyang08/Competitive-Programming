#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// cheesable?

int n, ans = 0;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n;
    while (n > 1) {
        int f = n;
        for (int i = 2; i * i <= n; i++) {
            if (n%i == 0) {
                f = i;
                break;
            }
        }
        int c = n/f;
        n -= c;
        ans += f - 1;
    }
    cout << ans << "\n";
    return 0;
}