#include <bits/stdc++.h>
using namespace std;

int t, n, arr[3][200001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> l(3), r(3);
        bool ans = false;
        long long tot = 0;
        for (int k = 0; k < 3; k++) for (int i = 1; i <= n; i++) {
            cin >> arr[k][i];
            if (!k) tot += arr[k][i];
        }
        tot = (long long)ceil(tot/3.0);
        int thing[3] = {0, 1, 2};
        do {
            // cout << "\n" << thing[0] << " " << thing[1] << " " << thing[2] << " bruh\n";

            int s = 1, j = 0, k = thing[0];
            long long sum = 0;
            for (int i = 1; i <= n; i++) {
                sum += arr[k][i];

                // cout << i << " " << j << " " << k << " " << sum << " wtf\n";

                if (sum >= tot) {
                    l[k] = s, r[k] = i;
                    if (j == 2) {
                        ans = true;
                        break;
                    }
                    s = i + 1;
                    k = thing[++j];
                    sum = 0;
                }
            }
            if (ans) break;
        } while (next_permutation(thing, thing + 3));
        if (!ans) cout << "-1\n";
        else {
            for (int i = 0; i < 3; i++) cout << l[i] << " " << r[i] << " ";
            cout << "\n";
        }
    }
    return 0;
}