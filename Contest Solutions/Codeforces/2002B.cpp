#include <bits/stdc++.h>
using namespace std;

int t, n, a[300001], b[300001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        bool bob = true, revbob = true;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
            if (b[i] != a[i]) bob = false;
            if (b[i] != a[n - i + 1]) revbob = false;
        }
        cout << (bob || revbob || n < 3 ? "Bob\n" : "Alice\n");
    }
    return 0;
}

/*
4
1 2 3 4
2 1 3 4

5
5 3 2 4 1
1 4 2 3 5
*/