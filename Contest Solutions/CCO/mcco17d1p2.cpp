#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 200000;
ll st[4 * MAXN], lazy[4 * MAXN];

ll query(int l, int r, int ql, int qr, int idx) {
  	if (lazy[idx]) {
      	st[idx] += lazy[idx];
      	if (l != r) {
          	lazy[2 * idx] += lazy[idx];
          	lazy[2 * idx + 1] += lazy[idx];
        }
      	lazy[idx] = 0;
    }
  	if (ql <= l && r <= qr) return st[idx];
  	if (ql > r || qr < l) return 0;
  	int m = (l + r)/2;
  	return max(query(l, m, ql, qr, 2 * idx), query(m + 1, r, ql, qr, 2 * idx + 1));
}
void update(int l, int r, int ql, int qr, int idx, int v) {
  	if (lazy[idx]) {
      	st[idx] += lazy[idx];
      	if (l != r) {
          	lazy[2 * idx] += lazy[idx];
          	lazy[2 * idx + 1] += lazy[idx];
        }
      	lazy[idx] = 0;
    }
  	if (ql <= l && r <= qr) {
    	st[idx] += v;
      	if (l != r) {
          	lazy[2 * idx] += v;
          	lazy[2 * idx + 1] += v;
        }
      	return;
    }
  	if (ql > r || qr < l) return;
  	int m = (l + r)/2;
  	update(l, m, ql, qr, 2 * idx, v);
  	update(m + 1, r, ql, qr, 2 * idx + 1, v);
  	st[idx] = max(st[2 * idx], st[2 * idx + 1]);
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n, k, q;
  	cin >> n >> k >> q;
  	while (q--) {
      	int op, a, b;
      	cin >> op >> a >> b;
      	if (op) cout << query(0, n - 1, a, b, 1) << "\n";
      	else update(0, n - 1, max(a - k + 1, 0), a, 1, b);
    }
    return 0;
}
