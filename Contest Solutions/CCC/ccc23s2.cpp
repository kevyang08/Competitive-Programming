#include <bits/stdc++.h>
using namespace std;

int n, h[5001], diff[5001][5001], psa[5001][5001], mn;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> h[i];
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            diff[i][j] = abs(h[j] - h[i]);
            psa[j - i + 1][j] = diff[i][j];
        }
    }
    for (int i = 2; i <= n; i++) {
        for (int j = i; j <= n; j++) psa[i][j] += psa[i - 2][j - 1];
    }
    cout << 0;
    for (int i = 2; i <= n; i++) {
        mn = 0x3f3f3f3f;
        for (int j = i; j <= n; j++) mn = min(mn, psa[i][j]);
        cout << " " << mn;
    }
    cout << "\n";
    return 0;
}
