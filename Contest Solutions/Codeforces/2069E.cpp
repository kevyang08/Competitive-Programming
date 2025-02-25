#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int t, a, b, ab, ba;
string s;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> s >> a >> b >> ab >> ba;
        s += s[s.length() - 1];
        int n = s.length(), ln = 1, thing = 0;
        vector<vector<int>> vq(2);
        for (int i = 1; i < n; i++) {
            if (s[i] != s[i - 1]) ++ln;
            else {
                if (ln%2) {
                    if (s[i - 1] == 'A') --a;
                    else --b;
                    if (ln > 1) thing += ln - 1;
                }
                else {
                    if (s[i - 1] == 'A') vq[1].pb(ln); // ba...ba
                    else vq[0].pb(ln); // ab...ab
                }
                ln = 1;
            }
        }
        sort(vq[0].begin(), vq[0].end(), greater<int>());
        sort(vq[1].begin(), vq[1].end(), greater<int>());
        while (!vq[1].empty() && ba) {
            int tmp = vq[1].back(); vq[1].pop_back();
            if (ba * 2 < tmp) {
                vq[1].pb(tmp - ba * 2);
                tmp = ba * 2;
            }
            ba -= tmp/2;
        }
        while (!vq[0].empty() && ab) {
            int tmp = vq[0].back(); vq[0].pop_back();
            if (ab * 2 < tmp) {
                vq[0].pb(tmp - ab * 2);
                tmp = ab * 2;
            }
            ab -= tmp/2;
        }
        if (ab != 0) {
            int tmp = min(ab, thing/2);
            ab -= tmp, thing -= tmp * 2;
            while (!vq[1].empty() && ab) {
                --a, --b;
                int tmp = vq[1].back() - 2; vq[1].pop_back();
                if (ab * 2 < tmp) {
                    vq[1].pb(tmp - ab * 2);
                    tmp = ab * 2;
                }
                ab -= tmp/2;
            }
        }
        if (ba != 0) {
            int tmp = min(ba, thing/2);
            ba -= tmp, thing -= tmp * 2;
            while (!vq[0].empty() && ba) {
                --a, --b;
                int tmp = vq[0].back() - 2; vq[0].pop_back();
                if (ba * 2 < tmp) {
                    vq[0].pb(tmp - ba * 2);
                    tmp = ba * 2;
                }
                ba -= tmp/2;
            }
        }
        a -= thing/2, b -= thing/2;
        while (!vq[1].empty()) {
            a -= vq[1].back()/2, b -= vq[1].back()/2;
            vq[1].pop_back();
        }
        while (!vq[0].empty()) {
            a -= vq[0].back()/2, b -= vq[0].back()/2;
            vq[0].pop_back();
        }
        cout << (a >= 0 && b >= 0 && ab >= 0 && ba >= 0 ? "YES\n" : "NO\n");
    }
    return 0;
}