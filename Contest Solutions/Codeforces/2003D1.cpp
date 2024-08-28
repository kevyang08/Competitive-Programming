#include <bits/stdc++.h>
using namespace std;

int t, n, k;
long long m;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        long long mx = 0;
        while (n--) {
            cin >> k;
            vector<int> v(k);
            for (int i = 0; i < k; i++) cin >> v[i];
            sort(v.begin(), v.end());
            long long j = 0, thing = 1;
            for (int i = 0; i < k; i++) {
                if (i && v[i] == v[i - 1]) continue;
                if (v[i] != j && thing) ++j, thing = 0;
                if (v[i] == j) ++j;
                else break;
            }
            mx = max(mx, j + thing);
        }
        if (m > mx) cout << m * (m + 1)/2 - mx * (mx + 1)/2 + mx * mx + mx << "\n";
        else cout << mx * m + mx << "\n";
    }
    return 0;
}