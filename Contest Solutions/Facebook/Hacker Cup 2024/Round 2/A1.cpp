#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
- peaks can only have odd digits, max is 17
- nvm digits increase by 1, can brute force
*/

int t, m;
ll a, b;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    freopen("cottontail_climb_part_1_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        cin >> a >> b >> m;
        int ans = 0;
        for (int i = 1; i < 10; i++) {
            for (int j = 1; j < 18; j += 2) {
                ll temp = i;
                for (int k = 1; k <= j/2; k++) {
                    if (temp%10 == 9) {
                        temp = 0;
                        break;
                    }
                    temp = temp * 10 + temp%10 + 1;
                }
                if (!temp) continue;
                for (int k = 1; k <= j/2; k++) temp = temp * 10 + temp%10 - 1;

                // cout << temp << " bruh\n";


                if (temp%m == 0 && a <= temp && temp <= b) ++ans;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}