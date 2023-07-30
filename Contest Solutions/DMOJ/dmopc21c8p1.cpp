#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n, m, a, ans[500000];
    set<int> s;
    unordered_map<int, int> cnt;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a;
        s.insert(a);
        cnt[a]++;
    }
    ans[0] = *s.lower_bound(1);
    cnt[ans[0]]--;
    if (cnt[ans[0]] == 0) s.erase(ans[0]);
    for (int i = 1; i < n; i++) {
        if (s.lower_bound(m - ans[i - 1]) == s.end()) {
            cout << -1 << "\n";
            return 0;
        }
        ans[i] = *s.lower_bound(m - ans[i - 1]);
        cnt[ans[i]]--;
        if (cnt[ans[i]] == 0) s.erase(ans[i]);
    }
    for (int i = 0; i < n; i++) cout << (i == 0 ? "" : " ") << ans[i];
    cout << "\n";
    return 0;
}
