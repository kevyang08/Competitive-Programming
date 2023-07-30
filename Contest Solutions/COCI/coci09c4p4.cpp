#include <bits/stdc++.h>
using namespace std;

int n, x, h[1000001], res[1000001], bruh = 0, cnt = 0;
long long ans = 0;
deque<pair<int, int>> dq;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
        while (!dq.empty() && dq.back().first >= h[i]) dq.pop_back();
        dq.push_back({h[i], i});
        if (i - dq.front().second >= x) dq.pop_front();
        if (i >= x) res[i - x + 1] = dq.front().first;
    }
    dq.clear();
    for (int i = 1; i <= n; i++) {
        while (!dq.empty() && dq.back().first <= res[i]) dq.pop_back();
        dq.push_back({res[i], i});
        if (i - dq.front().second >= x) dq.pop_front();
        res[i] = dq.front().first;
        ans += h[i] - res[i];
        if (res[i] != res[i - 1] || bruh >= x) {
            cnt++;
            bruh = 1;
        }
        else bruh++;
    }
    cout << ans << "\n";
    cout << cnt << "\n";
}
