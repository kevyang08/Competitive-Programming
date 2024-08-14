#include <bits/stdc++.h>
using namespace std;

int t, n, a[200000], m;
string s;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        cin >> m;
        while (m--) {
            cin >> s;
            bool thing = s.length() == n;
            map<char, int> mp;
            map<int, char> mp2;
            for (int i = 0; i < s.length(); i++) {
                char c = s[i];
                if (mp.find(c) != mp.end() && mp[c] != a[i]) thing = false;
                if (mp2.find(a[i]) != mp2.end() && mp2[a[i]] != c) thing = false;
                mp[c] = a[i];
                mp2[a[i]] = c;
            }
            cout << (thing ? "YES\n" : "NO\n");
        }
    }
    return 0;
}