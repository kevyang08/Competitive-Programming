#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 10000001;
 
int t, n, idx = 0;
long long bruh[8], ans[MAXN];
string s;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ans[0] = 1;
    for (int i = 0; i < 8; i++) bruh[i] = 1;
    for (int i = 1; i < MAXN; i++) {
        int wtf = 7;
        for (int j = 10000000; j > 0; j /= 10) {
            if (i%j == 0) {
                for (int k = 0; k < wtf; k++) bruh[k] = 1;
                bruh[wtf]++;
                idx = max(wtf, idx);
                break;
            }
            wtf--;
        }
        ans[i] = 1;
        for (int j = 0; j <= idx; j++) ans[i] *= bruh[j] * (bruh[j] + 1)/2;
    }
    cin >> t;
    while (t--) {
        cin >> n;
        cout << ans[n] << "\n";
    }
    return 0;
}
