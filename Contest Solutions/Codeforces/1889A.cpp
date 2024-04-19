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
        if (n%2) {
            cout << "-1\n";
            continue;
        }
        bool thing = true;
        for (int i = 0; i < n; i++) if (s[i] != s[0]) thing = false;
        if (thing) {
            cout << "-1\n";
            continue;
        }
        deque<char> dq;
        vector<int> v;
        for (char c : s) dq.push_back(c);
        int i1 = 0, i2 = n;
        while (!dq.empty()) {
            if (dq.front() == dq.back()) {
                if (dq.front() == '1') {
                    dq.push_front('1');
                    dq.push_front('0');
                    v.push_back(i1);
                }
                else {
                    dq.push_back('0');
                    dq.push_back('1');
                    v.push_back(i2);
                }
                i2 += 2;
            }
            dq.pop_back();
            dq.pop_front();
            i1++; i2--;
            if (v.size() > 300) break;
        }
        if (v.size() > 300) {
            cout << "-1\n";
            continue;
        }
        cout << v.size() << "\n";
        for (int i : v) cout << i << " ";
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
