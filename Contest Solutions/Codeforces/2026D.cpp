#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

/*
calculate staircase sum(?) as follows:
- psa[i] = a[i] + psa[i - 1]
- spsa[i] = psa[i] + spsa[i - 1]

(corrected post-submission)
to query a staircase sum from l to r starting at k:
- spsa[r] - spsa[l - 1] - psa[k - 1] * (r - l + 1)

(corrected post-submission)
then, for b, we can calculate the bpsa from 1 to n starting at k as follows:
- bpsa[i] = query(i, n, i) + bpsa[i - 1]
*/

int n, a[300001], q;
ll psa[300001], spsa[300001], bpsa[300001], l, r;
map<ll, int> mp;
map<int, ll> mpi;
ll query(int l, int r, int k) {
    return spsa[r] - spsa[l - 1] - psa[k - 1] * (r - l + 1);
}
ll queryB(int l, int r) {
    if (l > r) return 0;
    return bpsa[r] - bpsa[l - 1];
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        psa[i] = a[i] + psa[i - 1];
        spsa[i] = psa[i] + spsa[i - 1];
    }
    for (ll i = 0, j = 0; i < n; i++) {
        j += n - i;
        mp[j] = i + 1;
        mpi[i + 1] = j;
    }
    for (int i = 1; i <= n; i++) bpsa[i] = query(i, n, i) + bpsa[i - 1];
    // cout << bpsa[n] << "bruh\n";
    cin >> q;
    while (q--) {
        cin >> l >> r;
        int lb = mp.lower_bound(l) -> second, rb = mp.lower_bound(r) -> second;
        if (lb == rb) {
            cout << query(lb + l - mpi[lb - 1] - 1, rb + r - mpi[rb - 1] - 1, lb) << "\n";
        }
        else {
            // cout << lb << " " << rb << " here\n";
            // cout << lb + l - mpi[lb - 1] - 1 << " debug\n";
            // cout << rb + r - mpi[rb - 1] - 1 << " bruh\n";

            cout << queryB(lb + 1, rb - 1) + query(rb, rb + r - mpi[rb - 1] - 1, rb) + query(lb + l - mpi[lb - 1] - 1, n, lb) << "\n";
        }
    }
    return 0;
}

/*
4
1 2 5 10
1
6 10

expected: 54 (
got: 10 + 20 + 20 = 50
*/

/*
4
1 2 5 10
15
1 1
1 2
1 3
1 4
1 5
1 10
5 10
6 10
2 8
3 4
3 10
3 8
5 6
5 5
1 8
*/