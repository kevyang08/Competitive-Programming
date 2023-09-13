#include <bits/stdc++.h>
using namespace std;

int n, a, pos[100001], bit[100001];
void update(int i, int v) {
    for (; i > 0; i -= (i & -i)) bit[i] += v;
}
int query(int i) {
    int res = 0;
    for (; i <= n; i += (i & -i)) res += bit[i];
    return res;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        pos[a] = i;
    }
    for (int i = 1, j = 1, k = n; i <= n; i++) {
        if (i%2) {
            cout << pos[j] + query(pos[j]) - j << "\n";
            update(pos[j++], 1);
        }
        else {
            cout << k - pos[k] - query(pos[k]) << "\n";
            update(n, -1);
            update(pos[k--] - 1, 1);
        }
    }
    return 0;
}
