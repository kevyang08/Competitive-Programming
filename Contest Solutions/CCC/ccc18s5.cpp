#include <bits/stdc++.h>
using namespace std;

int n, m, p, q, a, b, c, x, y, z, id[2][100001], mn[100001];
long long ans = 0, arr[100001];
vector<pair<int, pair<int, int>>> ec, ep, bruh;
int find(int i, int x) {return (id[i][x] < 0 ? x : (id[i][x] = find(i, id[i][x])));}
void join(int i, int x, int y) {
    if ((x = find(i, x)) < (y = find(i, y))) {
        id[i][x] += id[i][y];
        id[i][y] = x;
    }
    else {
        id[i][y] += id[i][x];
        id[i][x] = y;
    }
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    for (int i = 1; i < 100001; i++) id[0][i] = id[1][i] = -1;
    cin >> n >> m >> p >> q;
    for (int i = 0; i < p; i++) {
        cin >> a >> b >> c;
        ec.push_back({c, {a, b}});
    }
    sort(ec.begin(), ec.end());
    for (int i = 0; i < q; i++) {
        cin >> x >> y >> z;
        ep.push_back({z, {x, y}});
    }
    sort(ep.begin(), ep.end());
    for (int i = 0; i < p; i++) {
        if (find(0, ec[i].second.first) != find(0, ec[i].second.second)) {
            join(0, ec[i].second.first, ec[i].second.second);
            bruh.push_back(ec[i]);
        }
        else ans += (long long)ec[i].first * n;
    }
    for (int i = 1; i <= bruh.size(); i++) arr[i] = arr[i - 1] + bruh[i - 1].first;
    for (int i = 0; i < q; i++) {
        if (find(1, ep[i].second.first) != find(1, ep[i].second.second)) {
            join(1, ep[i].second.first, ep[i].second.second);
            int l = 0, r = bruh.size();
            while (l < r) {
                int m = (l + r)/2;
                if (bruh[m].first <= ep[i].first) l = m + 1;
                else r = m;
            }
            ans += arr[bruh.size()] - arr[l] + (long long)ep[i].first * l;
        }
        else ans += (long long)ep[i].first * m;
    }
    cout << ans << "\n";
}
