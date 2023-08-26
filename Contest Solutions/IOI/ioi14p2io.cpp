#include <bits/stdc++.h>
using namespace std;

int n, k, op, l, r, v, tp[8000005], lo[8000005], hi[8000005], arr[2000005];
void pushDown(int l, int r, int idx) {
    if (tp[idx]) {
        if (l == r) {
            if (arr[l] < lo[idx] || tp[idx] == 4) arr[l] = lo[idx];
            else if (arr[l] > hi[idx]) arr[l] = hi[idx];
        }
        else {
            if (tp[idx] == 1) {
                if (lo[idx] >= hi[idx << 1]) {
                    lo[idx << 1] = hi[idx << 1] = lo[idx];
                    tp[idx << 1] = 4;
                }
                else lo[idx << 1] = max(lo[idx], lo[idx << 1]);
                if (lo[idx] >= hi[idx << 1 | 1]) {
                    lo[idx << 1 | 1] = hi[idx << 1 | 1] = lo[idx];
                    tp[idx << 1 | 1] = 4;
                }
                else lo[idx << 1 | 1] = max(lo[idx], lo[idx << 1 | 1]);
                if (tp[idx << 1] == 0) tp[idx << 1] = 1;
                else if (tp[idx << 1] == 2) tp[idx << 1] = 3;
                if (tp[idx << 1 | 1] == 0) tp[idx << 1 | 1] = 1;
                else if (tp[idx << 1 | 1] == 2) tp[idx << 1 | 1] = 3;
            }
            else if (tp[idx] == 2) {
                if (hi[idx] <= lo[idx << 1]) {
                    lo[idx << 1] = hi[idx << 1] = hi[idx];
                    tp[idx << 1] = 4;
                }
                else hi[idx << 1] = min(hi[idx], hi[idx << 1]);
                if (hi[idx] <= lo[idx << 1 | 1]) {
                    lo[idx << 1 | 1] = hi[idx << 1 | 1] = hi[idx];
                    tp[idx << 1 | 1] = 4;
                }
                else hi[idx << 1 | 1] = min(hi[idx], hi[idx << 1 | 1]);
                if (tp[idx << 1] == 0) tp[idx << 1] = 2;
                else if (tp[idx << 1] == 1) tp[idx << 1] = 3;
                if (tp[idx << 1 | 1] == 0) tp[idx << 1 | 1] = 2;
                else if (tp[idx << 1 | 1] == 1) tp[idx << 1 | 1] = 3;
            }
            else if (tp[idx] == 3) {
                if (lo[idx << 1] >= hi[idx]) {
                    lo[idx << 1] = hi[idx << 1] = hi[idx];
                    tp[idx << 1] = 4;
                }
                else if (lo[idx] >= hi[idx << 1]) {
                    lo[idx << 1] = hi[idx << 1] = lo[idx];
                    tp[idx << 1] = 4;
                }
                else {
                    lo[idx << 1] = max(lo[idx], lo[idx << 1]);
                    hi[idx << 1] = min(hi[idx], hi[idx << 1]);
                    if (lo[idx << 1] == hi[idx << 1]) tp[idx << 1] = 4;
                }
                if (lo[idx << 1 | 1] >= hi[idx]) {
                    lo[idx << 1 | 1] = hi[idx << 1 | 1] = hi[idx];
                    tp[idx << 1 | 1] = 4;
                }
                else if (lo[idx] >= hi[idx << 1 | 1]) {
                    lo[idx << 1 | 1] = hi[idx << 1 | 1] = lo[idx];
                    tp[idx << 1 | 1] = 4;
                }
                else {
                    lo[idx << 1 | 1] = max(lo[idx], lo[idx << 1 | 1]);
                    hi[idx << 1 | 1] = min(hi[idx], hi[idx << 1 | 1]);
                    if (lo[idx << 1 | 1] == hi[idx << 1 | 1]) tp[idx << 1 | 1] = 4;
                }
                if (tp[idx << 1] != 4) tp[idx << 1] = 3;
                if (tp[idx << 1 | 1] != 4) tp[idx << 1 | 1] = 3;
            }
            else {
                lo[idx << 1] = lo[idx << 1 | 1] = hi[idx << 1] = hi[idx << 1 | 1] = lo[idx];
                tp[idx << 1] = tp[idx << 1 | 1] = 4;
            }
        }
        tp[idx] = lo[idx] = 0; hi[idx] = 0x3f3f3f3f;
    }
}
void update(int l, int r, int ql, int qr, int idx, int v, int op) {
    pushDown(l, r, idx);
    if (l > qr || r < ql) return;
    if (l >= ql && r <= qr) {
        tp[idx] = op;
        if (op == 1) lo[idx] = v;
        else hi[idx] = v;
        return;
    }
    int m = (l + r) >> 1;
    update(l, m, ql, qr, idx << 1, v, op);
    update(m + 1, r, ql, qr, idx << 1 | 1, v, op);
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    memset(hi, 0x3f3f3f3f, sizeof(hi));
    cin >> n >> k;
    while (k--) {
        cin >> op >> l >> r >> v;
        l++; r++;
        update(1, n, l, r, 1, v, op);
    }
    for (int i = 1; i <= n; i++) {
        update(1, n, i, i, 1, 0, 1);
        cout << arr[i] << "\n";
    }
    return 0;
}

/*
1: set lower bound
2: set upper bound
3: set lower and upper bounds
4: set number
*/
