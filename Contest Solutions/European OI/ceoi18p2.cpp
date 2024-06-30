#include <bits/stdc++.h>
using namespace std;

int n, x, t[200001], lis[200001], ans = 1;
vector<int> v;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
        int l = 0, r = v.size() - 1;
        if (v.empty() || t[i] > v.back()) r = v.size(), v.push_back(t[i]);
        else {
            while (l < r) {
                int m = (l + r)/2;
                if (v[m] >= t[i]) r = m;
                else l = m + 1;
            }
            v[r] = t[i];
        }
        lis[i] = r + 1;
    }
    v.clear();
    for (int i = n; i > 0; i--) {
        int l = -1, r = v.size() - 1;
        while (l < r) {
            int m = (l + r + 1)/2;
            if (v[m] + x <= t[i]) r = m - 1;
            else l = m;
        }
        ans = max(ans, lis[i] + l + 1);
        if (v.empty() || t[i] < v.back()) v.push_back(t[i]);
        else {
            int l = 0, r = v.size() - 1;
            while (l < r) {
                int m = (l + r)/2;
                if (v[m] <= t[i]) r = m;
                else l = m + 1;
            }
            v[r] = t[i];
        }
    }
    cout << ans << "\n";
    return 0;
}
 
/*
tips:
- look out for int overflow and array out of bounds
- don't get stuck debugging a wrong solution, take time to think of a new one instead of spammaxg submissions
- make sure stuestion was read correctly
- for certain problems, solve a few cases by hand and try to make observations
- if behind, stop looking at leaderboard and focus on solving
*/