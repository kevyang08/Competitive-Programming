#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int t, n, q;
char x, y, s[200001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        set<int> ba, ca, bc, cb;
        cin >> n >> q >> s;
        for (int i = 0; i < q; i++) {
            cin >> x >> y;
            if (x == 'b' && y == 'a') ba.insert(i);
            if (x == 'c' && y == 'a') ca.insert(i);
            if (x == 'b' && y == 'c') bc.insert(i);
            if (x == 'c' && y == 'b') cb.insert(i);
        }
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') continue;
            if (s[i] == 'b') {
                if (!ba.empty()) {
                    s[i] = 'a';
                    ba.erase(ba.begin());
                }
                else if (!bc.empty() && ca.lower_bound(*bc.begin()) != ca.end()) {
                    ca.erase(ca.lower_bound(*bc.begin()));
                    bc.erase(bc.begin());
                    s[i] = 'a';
                }
            }
            else {
                if (!ca.empty()) {
                    s[i] = 'a';
                    ca.erase(ca.begin());
                }
                else if (!cb.empty()) {
                    s[i] = 'b';
                    if (ba.lower_bound(*cb.begin()) != ba.end()) {
                        s[i] = 'a';
                        ba.erase(ba.lower_bound(*cb.begin()));
                    }
                    cb.erase(cb.begin());
                }
            }
        }
        cout << s << "\n";
    }
    return 0;
}