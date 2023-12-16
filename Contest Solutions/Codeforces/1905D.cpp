#include <bits/stdc++.h>
using namespace std;

int t, n, a[1000001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        long long res = 0, cur = 0;
        set<int> s;
        deque<pair<int, int>> dq;
        cin >> n;
        for (int i = 0; i <= n; i++) s.insert(i);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            s.erase(a[i]);
            if (dq.empty() || dq.back().second != *s.lower_bound(0)) dq.push_back({1, *s.lower_bound(0)});
            else dq.back().first++;
            res += dq.back().second;
        }
        cur = res;
        for (int i = 1; i < n; i++) {
            int freq = 0;
            cur -= dq.front().second;
            dq.front().first--;
            if (!dq.front().first) dq.pop_front();
            while (!dq.empty() && dq.back().second >= a[i]) {
                auto p = dq.back();
                cur -= (long long)p.first * p.second;
                freq += p.first;
                dq.pop_back();
            }
            cur += (long long)freq * a[i];
            if (freq) dq.push_back({freq, a[i]});
            cur += n;
            dq.push_back({1, n});
            res = max(cur, res);
        }
        cout << res << "\n";
    }
    return 0;
}
