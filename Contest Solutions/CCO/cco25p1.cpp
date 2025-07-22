#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int n, idx = 0;
ll m, ans = 0;
vector<ll> v, ma, cnt, vm;
priority_queue<ll> pq[64];
set<ll> st;
map<ll, int> mp;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> m;
    v.resize(n);
    ma.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i] >> ma[i];
        st.insert(ma[i]);
    }
    while (!st.empty()) {
        ll c = *st.rbegin(); st.erase(c);
        mp[c] = idx++;
        cnt.push_back(m/c);
        m -= m/c * c;
        vm.push_back(c);
    }
    for (int i = 0; i < n; i++) pq[mp[ma[i]]].push(v[i]);
    for (int i = idx - 1; i >= 0; i--) {
        while (cnt[i] && !pq[i].empty()) {
            --cnt[i];
            ans += pq[i].top(); pq[i].pop();
        }
        if (pq[i].empty() || !i) continue;
        int j = 0;
        ll cur = 0;
        while (!pq[i].empty()) {
            ++j;
            cur += pq[i].top(); pq[i].pop();
            if (j == vm[i - 1]/vm[i]) {
                pq[i - 1].push(cur);
                j = 0, cur = 0;
            }
        }
        if (j) pq[i - 1].push(cur);
    }
    cout << ans << "\n";
    return 0;
}