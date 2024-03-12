#include <bits/stdc++.h>
using namespace std;

int t, n, m, x, r;
char c;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        set<int> s;
        cin >> n >> m >> x;
        s.insert(x);
        while (m--) {
            cin >> r >> c;
            set<int> st;
            if (c == '0') for (int i : s) st.insert((i - 1 + r + n)%n + 1);
            else if (c == '1') for (int i : s) st.insert((i - 1 - r + n)%n + 1);
            else {
                for (int i : s) {
                    if (st.find((i - 1 + r + n)%n + 1) == st.end()) st.insert((i - 1 + r + n)%n + 1);
                    if (st.find((i - 1 - r + n)%n + 1) == st.end()) st.insert((i - 1 - r + n)%n + 1);
                }
            }
            s = st;
        }
        cout << s.size() << "\n";
        while (!s.empty()) {
            cout << *s.begin();
            s.erase(*s.begin());
            cout << (s.empty() ? "\n" : " ");
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
