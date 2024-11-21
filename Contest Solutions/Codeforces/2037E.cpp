#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int t, n, ans[200001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        int cnt = 0, res, prev = -1;
        string s = "";
        for (int i = 2, j = 1; i <= n; i++) {
            cout << "? " << j << " " << i << endl;
            cin >> res;
            if (!res) {
                if (cnt) {
                    s += '0';
                    ++j;
                }
                prev = 0;
                continue;
            }
            if (!cnt) {
                while (i - j > res) s += '1', ++j;
                while (j < i) s += '0', ++j;
                s += '1';
                --j;
                prev = 1;
            }
            else if (res == prev) {
                s += '0';
                j = i;
                prev = 0;
                continue;
            }
            else {
                s += '1';
                prev = res;
            }
            ++cnt;
        }
        if (!cnt) cout << "! IMPOSSIBLE" << endl;
        else cout << "! " << s << endl;
    }
    return 0;
}