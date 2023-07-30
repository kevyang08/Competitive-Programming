#include <bits/stdc++.h>
using namespace std;

int n, m, arr[2][10001], x, y, w, h, c = 0, idx = 0;
vector<pair<pair<int, int>, int>> v;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> w >> h;
        x++; y++;
        v.push_back({{x, y}, 1});
        if (x + w <= n && y + h <= n) v.push_back({{x + w, y + h}, 1});
        if (x + w <= n) v.push_back({{x + w, y}, -1});
        if (y + h <= n) v.push_back({{x, y + h}, -1});
    }
    sort(v.begin(), v.end());
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            arr[1][j] = arr[1][j - 1] + arr[0][j] - arr[0][j - 1];
            while (v[idx].first.first == i && v[idx].first.second == j) arr[1][j] += v[idx++].second;
            if (arr[1][j]%2 == 1) c++;
        }
        for (int j = 1; j <= n; j++) arr[0][j] = arr[1][j];
    }
    cout << c << "\n";
}
