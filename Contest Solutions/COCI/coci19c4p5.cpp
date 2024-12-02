#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int n, l, r;
ll nn = INF, dn = 1;
string s;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> s;
    for (int k = 1; k <= 26; k++) {
        vector<int> f(26);
        ll c = 0;
        for (int i = 0, j = 0; i < n; i++) {
            if (!f[s[i] - 'a']) ++c;
            f[s[i] - 'a']++;
            while (c > k) {
                --f[s[j] - 'a'];
                if (!f[s[j] - 'a']) --c;
                ++j;
            }
            if (c * dn < nn * (i - j + 1)) {
                nn = c, dn = i - j + 1;
                l = j + 1, r = i + 1;
            }
        }
    }
    cout << l << " " << r << "\n";
    return 0;
}