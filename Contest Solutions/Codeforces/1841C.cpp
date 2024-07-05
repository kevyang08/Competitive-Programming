#include <bits/stdc++.h>
using namespace std;

int t, arr[200001], idx[5], cnt[5][200001], mx[200001];
string s;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        int ans = 0, mdt = 0;
        cin >> s;
        for (int i = s.length() - 1, j = 0; i >= 0; i--) {
            if (s[i] - 'A' < j) ans -= pow(10, s[i] - 'A');
            else ans += pow(10, s[i] - 'A');
            mx[i + 1] = j;
            j = max(j, s[i] - 'A');
        }
        for (int i = 0; i < 5; i++) idx[i] = 0;
        for (int i = 1; i <= s.length(); i++) {
            arr[i] = arr[i - 1] + pow(10, s[i - 1] - 'A');
            int t1 = 0, t2 = 0;
            for (int k = s[i - 1] - 'A'; k < 5; k++) t1 = max(t1, idx[k]);
            for (int k = mx[i]; k < 5; k++) t2 = max(t2, idx[k]);
            for (int j = 0; j < 5; j++) {
                if (s[i - 1] - 'A' == j) continue;
                int mdx = 0, dt = pow(10, j), bruh = 0;
                if (mx[i] > j) dt = -dt;
                for (int k = j; k < 5; k++) mdx = max(mdx, idx[k]);
                if (s[i - 1] - 'A' >= mx[i]) {
                    if (s[i - 1] - 'A' > j) {
                        // values from max(mx[i], j) to s[i - 1] - 'A' - 1 change, but only if no later elements are strictly greater than it
                        for (int k = s[i - 1] - 'A' - 1; k >= max(mx[i], j); k--) {
                            bruh = max(bruh, idx[k + 1]);
                            dt += 2 * (cnt[k][i - 1] - cnt[k][bruh]) * pow(10, k);
                        }
                    }
                    else {
                        // values from s[i - 1] - 'A' to j - 1 change, but only if no later elements are strictly greater than it
                        for (int k = j - 1; k >= s[i - 1] - 'A'; k--) {
                            bruh = max(bruh, idx[k + 1]);
                            dt -= 2 * (cnt[k][i - 1] - cnt[k][bruh]) * pow(10, k);
                        }
                    }
                    dt -= pow(10, s[i - 1] - 'A');
                }
                else {
                    // if (mx[i] >= j) nothing changes
                    // else values from mx[i] to j - 1 change, but only if no later elements are strictly greater than it
                    if (mx[i] < j) {
                        for (int k = j - 1; k >= mx[i]; k--) {
                            bruh = max(bruh, idx[k + 1]);
                            dt -= 2 * (cnt[k][i - 1] - cnt[k][bruh]) * pow(10, k);
                        }
                    }
                    dt += pow(10, s[i - 1] - 'A');
                }
                mdt = max(mdt, dt);

                // cout << i << " " << j << " " << mdx << " " << t1 << " " << t2 << " " << bruh << " " << dt << " " << mdt << " bruh\n";
            }
            idx[s[i - 1] - 'A'] = i;
            for (int k = 0; k < 5; k++) cnt[k][i] = cnt[k][i - 1];
            cnt[s[i - 1] - 'A'][i]++;
        }
        // cout << ans << " " << mdt << " debug\n";
        cout << ans + mdt << '\n';
    }
    return 0;
}
 
/*
tips:
- look out for int overflow and array out of bounds
- don't get stuck debugging a wrong solution, take time to think of a new one instead of spamming submissions
- make sure stuestion was read correctly
- for certain problems, solve a few cases by hand and try to make observations
- if behind, stop looking at leaderboard and focus on solving
*/