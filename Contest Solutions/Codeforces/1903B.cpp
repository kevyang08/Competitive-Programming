#include <bits/stdc++.h>
using namespace std;
 
int t, n, a[1001][1001], arr[1001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        bool ans = true;
        for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> a[i][j];
        for (int i = 1; i <= n; i++) {
            arr[i] = INT_MAX >> 1;
            for (int j = 1; j <= n; j++) {
                if (j == i) continue;
                arr[i] &= a[i][j];
            }
        }
        for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) if (i != j && (arr[i] | arr[j]) != a[i][j]) ans = false;
        if (ans) {
            cout << "YES\n";
            for (int i = 1; i <= n; i++) cout << arr[i] << (i == n ? "\n" : " ");
        }
        else cout << "NO\n";
    }
    return 0;
}
 
/*
1
5
0 7 7 5 5
7 0 3 2 6
7 3 0 3 7
5 2 3 0 4
5 6 7 4 0
*/
