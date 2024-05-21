#include <bits/stdc++.h>
using namespace std;

int t, n;
string b;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> b;
        vector<char> v;
        set<char> st;
        for (char c : b) {
            if (st.find(c) != st.end()) continue;
            st.insert(c);
            v.push_back(c);
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < v.size(); j++) {
                if (v[j] == b[i]) {
                    cout << v[v.size() - j - 1];
                    break;
                }
            }
        }
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
