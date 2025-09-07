#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
// const int M = 998244353
const int M = 1e9 + 7;

int n, ans = 0;
char s[200001], t[200001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> s >> t;
    deque<char> dq;
    multiset<char> ms;
    for (int i = 0; i < n; i++) dq.push_back(s[i]);
    for (int i = n - 1; i >= 0; i--) {
        if (dq.size() + ms.size() == i + 1 && dq.back() == t[i]) {
            dq.pop_back();
            continue;
        }
        while (ms.empty() || ms.find(t[i]) == ms.end()) {
            if (dq.empty()) {
                cout << "-1\n";
                return 0;
            }
            ms.insert(dq.front());
            dq.pop_front();
            ++ans;
        }
        ms.extract(t[i]);
    }
    cout << ans << "\n";
    return 0;
}