#include <bits/stdc++.h>
using namespace std;

int n, w, t, mn = 0;
vector<int> vl, vg, v;
long long solve(int thing) {
    long long ans = 0;
    int l = 0, r = n - 1, p = w;
    for (int i = 0; i < n; i++) {
        if (i%2 == thing) {
            ans += max(abs(v[l] - p), abs(v[l] - w));
            p = v[l++];
        }
        else {
            ans += max(abs(v[r] - p), abs(v[r] - w));
            p = v[r--];
        }
    }
    return ans;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> w;
    vl.push_back(w);
    vg.push_back(w);
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (t > w) vg.push_back(t);
        else vl.push_back(t);
        v.push_back(t);
    }
    sort(vl.begin(), vl.end());
    sort(vg.begin(), vg.end());
    sort(v.begin(), v.end());
    for (int i = 0; i < vl.size() - 1; i++) mn += vl[i + 1] - vl[i];
    for (int i = 0; i < vg.size() - 1; i++) mn += vg[i + 1] - vg[i];
    cout << mn << " " << max(solve(0), solve(1)) << "\n";
    return 0;
}
