#include <bits/stdc++.h>
using namespace std;

int n, q, op, a, b, temp, arr[100001], tree[27][100001];
long long query(int op, int l, int r) {
    long long res = 0;
    for (int j = 0; j < 27; j++) {
        long long cnt = 0;
        for (int k = r; k > 0; k -= (k & -k)) cnt += tree[j][k];
        for (int k = l; k > 0; k -= (k & -k)) cnt -= tree[j][k];
        if (cnt == 0) continue;
        if (op == 2) res += (1 << j) * ((long long)(r - l) * (r - l - 1)/2 - (r - l - cnt) * (r - l - cnt - 1)/2);
        else if (op == 3) res += (1 << j) * cnt * (cnt - 1)/2;
        else res += (1 << j) * cnt * (r - l - cnt);
    }
    return res;
}
void update(int i, int x) {
    for (int j = 0; j < 27; j++) {
        if (x & (1 << j)) for (int k = i; k <= n; k += (k & -k)) tree[j][k]++;
        if (arr[i] & (1 << j)) for (int k = i; k <= n; k += (k & -k)) tree[j][k]--;
    }
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        update(i, temp);
        arr[i] = temp;
    }
    while (q--) {
        cin >> op >> a >> b;
        if (op == 1) {
            update(a, b);
            arr[a] = b;
        }
        else cout << query(op, --a, b) << "\n";
    }
    return 0;
}
