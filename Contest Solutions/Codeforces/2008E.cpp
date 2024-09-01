#include <bits/stdc++.h>
using namespace std;

int t, n;
string s;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        vector<vector<int>> fq(2, vector<int>(26));
        vector<multiset<int>> ms(2);
        cin >> n >> s;
        if (n == 1) {
            cout << "1\n";
            continue;
        }
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            ms[i%2].extract(fq[i%2][c]);
            ++fq[i%2][c];
            ms[i%2].insert(fq[i%2][c]);
        }
        int ans = n - *ms[1].rbegin() - *ms[0].rbegin() + n%2;
        if (n%2 ^ 1) {
            cout << ans << "\n";
            continue;
        }
        for (int i = n - 1; i >= 0; i--) {
            int c = s[i] - 'a';
            ms[i%2].extract(fq[i%2][c]);
            --fq[i%2][c];
            ms[i%2].insert(fq[i%2][c]);
            ans = min(ans, n - *ms[1].rbegin() - *ms[0].rbegin());
            ms[i%2 ^ 1].extract(fq[i%2 ^ 1][c]);
            ++fq[i%2 ^ 1][c];
            ms[i%2 ^ 1].insert(fq[i%2 ^ 1][c]);
        }
        cout << ans << "\n";
    }
    return 0;
}