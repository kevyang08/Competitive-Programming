#include <bits/stdc++.h>
using namespace std;

const int sz = 500;

int n, m, a[250000], l, r, off[sz], cnt[sz][10];
string bruh;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m >> bruh;
    for (int i = 0; i < n; i++) {
        a[i] = bruh[i] - '0';
        cnt[i/sz][a[i]]++;
    }
    while (m--) {
        cin >> l >> r;
        l--; r--;
        int s = l/sz, e = r/sz, ans = 0;
        for (int i = s; i <= e; i++) {
            int temp = cnt[i][9];
            for (int j = 9; j >= 0; j--) {
                ans += cnt[i][j] * j;
                if (j) cnt[i][j] = cnt[i][j - 1];
            }
            cnt[i][0] = temp;
            off[i]++;
        }
        for (int i = s * sz; i < l; i++) {
            cnt[i/sz][(a[i] + off[i/sz])%10]--;
            a[i] = (a[i] - 1 + 10)%10;
            cnt[i/sz][(a[i] + off[i/sz])%10]++;
            ans -= (a[i] + off[i/sz])%10;
        }
        for (int i = r + 1; i < min((e + 1) * sz, n); i++) {
            cnt[i/sz][(a[i] + off[i/sz])%10]--;
            a[i] = (a[i] - 1 + 10)%10;
            cnt[i/sz][(a[i] + off[i/sz])%10]++;
            ans -= (a[i] + off[i/sz])%10;
        }
        cout << ans << "\n";
    }
    return 0;
}
