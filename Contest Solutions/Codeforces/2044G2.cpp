#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int t, n, r[200001], in[200001], off[200001];
bool vis[200001];
map<int, int> mp[200001];
queue<int> q;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        int ans = 2;
        cin >> n;
        fill(vis, vis + n + 1, false);
        fill(in, in + n + 1, 0);
        fill(off, off + n + 1, 0);
        for (int i = 1; i <= n; i++) cin >> r[i];
        for (int i = 1; i <= n; i++) ++in[r[i]], mp[i].clear(), mp[i][0] = 1;
        for (int i = 1; i <= n; i++) if (!in[i]) q.push(i);
        while (!q.empty()) {
            int c = q.front(); q.pop();
            ++off[c];
            ans = max(ans, mp[c].rbegin() -> first + mp[c].rbegin() -> second + off[c] + 1);
            vis[c] = true;
            if (mp[r[c]].size() < mp[c].size()) swap(mp[r[c]], mp[c]), swap(off[r[c]], off[c]);
            for (auto &[k, v] : mp[c]) {
                int tmp = k - off[r[c]] + off[c];
                if (mp[r[c]].lower_bound(tmp) != mp[r[c]].begin() && (--mp[r[c]].lower_bound(tmp)) -> first + (--mp[r[c]].lower_bound(tmp)) -> second > tmp) 
                    tmp = (--mp[r[c]].lower_bound(tmp)) -> first;
                mp[r[c]][tmp] += v;
                while (mp[r[c]].upper_bound(tmp) != mp[r[c]].end() && tmp + mp[r[c]][tmp] > mp[r[c]].upper_bound(tmp) -> first) {
                    mp[r[c]][tmp] += mp[r[c]].upper_bound(tmp) -> second;
                    mp[r[c]].erase(mp[r[c]].upper_bound(tmp));
                }
            }
            --in[r[c]];
            if (!in[r[c]]) q.push(r[c]);
        }
        cout << ans << "\n";
    }
    return 0;
}