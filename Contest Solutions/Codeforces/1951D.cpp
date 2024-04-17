#include <bits/stdc++.h>
using namespace std;

int t;
long long n, k;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<long long> v;
        while (k && n) {
            long long p = -1;
            if (n < k) break;
            if (n%k == 0) p = n/k;
            else if (n - k + 1 > n/2) p = n - k + 1;
            else p = n/k;
            k -= n/p;
            n %= p;
            v.push_back(p);
        }
        if (k) cout << "NO\n";
        else {
            cout << "YES\n";
            cout << v.size() << "\n";
            for (int i = 0; i < v.size(); i++) cout << v[i] << (i == v.size() - 1 ? "\n" : " ");
        }
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
