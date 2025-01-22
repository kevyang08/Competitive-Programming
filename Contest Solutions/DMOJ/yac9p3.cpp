#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int n, a, mx[1000005];
ll ans = 0;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    for (int i = 2; i <= 1000000; i++) {
        if (mx[i]) continue;
        for (int j = i; j <= 1000000; j += i) mx[i] = i;
    }
    cin >> n;
    stack<int> st;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        if (a == 1) st.push(i);
        else {
            while (!st.empty() && i - st.top() + 1 < mx[a]) st.pop();
        }
        ans += st.size();
    }
    cout << ans << "\n";
    return 0;
}