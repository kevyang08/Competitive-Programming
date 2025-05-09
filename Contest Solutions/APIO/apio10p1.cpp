#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

/*
wtf was i doing
*/

int n, a, b, c; 
ll x[1000005], dp[1000005];
deque<int> dq;
double intersect(int i, int j) {
    ll mi = -2 * a * x[i], mj = -2 * a * x[j];
    ll bi = a * x[i] * x[i] - b * x[i] + dp[i], bj = a * x[j] * x[j] - b * x[j] + dp[j];
    return (double)(bi - bj)/(mj - mi);
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> a >> b >> c;
    dq.push_back(0);
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        x[i] += x[i - 1];
        while (dq.size() > 1 && intersect(dq[0], dq[1]) <= x[i]) dq.pop_front();
        ll tmp = x[i] - x[dq.front()];
        dp[i] = a * tmp * tmp + b * tmp + c + dp[dq.front()];
        while (dq.size() > 1 && intersect(dq.back(), i) <= intersect(dq[dq.size() - 2], i)) dq.pop_back();
        dq.push_back(i);
    }
    cout << dp[n] << "\n";
    return 0;
}