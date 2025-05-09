#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int n, ans = 0;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n;
    vector<int> w(n);
    vector<ll> x(n), y(n);
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i] >> w[i];
    for (int i = 0; i < n; i++) {
        vector<int> vl, vr;
        int cl = 0, cr = 0, idl = 0, idr = 0;
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            if (x[j] < x[i] || (x[j] == x[i] && y[j] > y[i])) {
                vl.push_back(j);
                cl += w[j];
            }
            else {
                vr.push_back(j);
                cr += w[j];
            }
        }
        sort(vl.begin(), vl.end(), [&](auto a, auto b) {
            return (y[a] - y[i]) * (x[b] - x[i]) < (y[b] - y[i]) * (x[a] - x[i]);
        });
        sort(vr.begin(), vr.end(), [&](auto a, auto b) {
            return (y[a] - y[i]) * (x[b] - x[i]) < (y[b] - y[i]) * (x[a] - x[i]);
        });
        while (idl < vl.size() || idr < vr.size()) {
            int tmpl = 0, tmpr = 0;
            if (idr == vr.size() || (idl < vl.size() && (y[vl[idl]] - y[i]) * (x[vr[idr]] - x[i]) > (y[vr[idr]] - y[i]) * (x[vl[idl]] - x[i]))) {
                tmpl += w[vl[idl]];
                while (idl + 1 < vl.size() && (y[vl[idl]] - y[i]) * (x[vl[idl + 1]] - x[i]) == (y[vl[idl + 1]] - y[i]) * (x[vl[idl]] - x[i])) tmpl += w[vl[++idl]];
                while (idr < vr.size() && (y[vl[idl]] - y[i]) * (x[vr[idr]] - x[i]) == (y[vr[idr]] - y[i]) * (x[vl[idl]] - x[i])) tmpr += w[vr[idr++]];
                ++idl;
            }
            else {
                tmpr += w[vr[idr]];
                while (idr + 1 < vr.size() && (y[vr[idr]] - y[i]) * (x[vr[idr + 1]] - x[i]) == (y[vr[idr + 1]] - y[i]) * (x[vr[idr]] - x[i])) tmpr += w[vr[++idr]];
                while (idl < vl.size() && (y[vr[idr]] - y[i]) * (x[vl[idl]] - x[i]) == (y[vl[idl]] - y[i]) * (x[vr[idr]] - x[i])) tmpl += w[vl[idl++]];
                ++idr;
            }
            ans = max(ans, max(cl + tmpr, cr + tmpl) + w[i]);
            ans = max(ans, max(cl - tmpl, cr - tmpr));
            ans = max(ans, max(cl, cr) + max(w[i], 0));
            ans = max(ans, max(cl - tmpl + tmpr, cr - tmpr + tmpl) + max(w[i], 0));
            cl += tmpr - tmpl;
            cr += tmpl - tmpr;
        }

        // cout << i << " " << ans << " bruh\n"; // debug
    }
    cout << ans << "\n";
    return 0;
}