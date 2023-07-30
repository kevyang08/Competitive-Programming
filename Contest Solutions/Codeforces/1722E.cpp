#include <bits/stdc++.h>
using namespace std;
 
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, q;
      	long long arr[1005][1005] = {0};
        cin >> n >> q;
        for (int i = 0; i < n; i++) {
            int h, w;
            cin >> h >> w;
            arr[1][1] += h * w;
            arr[h + 2][w + 2] += h * w;
            arr[h + 2][1] -= h * w;
            arr[1][w + 2] -= h * w;
        }
        for (int i = 1; i < 1005; i++) for (int j = 1; j < 1005; j++) arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
        while (q--) {
            int h1, w1, h2, w2;
            cin >> h1 >> w1 >> h2 >> w2;
            cout << arr[h2 + 1][w2 + 1] - arr[h2 + 1][w1 + 2] - arr[h1 + 2][w2 + 1] + arr[h1 + 2][w1 + 2] << "\n";
        }
    }
    return 0;
}
