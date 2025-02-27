#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

ll c, cnt[100000], ln = 0, j = -1;
char ch[100000], ans;
string s;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> s >> c;
    s += 'E';
    ll cur = 0;
    for (int i = 0; i < s.length(); i++) {
        if (isalpha(s[i])) {
            if (j >= 0) cnt[j] = cur, ln += cur;
            ch[++j] = s[i], cur = 0;
        }
        else cur = cur * 10 + s[i] - '0';
    }
    c = (c + 1)%ln;
    if (!c) {
        cout << ch[j - 1] << "\n";
        return 0;
    }
    for (int i = 0; i < j; i++) {
        c -= cnt[i];
        if (c <= 0) {
            ans = ch[i];
            break;
        }
    }
    cout << ans << "\n";
    return 0;
}