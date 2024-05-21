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
        cin >> n >> s;
        vector<int> v(4, 0);
        for (int i = 0; i < n; i++) {
            switch (s[i]) {
                case 'N': v[0]++; break;
                case 'S': v[1]++; break;
                case 'E': v[2]++; break;
                case 'W': v[3]++; break;
            }
        }
        // cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << " bruh\n";
        if ((v[0] + v[1])%2 || (v[2] + v[3])%2 || max(v[0], v[1]) < 2 && max(v[2], v[3]) == 0 || max(v[2], v[3]) < 2 && max(v[0], v[1]) == 0) cout << "NO\n";
        else {
            for (int i = 0; i < n; i++) {
                switch (s[i]) {
                    case 'N': cout << ((v[0]--)%2 ? 'R' : 'H'); break;
                    case 'S': cout << ((v[1]--)%2 ? 'R' : 'H'); break;
                    case 'E': cout << ((v[2]--)%2 ? 'H' : 'R'); break;
                    case 'W': cout << ((v[3]--)%2 ? 'H' : 'R'); break;
                }
            }
            cout << "\n";
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
