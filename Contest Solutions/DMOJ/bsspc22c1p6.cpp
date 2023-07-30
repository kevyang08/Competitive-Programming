#include <bits/stdc++.h>
using namespace std;

int n, m;
long long a, b, arr[5001][5001], bruh[5001], mx = 1, ans = 0, arra[5001], psa[5001];
vector<pair<int, int>> v;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        bruh[i] = a;
        for (int j = 1; j <= n; j++) arr[i][j] = a * (j - 1) + b;
    }
    for (int i = 1; i <= n; i++) {
        mx = 1;
        for (int j = 1; j <= n; j++) if (bruh[j] > bruh[mx] || bruh[j] == bruh[mx] && arr[j][i] > arr[mx][i]) mx = j;
        ans += arr[mx][i];
        arra[i] = psa[i] = bruh[mx];
        bruh[mx] = 0;
        v.push_back({mx, i});
    }
    for (int i = 1; i <= n; i++) {
        psa[i] += psa[i - 1];
        // cout << psa[i] << "\n"; // debug
    }
    for (int i = 0; i < n - m; i++) {
        mx = 0;
        for (int j = 0; j < n; j++) {
            if (arr[v[j].first][v[j].second] + psa[n] - psa[v[j].second] > arr[v[mx].first][v[mx].second] + psa[n] - psa[v[mx].second]) mx = j;
        }
        // cout << mx << "\n"; // debug
        // cout << v[mx].first << " " << v[mx].second << "\n"; // debug
        // cout << arr[v[mx].first][v[mx].second] + psa[n] - psa[v[mx].second] << "\n"; // debug
        ans -= arr[v[mx].first][v[mx].second] + psa[n] - psa[v[mx].second];
        arr[v[mx].first][v[mx].second] = 0;
        for (int j = v[mx].second; j <= n; j++) psa[j] -= arra[v[mx].second];
        for (int j = mx; j < n; j++) arr[v[j].first][v[j].second] -= arra[v[j].second];
    }
    cout << ans << "\n";
}
