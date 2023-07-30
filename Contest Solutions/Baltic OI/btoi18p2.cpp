#include <bits/stdc++.h>
using namespace std;

int n, k, r, d[200000], cnt[200000], b, q[200000], ans = 0x3f3f3f3f;
unordered_set<int> s;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> k >> r;
    for (int i = 0; i < n; i++) cin >> d[i];
    for (int i = 0; i < r; i++) {
        cin >> b >> q[b];
        s.insert(b);
    }
    for (int i = 0, j = 0; i < n; i++) {
        cnt[d[i]]++;
        while (cnt[d[j]] > q[d[j]]) cnt[d[j++]]--;
        if (cnt[d[i]] >= q[d[i]] && s.find(d[i]) != s.end()) s.erase(d[i]);
        if (s.size() == 0) ans = min(ans, i - j + 1);
    }
    if (ans == 0x3f3f3f3f) cout << "impossible\n";
    else cout << ans << "\n";
    return 0;
}
