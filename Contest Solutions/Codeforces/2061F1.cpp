#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int t;
string a, b;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> a >> b;
        stack<pair<char, int>> st1, st2;
        int ans = 0, l = 0;
        char p = a[0];
        for (char c : a) {
            if (p != c) {
                st1.push({p, l});
                l = 0;
                p = c;
            }
            ++l;
        }
        st1.push({p, l});
        p = b[0], l = 0;
        for (char c : b) {
            if (p != c) {
                st2.push({p, l});
                l = 0;
                p = c;
            }
            ++l;
        }
        st2.push({p, l});
        while (!st1.empty() && !st2.empty()) {
            // cout << st1.size() << " " << st1.top().fi << " " << st1.top().se << " bruh\n";
            // cout << st2.size() << " " << st2.top().fi << " " << st2.top().se << " wtf\n\n";
            if (st1.top().fi != st2.top().fi) {
                if (st1.size() == 1) {
                    st1.pop();
                    break;
                }
                auto tmp1 = st1.top(); st1.pop();
                auto tmp2 = st1.top(); st1.pop();
                if (!st1.empty()) st1.top().se += tmp1.se;
                else st1.push(tmp1);
                st1.push(tmp2);
                ++ans;
            }
            else {
                if (st1.top().se > st2.top().se) {
                    while (!st1.empty()) st1.pop();
                    break;
                }
                st2.top().se -= st1.top().se;
                if (!st2.top().se) st2.pop();
                st1.pop();
            }
        }
        cout << (st1.size() != st2.size() ? -1 : ans) << "\n";
    }
    return 0;
}