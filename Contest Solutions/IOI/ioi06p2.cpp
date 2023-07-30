#include <bits/stdc++.h>
using namespace std;

int m, n, a, b, c, d, rp = 0, cp = 0, rc = 0, cc = 0, arr[1001][1001], ap[1001][1001], ac[1001][1001];
deque<int> dq;
deque<pair<int, int>> mn[1001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> m >> n >> a >> b >> c >> d;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
            arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
            if (i >= b && j >= a) ap[i - b + 1][j - a + 1] = arr[i][j] - arr[i - b][j] - arr[i][j - a] + arr[i - b][j - a];
            if (i >= d && j >= c) ac[i - d + 1][j - c + 1] = arr[i][j] - arr[i - d][j] - arr[i][j - c] + arr[i - d][j - c];
        }
    }
    for (int i = 2; i < n; i++) {
        dq.clear();
        for (int j = 2; j < m; j++) {
            while (!dq.empty() && ac[i][dq.back()] >= ac[i][j]) dq.pop_back();
            if (j + c <= m) {
                dq.push_back(j);
                if (j + c >= a) {
                    while (!mn[j + c - a + 1].empty() && ac[mn[j + c - a + 1].back().first][mn[j + c - a + 1].back().second] >= ac[i][dq.front()]) mn[j + c - a + 1].pop_back();
                    mn[j + c - a + 1].push_back({i, dq.front()});
                    if (i + d >= b) {
                        if (ap[i + d - b + 1][j + c - a + 1] - ac[mn[j + c - a + 1].front().first][mn[j + c - a + 1].front().second] > ap[rp][cp] - ac[rc][cc]) {
                            rp = i + d - b + 1;
                            cp = j + c - a + 1;
                            rc = mn[j + c - a + 1].front().first;
                            cc = mn[j + c - a + 1].front().second;
                        }
                    }
                    if (!mn[j + c - a + 1].empty() && mn[j + c - a + 1].front().first == i + d - b + 2) mn[j + c - a + 1].pop_front();
                }
            }
            if (!dq.empty() && dq.front() == j + c - a + 2) dq.pop_front();
        }
    }
    cout << cp << " " << rp << "\n" << cc << " " << rc << "\n";
    return 0;
}
