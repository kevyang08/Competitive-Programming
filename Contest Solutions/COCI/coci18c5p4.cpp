#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

/*
when matching:
- for a specific character c, match either ? or c
- for ?, match _ or ?

when inserting:
- for a specific character c, insert either _ or c
- for ?, insert ?

note: needa optimize hash table (in other words do not use string)
26 for '?', 27 for '_', 0-25 for 'a' to 'z'
*/

int n, m;
ll ans = 0;
string s;
unordered_map<int, int> mp;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s;
        int cnt = 0;
        for (int j = 0; j < m; j++) cnt += (s[j] != '?');
        for (int j = 0; j < (1 << m); j++) {
            int t = 0;
            for (int k = 0; k < m; k++) {
                t *= 28;
                if ((1 << k) & j) t += 26;
                else t += (s[k] == '?' ? 27 : s[k] - 'a');
            }
            if (mp.find(t) != mp.end()) ans += mp[t];
            // cout << t << " " << ans << " debug\n"; // debug
        }
        for (int j = 0; j < (1 << cnt); j++) {
            int t = 0;
            for (int k = 0, idx = 0; k < m; k++) {
                t *= 28;
                if (s[k] == '?') t += 26;
                else {
                    if ((1 << idx) & j) t += 27;
                    else t += s[k] - 'a';
                    ++idx;
                }
            }
            ++mp[t];
        }
        // cout << ans << "bruh\n"; // debug
    }
    cout << ans << "\n";
    return 0;
}