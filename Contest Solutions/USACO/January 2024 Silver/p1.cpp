#include <bits/stdc++.h>
using namespace std;

int t, n, q, c, a, b, arr[100001];
vector<pair<int, int>> vp;
bool wtf[100001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        int prh = 0, idl = 0, idr = 1, bruh = 0, mx = 1;
        deque<int> dq;
        bool thing = true;
        cin >> n >> q >> c;
        memset(wtf, false, sizeof(wtf));
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            if (!arr[i]) wtf[i] = true;
        }
        vp.clear();
        while (q--) {
            cin >> a >> b;
            vp.push_back({a, b});
        }
        sort(vp.begin(), vp.end());
        for (auto p : vp) {
            if (p.second < prh || p.first < prh && p.second > prh) thing = false;
            while (idr < p.second) {
                while (!dq.empty() && arr[dq.back()] <= arr[idr]) dq.pop_back();
                dq.push_back(idr++);
            }
            while (idl < p.first) {
                mx = max(mx, arr[++idl]);
                if (wtf[idl] && idl >= prh) bruh = idl;
                if (!dq.empty() && dq.front() == idl) dq.pop_front();
            }
            if (!dq.empty() && arr[dq.front()]) {
                if (arr[idr] && arr[dq.front()] >= arr[idr]) thing = false;
                if (!bruh && arr[dq.front()] > mx) thing = false;
                else if (bruh && arr[dq.front()] > mx) arr[bruh] = mx = arr[dq.front()];
            }
            if (!arr[idr]) arr[idr] = mx + 1;
            bruh = 0;
            if (arr[idr] <= mx) thing = false;
            prh = p.second;
        }
        for (int i = 1; i <= n; i++) if (arr[i] > c) thing = false;
        if (!thing) {
            cout << -1 << "\n";
            continue;
        }
        for (int i = 1; i <= n; i++) cout << max(1, arr[i]) << (i == n ? "\n" : " ");
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
