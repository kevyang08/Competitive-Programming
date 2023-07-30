#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int arr[3001][3001], tree[3001][3001];
void update(int x, int y, int v) {
    for (int i = x; i < 3001; i += (i & -i)) 
        for (int j = y; j < 3001; j += (j & -j))
            tree[i][j] = max(v, tree[i][j]);
}
int query(int x, int y) {
    int res = 0;
    for (int i = x; i > 0; i -= (i & -i))
        for (int j = y; j > 0; j -= (j & -j)) 
            res = max(res, tree[i][j]);
    return res;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n, k;
    ll ans = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) 
        for (int j = n - i + 1; j <= n; j++) 
            cin >> arr[i][j];
    for (int i = n; i > 0; i--) {
        for (int j = 0; i + j <= n; j++) {
            update(i + j, n - j, arr[i + j][n - j]);
            if (j + 1 >= k) ans += query(i + j, n - j + k - 1);
        }
    }
    cout << ans << "\n";
}
