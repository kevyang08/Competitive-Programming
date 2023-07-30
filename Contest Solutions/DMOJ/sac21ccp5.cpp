#include <bits/stdc++.h>
using namespace std;

int id[100001];
int find(int x) {
    return id[x] < 0 ? x : (id[x] = find(id[x]));
}
void join(int x, int y) {
    if (id[x = find(x)] < id[y = find(y)]) {
        id[x] += id[y];
        id[y] = x;
    }
    else {
        id[y] += id[x];
        id[x] = y;
    }
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) id[i] = -1;
    while (q--) {
        int op, a, b;
        cin >> op >> a;
        if (op == 1) {cin >> b; if (find(a) != find(b)) join(a, b);}
        else cout << -id[find(a)] << "\n";
    }
    return 0;
}
