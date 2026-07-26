#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
// const int M = 998244353;
const int M = 1e9 + 7;

/*
- binary search
- iterate through numbers from smallest to largest, keeping track of index
- use fenwick tree to keep track of counts
- keep track of minimum needed for empty carts

post submission notes:
- disregard last point above, misread q
- can precompute over and do O(nlogn) instead of O(nlog^2n)
*/

int n, a[300005], bit[300005], over[300005], thing[300005];
ll k;
vector<pair<int, int>> arr;
void update(int x) {
    for (; x > 0; x -= (x & -x)) ++bit[x];
}
int query(int x) {
    int res = 0;
    for (; x <= n; x += (x & -x)) res += bit[x];
    return res;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        arr.push_back({a[i], i});
    }
    sort(arr.begin(), arr.end());
    for (auto &[aa, bb] : arr) {
        thing[bb] = query(bb);
        update(bb);
    }
    int l = 0, r = n - 1;
    while (l < r) {
        int m = (l + r)/2;
        ll tmpk = k;
        fill(bit, bit + n + 1, 0);
        fill(over, over + n + 1, 0);
        stack<int> st;
        for (auto &[aa, bb] : arr) {
            if (thing[bb] > m) {
                over[bb] = thing[bb] - m;
                while (!st.empty() && a[st.top()] < aa && st.top() >= bb) st.pop();
                if (st.empty() || a[st.top()] != aa) st.push(bb);
            }
        }
        int z = 0;
        for (int i = n; i > 0 && tmpk >= 0; i--) {
            if (z < over[i]) {
                tmpk = -1;
                break;
            }
            if (a[i]) continue;
            if (!st.empty()) {
                tmpk -= a[st.top()];
                ++z;
                while (!st.empty() && z >= over[st.top()]) st.pop();
            }
        }
        if (tmpk >= 0) r = m;
        else l = m + 1;
    }
    cout << l << "\n";
    return 0;
}