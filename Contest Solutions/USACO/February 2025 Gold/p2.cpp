#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

/*
woops length has to be exactly k

if (cnt >= k) do 1 k times
else if (cnt + suf >= k) do 1 cnt times + 0 min(k, suf) times
else:
    - let cnt(l,r) be the number of 1s from l to r
    - binary search for largest idx s.t. cnt(l,idx) + r - idx >= k
        - m = (lo + hi + 1)/2
        - if >= k: lo = m
        - else: hi = m - 1

- we will also store the number represented by the binary string in each section for faster queries

with good implementation, can combine all 3 cases

time complexity: should be O(mlogn + qlog^2n)

nvm acc have to optimize to logn

nvm stupid constant optimization problem
*/

const int M = 1e9 + 7;

ll bpow(ll n, int p) {
    ll res = 1;
    while (p > 0) {
        if ((p & 1) == 1) {
            res *= n;
            res %= M;
        }
        n *= n;
        n %= M;
        p >>= 1;
    }
    return res;
}

int n, m, q, l, r, k;
map<int, int> mp;
gp_hash_table<int, int> cnt, np;
vector<int> vv;
gp_hash_table<int, ll> pt;
int queryC(int i) {
    int idx = *(--upper_bound(vv.begin(), vv.end(), i));
    return cnt[idx] + np[idx] * (i - idx); 
}
ll queryV(int i) {
    int idx = *(--upper_bound(vv.begin(), vv.end(), i));
    return ((pt[idx] + np[idx]) * bpow(2, i - idx) - np[idx] + M)%M;
}
ll queryV(int l, int r) {
    ll rl = queryV(l - 1), rr = queryV(r);
    return (rr - (rl * bpow(2, r - l + 1))%M + M)%M;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> m >> q;
    while (m--) {
        cin >> l >> r;
        ++mp[l]; --mp[r + 1];
    }
    if (mp.find(1) == mp.end()) mp[1] = 0;
    if (mp.find(n + 1) == mp.end()) mp[n + 1] = 0;
    int prv = 0, tmp = 0, c = 0;
    ll cur = 0;
    for (auto &[i, v] : mp) {
        c += (tmp%2 ? i - prv : 0);
        cur = ((cur + tmp%2) * bpow(2, i - prv) - tmp%2 + M)%M;
        cnt[i - 1] = c;
        pt[i - 1] = cur;
        tmp += v;
        np[i - 1] = tmp%2;
        prv = i;
        vv.push_back(i - 1);
    }
    while (q--) {
        cin >> l >> r >> k;
        int lo = l - 1, hi = r, ones = 0, cl = queryC(l - 1);
        while (lo < hi) {
            int m = (lo + hi + 1)/2, cm = queryC(m);
            if (cm - cl + r - m < k) hi = m - 1;
            else lo = m, ones = cm - cl;
        }
        if (ones >= k) cout << (bpow(2, k) - 1 + M)%M << "\n";
        else cout << (bpow(2, k) - bpow(2, k - ones) + M + queryV(lo + 1, lo + k - ones))%M << "\n";
    }
    return 0;
}

/*
5 1 1
1 5
1 5 4

*/