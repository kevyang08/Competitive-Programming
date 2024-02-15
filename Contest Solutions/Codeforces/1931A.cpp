#include <bits/stdc++.h>
using namespace std;
 
int t;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < 3; i++) {
            if (n - (2 - i) * 26 > 0) {
                char temp = n - (2 - i) * 26 - 1 + 'a';
                cout << temp;
                n -= temp - 'a' + 1;
            } 
            else {
                cout << 'a';
                n--;
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
