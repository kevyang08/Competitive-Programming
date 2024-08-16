#include <bits/stdc++.h>
using namespace std;

int n;
long long ans = 0;
string s;
unordered_map<int, int> mp[26];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n;
    while (n--) {
        cin >> s;
        vector<int> cnt(26);
        for (int i = 0; i < s.length(); i++) ++cnt[s[i] - 'a'];
        int tmp = 0;
        for (int i = 0; i < 26; i++) if (cnt[i]%2) tmp += (1 << i);
        for (int i = 0; i < 26; i++) {
            if (cnt[i]) continue;
            int j = ((1 << 26) - 1) ^ (1 << i);
            ans += mp[i].find(j ^ (tmp & j)) == mp[i].end() ? 0 : mp[i][j ^ (tmp & j)];
            ++mp[i][tmp & j];
        }
    }
    cout << ans << "\n";
    return 0;
}