#include <bits/stdc++.h>
using namespace std;

int id[100001];
int find(int x) {
    return id[x] < 0 ? x : (id[x] = find(id[x]));
}
void join(int x, int y) {
    if ((x = find(x)) < (y = find(y))) {
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
    int n, m, k, a, b, c = 0;
    cin >> n >> m >> k;
    string r;
    cin >> r;
    for (int i = 1; i <= 100000; i++) id[i] = -1;
    while (m--) {
        cin >> a >> b;
        if (find(a) != find(b) && r[a - 1] == r[b - 1]) join(a, b);
    }
    while (k--) {
        cin >> a >> b;
        if (find(a) == find(b)) c++;
    }
    cout << c << "\n";
    return 0;
}
