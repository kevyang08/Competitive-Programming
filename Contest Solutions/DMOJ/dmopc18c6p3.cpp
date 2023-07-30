#include <bits/stdc++.h>
using namespace std;

int id[200001];
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
    int n, m;
    bool thing = false;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) id[i] = -1;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        if (find(a) == find(b)) {
            if (!thing) thing = true;
            else {
                cout << "NO\n";
                return 0;
            }
        }
        else join(a, b);
    }
    cout << "YES\n";
    return 0;
}
