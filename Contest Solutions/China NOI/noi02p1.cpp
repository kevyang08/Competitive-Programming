#include <bits/stdc++.h>
using namespace std;

int t, a, b, id[30001], pos[30001], sz[30001];
char op;
int find(int x) {
    if (id[x] < 0) return x;
    int temp = find(id[x]);
    if (temp != id[x]) pos[x] += pos[id[x]] - 1;
    return (id[x] = temp);
}
void join(int i, int j) {
    i = find(i); j = find(j);
    pos[i] = sz[j] + 1;
    sz[j] += sz[i];
    id[i] = j;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    fill(id, id + 30001, -1);
    fill(pos, pos + 30001, 1);
    fill(sz, sz + 30001, 1);
    cin >> t;
    while (t--) {
        cin >> op >> a >> b;
        if (op == 'M') join(a, b);
        else cout << (find(a) == find(b) ? abs(pos[a] - pos[b]) - 1 : -1) << "\n";
    }
    return 0;
}
