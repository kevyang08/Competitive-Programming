#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t, n, g;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    freopen("line_of_delivery_part_1_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        cin >> n >> g;
        int mn = 0x3f3f3f3f, idx = 0, c = n;
        vector<int> e(n);
        for (int i = 0; i < n; i++) cin >> e[i];
        sort(e.begin(), e.end());
        for (int i : e) {
            if (abs(g - i) <= mn) {
                mn = abs(g - i);
                idx = c;
            }
            --c;
        }
        cout << idx << " " << mn << "\n";
    }
    return 0;
}