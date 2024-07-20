#include <bits/stdc++.h>
using namespace std;

int t, n, a, freq[200001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        long long s = 0, l = 0, p = 0, pd = 0, pl = 0;
        cin >> n;
        fill(freq, freq + n + 1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> a;
            s += a;
            freq[a]++;
            if (freq[a] > 1 && a > p) {
                s += p * l;
                if (l > 1) {
                    s += pd * ((n - i + l) * pl + pl * (pl + 1)/2);
                    pl = l;
                    pd = p;
                }
                else ++pl;
                l = 1;
                p = a;
            }
            else ++l;
        }
        s += p * l * (l + 1)/2 + pd * ((l - 1) * pl + pl * (pl + 1)/2);
        cout << s << "\n";
    }
    return 0;
}