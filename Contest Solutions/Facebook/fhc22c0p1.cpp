#include <bits/stdc++.h>
using namespace std;

int t, n, k, s, cnt[101];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("second_hands_input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    for (int bruh = 1; bruh <= t; bruh++) {
        fill(cnt, cnt + 101, 0);
        cin >> n >> k;
        bool thing = false;
        for (int i = 0; i < n; i++) {
            cin >> s;
            cnt[s]++;
            if (cnt[s] > 2) thing = true;
        }
        if (n > 2 * k || thing) cout << "Case #" << bruh << ": NO\n";
        else cout << "Case #" << bruh << ": YES\n";
    }
    return 0;
}
