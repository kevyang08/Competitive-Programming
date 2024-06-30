#include <bits/stdc++.h>
using namespace std;

int t, n, k, a;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        long long ans = 0;
        map<int, vector<int>> mp;
        for (int i = 1; i <= n; i++) {
            cin >> a;
            mp[a%k].push_back(a);
        }
        int cnt = 0;
        for (auto &[a, v] : mp) {
            if (v.size()%2) {
                if (!cnt) ++cnt;
                else {
                    ans = -1;
                    break;
                }
            }
            sort(v.begin(), v.end());
            vector<long long> temp(v.size());
            long long res = 0x3f3f3f3f3f3f3f3f;
            for (int i = 0; i < v.size() - v.size()%2; i += 2) {
                temp[i] = (v[i + 1] - v[i])/k;
                if (i > 1) temp[i] += temp[i-2];
            }
            if (v.size() == 1) res = 0;
            else if (v.size()%2) {
                long long sum = 0;
                for (int i = v.size() - 2; i > 0; i -= 2) {
                    res = min(res, sum + temp[i - 1]);
                    sum += (v[i+1]-v[i])/k;
                }
                res = min(res, sum);
            }
            else res = temp[v.size() - 2];
            ans += res;
        }
        cout << ans << "\n";
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