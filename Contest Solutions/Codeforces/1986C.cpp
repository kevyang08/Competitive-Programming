#include <bits/stdc++.h>
using namespace std;

int t, n, m, a;
string s, c;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> m >> s;
        set<int> st;
        for (int i = 0; i < m; i++) {
            cin >> a;
            st.insert(a);
        }
        cin >> c;
        sort(c.begin(), c.end());
        for (int i = 0, j = 0; i < n; i++) cout << (st.find(i + 1) != st.end() ? c[j++] : s[i]);
        cout << "\n";
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