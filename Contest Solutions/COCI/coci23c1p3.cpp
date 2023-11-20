#include <bits/stdc++.h>
using namespace std;

int n, m, r, s, a[5001][5001];
deque<int> dq;
deque<pair<int, int>> mx[5001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> a[i][j];
    cin >> r >> s;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!dq.empty() && j - dq.front() == s) dq.pop_front();
            while (!dq.empty() && a[i][dq.back()] <= a[i][j]) dq.pop_back();
            dq.push_back(j);
            if (!mx[j].empty() && i - mx[j].front().first == r) mx[j].pop_front();
            while (!mx[j].empty() && a[mx[j].back().first][mx[j].back().second] <= a[i][dq.front()]) mx[j].pop_back();
            mx[j].push_back({i, dq.front()});
            if (i >= r && j >= s) cout << a[mx[j].front().first][mx[j].front().second] << (j == m ? "\n" : " ");
        }
        dq.clear();
    }
    return 0;
}
