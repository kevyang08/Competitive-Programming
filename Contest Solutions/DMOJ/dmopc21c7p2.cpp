#include <bits/stdc++.h>
using namespace std;

int n, q, l, r, k, prv[1000001], nxt[1000001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> q;
    nxt[n] = -1;
    for (int i = 1; i <= n; i++) {
        prv[i] = i - 1;
        nxt[i - 1] = i;
    }
    while (q--) {
        cin >> l >> r >> k;
        if (prv[l] == k) continue;
        nxt[prv[l]] = nxt[r];
        prv[nxt[r]] = prv[l];
        prv[l] = k;
        nxt[r] = nxt[k];
        if (nxt[k] != -1) prv[nxt[k]] = r;
        nxt[k] = l;
    }
    int i = nxt[0];
    while (i != -1) {
        cout << i << (nxt[i] == -1 ? "\n" : " ");
        i = nxt[i];
    }
    return 0;
}
